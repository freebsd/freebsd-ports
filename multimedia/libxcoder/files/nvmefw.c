/*
 * nvmefw: NETINT Quadra firmware upgrade tool for FreeBSD.
 *
 * Reproduces what NETINT's quadra_auto_upgrade.sh does with nvme-cli on Linux
 * (measured with strace/ftrace, see netint_quadra.md section 6):
 *
 *   1. controller reset                               nvme reset
 *   2. Firmware Image Download (admin 0x11), 4096 bytes per command,
 *      cdw10 = dwords - 1, cdw11 = byte offset / 4    nvme fw-download -x 4096
 *   3. vendor admin command 0xC7, no data: burn the image from the card's
 *      DDR into its NOR flash (about a minute)        nvme admin-passthru --opcode 0xc7
 *   4. the new firmware is active after a power cycle (cold upgrade).
 *
 * It uses the NATIVE nvme(4) ioctl NVME_PASSTHROUGH_CMD, not the Linux-compatible
 * one: the Linux-compatible ioctl never reports the NVMe completion status
 * (nvme_npc_done() only stores cdw0), so a failed command would look like
 * success. The native ioctl returns the whole completion entry.
 *
 * Build: cc -O1 -Wall -o nvmefw nvmefw.c
 *
 *   nvmefw info  /dev/nvme1                  identify (model, serial, firmware revision)
 *   nvmefw check /dev/nvme1 IMAGE.bin        validate the image, compare revisions
 *   nvmefw plan  /dev/nvme1 IMAGE.bin        print every command that flash would send
 *   nvmefw flash /dev/nvme1 IMAGE.bin --yes  reset, download, burn   (WRITES THE CARD'S FLASH)
 *
 * Use quadra_fw_upgrade.sh (same directory) for the safe wrapper: it checks that
 * no session is running and raises nvme(4)'s admin timeout around the burn.
 */
#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/endian.h>
#include <sys/stat.h>
#include <dev/nvme/nvme.h>

#include <err.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define CHUNK		4096u
#define OPC_IDENTIFY	0x06
#define OPC_FW_DOWNLOAD	0x11
#define OPC_VENDOR_BURN	0xC7
/* Layout of NETINT's nor_flash_*.bin, from quadra_auto_upgrade.sh */
#define IMG_REV_OFFSET	1048580u
#define IMG_REV_LEN	8u
#define IMG_MIN_SIZE	1048704u

static int
pt(int fd, struct nvme_pt_command *p)
{
	if (ioctl(fd, NVME_PASSTHROUGH_CMD, p) < 0)
		err(1, "ioctl NVME_PASSTHROUGH_CMD opc 0x%02x", p->cmd.opc);
	/* returns the NVMe status: 0 = success */
	return (NVME_STATUS_GET_SCT(p->cpl.status) << 8) | NVME_STATUS_GET_SC(p->cpl.status);
}

static void
identify(int fd, uint8_t *buf4k)
{
	struct nvme_pt_command p;
	int st;

	memset(&p, 0, sizeof(p));
	p.cmd.opc = OPC_IDENTIFY;
	p.cmd.cdw10 = htole32(1);	/* CNS 1: controller */
	p.buf = buf4k;
	p.len = CHUNK;
	p.is_read = 1;
	st = pt(fd, &p);
	if (st != 0)
		errx(1, "identify failed, status 0x%x", st);
}

static void *
aligned(size_t n)
{
	void *b;

	if (posix_memalign(&b, CHUNK, n) != 0)
		err(1, "posix_memalign");
	memset(b, 0, n);
	return (b);
}

static int
cmd_info(const char *dev)
{
	uint8_t *id = aligned(CHUNK);
	int fd = open(dev, O_RDWR);

	if (fd < 0)
		err(1, "open %s", dev);
	identify(fd, id);
	printf("VID      0x%04x\nSN       %.20s\nMN       %.40s\nFR       %.8s\nOACS     0x%x\nFRMW     0x%x\n",
	    id[0] | id[1] << 8, (char *)id + 4, (char *)id + 24, (char *)id + 64,
	    id[256] | id[257] << 8, id[260]);
	close(fd);
	return (0);
}

struct image {
	uint8_t *data;
	size_t size;
	char rev[IMG_REV_LEN + 1];
};

static void
load_image(const char *path, struct image *im)
{
	struct stat sb;
	int fd = open(path, O_RDONLY);
	size_t got = 0;

	if (fd < 0)
		err(1, "open %s", path);
	if (fstat(fd, &sb) < 0)
		err(1, "fstat");
	im->size = (size_t)sb.st_size;
	if (im->size < IMG_MIN_SIZE)
		errx(1, "%s: %zu bytes is smaller than the minimum %u, file looks corrupt",
		    path, im->size, IMG_MIN_SIZE);
	if (im->size % 4 != 0)
		errx(1, "%s: size %zu is not a multiple of 4 (NVMe works in dwords)", path, im->size);
	im->data = malloc(im->size);
	if (im->data == NULL)
		err(1, "malloc");
	while (got < im->size) {
		ssize_t n = read(fd, im->data + got, im->size - got);
		if (n <= 0)
			err(1, "read");
		got += (size_t)n;
	}
	close(fd);
	memcpy(im->rev, im->data + IMG_REV_OFFSET, IMG_REV_LEN);
	im->rev[IMG_REV_LEN] = '\0';
}

static int
cmd_check(const char *dev, const char *path)
{
	struct image im;
	uint8_t *id = aligned(CHUNK);
	int fd = open(dev, O_RDWR), i;
	char cardrev[9];

	if (fd < 0)
		err(1, "open %s", dev);
	load_image(path, &im);
	identify(fd, id);
	memcpy(cardrev, id + 64, 8);
	cardrev[8] = '\0';
	for (i = 0; i < IMG_REV_LEN; i++)
		if (im.rev[i] < 0x20 || im.rev[i] > 0x7e)
			errx(1, "image revision field is not printable text: not a Quadra image?");
	printf("image   %s\n        %zu bytes, %zu download commands of %u bytes, revision \"%s\"\n",
	    path, im.size, (im.size + CHUNK - 1) / CHUNK, CHUNK, im.rev);
	printf("card    %.40s serial %.20s, firmware \"%s\"\n", (char *)id + 24, (char *)id + 4, cardrev);
	printf("verdict %s\n", strcmp(im.rev, cardrev) == 0 ?
	    "same revision as the card (re-flash, safe test)" : "DIFFERENT revision (a real upgrade or downgrade)");
	close(fd);
	return (0);
}

static void
chunk_cmd(const struct image *im, size_t off, uint32_t *cdw10, uint32_t *cdw11, size_t *len)
{
	*len = im->size - off < CHUNK ? im->size - off : CHUNK;
	*cdw10 = (uint32_t)(*len / 4 - 1);	/* NUMD, 0-based dword count */
	*cdw11 = (uint32_t)(off / 4);		/* OFST, in dwords */
}

static int
cmd_plan(const char *path)
{
	struct image im;
	size_t off, len, n = 0;
	uint32_t c10, c11;

	load_image(path, &im);
	for (off = 0; off < im.size; off += CHUNK) {
		chunk_cmd(&im, off, &c10, &c11, &len);
		printf("%zu download_fw cdw10=0x%x cdw11=0x%x len=%zu\n", n++, c10, c11, len);
	}
	printf("%zu burn opc=0x%02x cdw10..15=0 no data\n", n, OPC_VENDOR_BURN);
	return (0);
}

static int
cmd_flash(const char *dev, const char *path)
{
	struct image im;
	struct nvme_pt_command p;
	uint8_t *id = aligned(CHUNK), *buf = aligned(CHUNK);
	size_t off, len, n = 0;
	uint32_t c10, c11;
	int fd, st, i;
	time_t t0;

	load_image(path, &im);
	fd = open(dev, O_RDWR);
	if (fd < 0)
		err(1, "open %s", dev);
	identify(fd, id);
	printf("card %.40s, firmware \"%.8s\"; image revision \"%s\", %zu bytes\n",
	    (char *)id + 24, (char *)id + 64, im.rev, im.size);

	/* 1. controller reset, then wait until the controller answers again */
	printf("1/3 controller reset ... ");
	fflush(stdout);
	if (ioctl(fd, NVME_RESET_CONTROLLER) < 0)
		err(1, "NVME_RESET_CONTROLLER");
	for (i = 0; i < 60; i++) {
		struct nvme_pt_command q;

		sleep(1);
		memset(&q, 0, sizeof(q));
		q.cmd.opc = OPC_IDENTIFY;
		q.cmd.cdw10 = htole32(1);
		q.buf = id;
		q.len = CHUNK;
		q.is_read = 1;
		if (ioctl(fd, NVME_PASSTHROUGH_CMD, &q) == 0 &&
		    NVME_STATUS_GET_SC(q.cpl.status) == 0 && NVME_STATUS_GET_SCT(q.cpl.status) == 0)
			break;
	}
	if (i == 60)
		errx(1, "controller did not come back after reset");
	printf("ok after %d s\n", i + 1);

	/* 2. download the image into the card's DDR */
	printf("2/3 download %zu chunks ... ", (im.size + CHUNK - 1) / CHUNK);
	fflush(stdout);
	for (off = 0; off < im.size; off += CHUNK, n++) {
		chunk_cmd(&im, off, &c10, &c11, &len);
		memset(buf, 0, CHUNK);
		memcpy(buf, im.data + off, len);
		memset(&p, 0, sizeof(p));
		p.cmd.opc = OPC_FW_DOWNLOAD;
		p.cmd.cdw10 = htole32(c10);
		p.cmd.cdw11 = htole32(c11);
		p.buf = buf;
		p.len = (uint32_t)len;
		p.is_read = 0;			/* host to controller */
		st = pt(fd, &p);
		if (st != 0) {
			printf("\n");
			errx(1, "download chunk %zu (offset %zu) failed, status 0x%x: NOT burning", n, off, st);
		}
	}
	printf("ok\n");

	/* 3. burn DDR image into NOR flash (long: the admin timeout must be raised) */
	printf("3/3 burn to NOR flash (about a minute, do NOT interrupt) ... ");
	fflush(stdout);
	t0 = time(NULL);
	memset(&p, 0, sizeof(p));
	p.cmd.opc = OPC_VENDOR_BURN;
	st = pt(fd, &p);
	if (st != 0) {
		printf("\n");
		errx(1, "burn failed after %ld s, status 0x%x (the previous firmware stays in effect)",
		    (long)(time(NULL) - t0), st);
	}
	printf("ok after %ld s\n", (long)(time(NULL) - t0));
	printf("done: power-cycle the host (cold upgrade) to run the new firmware, then run: nvmefw info %s\n", dev);
	close(fd);
	return (0);
}

static void
usage(void)
{
	fprintf(stderr,
	    "usage: nvmefw info  DEV\n"
	    "       nvmefw check DEV IMAGE\n"
	    "       nvmefw plan  DEV IMAGE\n"
	    "       nvmefw flash DEV IMAGE --yes     (writes the card's flash)\n");
	exit(2);
}

int
main(int argc, char **argv)
{
	if (argc >= 3 && strcmp(argv[1], "info") == 0)
		return (cmd_info(argv[2]));
	if (argc >= 4 && strcmp(argv[1], "check") == 0)
		return (cmd_check(argv[2], argv[3]));
	if (argc >= 4 && strcmp(argv[1], "plan") == 0)
		return (cmd_plan(argv[3]));
	if (argc >= 5 && strcmp(argv[1], "flash") == 0 && strcmp(argv[4], "--yes") == 0)
		return (cmd_flash(argv[2], argv[3]));
	usage();
	return (2);
}

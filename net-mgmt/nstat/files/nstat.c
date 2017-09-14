/*-
 * Copyright (c) 2017
 *      Netflix Inc.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *
 */


#include <sys/types.h>
#include <sys/socket.h>
#include <sys/sysctl.h>
#include <sys/time.h>

#include <err.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sysexits.h>
#include <unistd.h>

#include <net/if.h>
#include <net/if_types.h>
#include <net/if_mib.h>

#include <netinet/tcp_fsm.h>

#include <sys/resource.h>
#include <sys/ttycom.h>
#include <sys/vmmeter.h>


/* why is this only defined in the kernel */
#define	timespecadd(vvp, uvp)						\
	do {								\
		(vvp)->tv_sec += (uvp)->tv_sec;				\
		(vvp)->tv_nsec += (uvp)->tv_nsec;			\
		if ((vvp)->tv_nsec >= 1000000000) {			\
			(vvp)->tv_sec++;				\
			(vvp)->tv_nsec -= 1000000000;			\
		}							\
	} while (0)


#define SWAP_CPU() { cpu_tmp = cpu; cpu = cpu_prev; cpu_prev = cpu_tmp; }
double
get_cpu(void)
{
	static long cpu_time[CPUSTATES];
	static long cpu_time_too[CPUSTATES];
	static long *cpu = cpu_time, *cpu_prev = cpu_time_too, *cpu_tmp;
	long busy, idle;
	size_t len;
	int i, status;

	SWAP_CPU();
	len = sizeof(cpu_time);
	status = sysctlbyname("kern.cp_time", cpu, &len, NULL, 0);
	if (status) {
		err(EX_OSERR, "Cant get CPU time");
	}
	for (busy = 0, i = 0; i < CPUSTATES; i++) {
		if (i != CP_IDLE)
			busy += cpu[i] - cpu_prev[i];
	}
	idle = cpu[CP_IDLE] - cpu_prev[CP_IDLE];

	return ((double)busy / (double)(busy + idle) * 100.0);
}

#define SWAP_VM() { vmm_tmp = vmm; vmm = vmm_prev; vmm_prev = vmm_tmp; }
struct my_vmmeter {
	uint64_t v_syscall;
	uint64_t v_swtch;
	uint64_t v_intr;
	uint64_t v_free_count;
};

void
get_vmm(u_int *syscall, u_int *csw, u_int *irq, double *free)
{
	static struct my_vmmeter vmm_arr[2];
	static struct my_vmmeter *vmm = &vmm_arr[0], *vmm_prev = &vmm_arr[1],
	    *vmm_tmp;
	size_t len;
	int status;

	SWAP_VM();
	len = sizeof(vmm->v_syscall);
	status = sysctlbyname("vm.stats.sys.v_syscall",
	    &vmm->v_syscall, &len, NULL, 0);
	status |= sysctlbyname("vm.stats.sys.v_swtch",
	    &vmm->v_swtch, &len, NULL, 0);
	status |= sysctlbyname("vm.stats.sys.v_intr",
	    &vmm->v_intr, &len, NULL, 0);
	status |= sysctlbyname("vm.stats.vm.v_free_count",
	    &vmm->v_free_count, &len, NULL, 0);
	if (status) {
		err(EX_OSERR, "Cant get CPU time");
	}
	*syscall = vmm->v_syscall - vmm_prev->v_syscall;
	*csw = vmm->v_swtch - vmm_prev->v_swtch;
	*irq = vmm->v_intr - vmm_prev->v_intr;
	*free = ((double)vmm->v_free_count * 4096.0) /
	    (1024.0 * 1024.0 * 1024.0);

}

static int
find_if(char *wanted)
{
	size_t len;
	int if_maxidx, i;
	int name[6];
	char ifn[128];

	name[0] = CTL_NET;
	name[1] = PF_LINK;
	name[2] = NETLINK_GENERIC;
	name[3] = IFMIB_SYSTEM;
	name[4] = IFMIB_IFCOUNT;

	len = sizeof(if_maxidx);
	if (sysctl(name, 5, &if_maxidx, &len, 0, 0) < 0)
		err(EX_OSERR, "can't get ifcnt");


	for (i = 0; i <= if_maxidx; i++) {
		name[3] = IFMIB_IFDATA;
		name[4] = i;
		name[5] = IFDATA_DRIVERNAME;
		len = sizeof(ifn);
		if (sysctl(name, 6, ifn, &len, 0, 0) < 0) {
			if (errno == ENOENT)
				continue;
			err(EX_OSERR, "can't get ifname");
		}
		if (0 == strncmp(wanted, ifn, len))
			return (i);
	}
	printf("Could not find %s\n", wanted);
	exit(ENOENT);
}

static void
get_nic_stats(int if_idx, struct ifmibdata *ifm)
{
	size_t len;
	int name[6];

	name[0] = CTL_NET;
	name[1] = PF_LINK;
	name[2] = NETLINK_GENERIC;
	name[3] = IFMIB_IFDATA;
	name[4] = if_idx;
	name[5] = IFDATA_GENERAL;
	len = sizeof(*ifm);
	if (sysctl(name, 6, ifm, &len, 0, 0) < 0)
		err(EX_OSERR, "could not get nic stats");
}

static char *
find_ifname(void)
{
	static char ifbuf[80];
	FILE *pipe;
	char *p;


	pipe = popen("netstat -4rn | grep default", "r");
	if (pipe == NULL)
		err(EX_OSERR, "could not run netsat");
	(void)fread(ifbuf, sizeof(ifbuf) - 1, 1, pipe);
	pclose(pipe);
	p = &ifbuf[sizeof(ifbuf) - 1];
	while (*p != ' ') {
		if (*p == '\n')
			*p = '\0';
		p--;
		if (p == ifbuf)
			err(EX_DATAERR, "can't read def rt");
	}
	/* we are point to a space, point to 1st ifname char */
	return (p + 1);
}

static int
find_rows(void)
{
	struct winsize sz;
	int rows;

	rows = 24;
	if (isatty(STDOUT_FILENO)) {
		if (0 == ioctl(STDOUT_FILENO, TIOCGWINSZ, &sz))
			rows = sz.ws_row;
	}
	return (rows);
}

static void
get_pcm_mem(double interval, double *r, double *w, double *rw)
{
	static FILE * pipe = NULL;
	static int pipe_fd;
	char *open_str;
	char buf[256];
	char *p;
	int sem_cnt, ret_found;
	ssize_t bytes;

	if (pipe == NULL) {
		open_str = alloca(80);
		snprintf(open_str, 80,
		    "pcm-memory.x -csv %f  2>/dev/null", interval * 0.99);
		pipe = popen(open_str, "r");
		if (pipe == NULL)
			err(EX_OSERR, "pipe");
		/* read one-time CSV hdrs */
		(void)fread(buf, sizeof(buf) - 1, 1, pipe);
		pipe_fd = fileno(pipe);
		fcntl(pipe_fd, F_SETFL, O_NONBLOCK);
	}
	bzero(buf, sizeof(buf));
	bytes = read(pipe_fd, buf, sizeof(buf));
	if (bytes == 0)
		err(EX_OSERR,
		    "pcm-memory.x exited - kldload cpuctl?");

	if (bytes == -1) {
		if (errno == EAGAIN)
			return;
		err(EX_OSERR, "read from pcm-memory.x failed");
	}

	p = &buf[bytes];
	/*
	 * the CSV is formatted as: ...; ....;  readbw; writebw;  rwbw\n
	 *
	 * So we start at the end of the buffer, and look backwards for a
	 * return.  Once found, we then count back 3 semi-colons, and then
	 * pass it to sscanf
	 */

	ret_found = 0;
	sem_cnt = 0;
	while (p != buf && sem_cnt < 3) {
		p--;
		if (!ret_found && *p != '\n')
			continue;
		ret_found = 1;
		if (*p == ';')
			sem_cnt++;
	}
	if (sem_cnt == 3) {
		p++;
		sscanf(p, "%lf; %lf; %lf", r, w, rw);
	}
}

long
get_tcp_est()
{
	uint64_t tcps[TCP_NSTATES];
	size_t len = sizeof(tcps);
	int status;

	status = sysctlbyname("net.inet.tcp.states", tcps, &len, NULL, 0);
	if (status != 0)
		err(EX_OSERR, "could not fetch tcp states");

	return ((long)tcps[TCPS_ESTABLISHED]);
}

#define SWAP_IFM() { ifm_tmp = ifm; ifm = ifm_prev; ifm_prev = ifm_tmp; }


static void
print_hdr(int do_pcm_mem)
{
	printf("  InMpps OMpps  InGbs  OGbs err TCP Est %%CPU syscalls csw     irq GBfree");
	if (do_pcm_mem)
		printf("   MemRd     MemWr    MemRW");
	printf("\n");

}

static void
usage(char *name)
{
	fprintf(stderr,
	    "usage: %s [-m] [-I interface] [wait]\n", name);
	exit(1);
}

int
main(int argc, char **argv)
{
	struct ifmibdata ifmd[2];
	struct ifmibdata *ifm, *ifm_prev, *ifm_tmp;
	char *ifname = NULL;
	int c, if_idx;
	double o_gbps, i_gbps, o_mpps, i_mpps;
	long errs, est;
	double interval = 1.0;
	int rows = find_rows() - 1;
	int row = 0;
	int do_pcm_mem = 0;
	u_int syscalls, csw, irq;
	double free_mem;
	double mem_rd = 0.0, mem_wr = 0.0, mem_rw = 0.0;
	struct timespec interval_ts, deadline_ts;


	while ((c = getopt(argc, argv, "mI:")) != -1) {
		switch (c) {
		case 'm':
			do_pcm_mem = 1;
			break;
		case 'I':
			ifname = optarg;
			break;
		default:
			usage(argv[0]);
		}
	}
	argc -= optind;
	argv += optind;

	if (*argv)
		interval = atof(*argv);

	interval_ts.tv_sec = (time_t)interval;
	interval_ts.tv_nsec = (interval - (time_t)interval) * 1000000000;

	if (ifname == NULL)
		ifname = find_ifname();

	if_idx = find_if(ifname);
	ifm = &ifmd[0];
	ifm_prev = &ifmd[1];

	/*
	 * preload all the counters so 1st interval looks reasonable
	 */

	if (do_pcm_mem)
		get_pcm_mem(interval, &mem_rd, &mem_wr, &mem_rw);
	get_nic_stats(if_idx, ifm);
	est = get_tcp_est();
	get_vmm(&syscalls, &csw, &irq, &free_mem);
	(void)get_cpu();
	usleep(interval * 1000 * 1000);
	clock_gettime(CLOCK_UPTIME, &deadline_ts);
	while (1) {
		if (row == 0)
			print_hdr(do_pcm_mem);
		SWAP_IFM();
		get_nic_stats(if_idx, ifm);
		i_gbps = ifm->ifmd_data.ifi_ibytes -
		    ifm_prev->ifmd_data.ifi_ibytes;
		i_gbps = (8.0 * i_gbps) / (1000.0 * 1000.0 * 1000.0 * interval);
		o_gbps = ifm->ifmd_data.ifi_obytes -
		    ifm_prev->ifmd_data.ifi_obytes;
		o_gbps = (8.0 * o_gbps) / (1000.0 * 1000.0 * 1000.0 * interval);
		i_mpps = ifm->ifmd_data.ifi_ipackets -
		    ifm_prev->ifmd_data.ifi_ipackets;
		i_mpps = i_mpps / (1000 * 1000 * interval);
		o_mpps = ifm->ifmd_data.ifi_opackets -
		    ifm_prev->ifmd_data.ifi_opackets;
		o_mpps = o_mpps / (1000 * 1000 * interval);

		/* all errs .. should be rare, don't clutter output */
		errs = ifm->ifmd_data.ifi_oerrors -
		    ifm_prev->ifmd_data.ifi_oerrors;
		errs += ifm->ifmd_data.ifi_ierrors -
		    ifm_prev->ifmd_data.ifi_ierrors;
		errs += ifm->ifmd_data.ifi_oqdrops -
		    ifm_prev->ifmd_data.ifi_oqdrops;
		errs += ifm->ifmd_data.ifi_iqdrops -
		    ifm_prev->ifmd_data.ifi_iqdrops;

		est = get_tcp_est();
		get_vmm(&syscalls, &csw, &irq, &free_mem);
		printf("%6.2lf %6.2lf %6.2lf %6.2lf %2ld %6ld   %4.2lf %6.0f %6.0f %6.0f %5.2lf",
		    i_mpps, o_mpps, i_gbps, o_gbps, errs, est, get_cpu(),
		    syscalls / interval, csw / interval, irq / interval,
		    free_mem);

		if (do_pcm_mem) {
			get_pcm_mem(interval, &mem_rd, &mem_wr, &mem_rw);
			printf("  %8.2f  %8.2f %8.2f", mem_rd, mem_wr, mem_rw);
		}
		printf("\n");
		if (++row == rows)
			row = 0;

		timespecadd(&deadline_ts, &interval_ts);
		clock_nanosleep(CLOCK_UPTIME, TIMER_ABSTIME, &deadline_ts, NULL);
	}
}

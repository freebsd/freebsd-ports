#include <sys/param.h>
#include <sys/disklabel.h>
#if __FreeBSD_version < 500000
#include <sys/diskslice.h>
#else
#include <sys/disk.h>
#include <errno.h>
#endif
#include <stddef.h>
#include "common.h"

unsigned int
sys_bsd_sectorsize(int fd)
{
#ifdef DIOCGSECTORSIZE
	unsigned int d;
	if (ioctl(fd, DIOCGSECTORSIZE, &d) == 0)
		return d;
#else
	struct disklabel dl;
	if (ioctl(fd, DIOCGDINFO, &dl) == 0)
		return dl.d_secsize;
#endif
	return 0;
}

int
sys_bsd_getsectors(int fd, unsigned long *s)
{
	/* XXX */
#if defined(DIOCGMEDIASIZE) && defined(DIOCGSECTORSIZE)
	off_t fullsize;
	unsigned sectsize;
	if (ioctl(fd, DIOCGMEDIASIZE, &fullsize) ||
	    ioctl(fd, DIOCGSECTORSIZE, &sectsize))
		return -1;
	*s = fullsize / sectsize;
	return 0;
#else
	struct disklabel dl;
	if (ioctl(fd, DIOCGDINFO, &dl) < 0)
		return -1;
	*s = (unsigned long) dl.d_ncylinders *
		(unsigned long) dl.d_ntracks *
		(unsigned long) dl.d_nsectors;
	return 0;
#endif
}

int
sys_bsd_ptsync(int fd)
{
#ifdef DIOCSYNCSLICEINFO
	return ioctl(fd, DIOCSYNCSLICEINFO, NULL);
#else
	errno = EINVAL;
	return -1;
#endif
}

int
sys_bsd_getgeometry(int fd, struct hd_geometry *g)
{
	/* XXX */
	struct disklabel dl;
	if (ioctl(fd, DIOCGDINFO, &dl) < 0)
		return -1;
	g->cylinders = dl.d_ncylinders;
	g->heads = dl.d_ntracks;
	g->sectors = dl.d_nsectors;
	return 0;
}

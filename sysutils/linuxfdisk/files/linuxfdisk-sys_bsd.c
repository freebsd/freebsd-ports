#include <sys/param.h>
#include <sys/disklabel.h>
#if __FreeBSD_version < 500000
#include <sys/diskslice.h>
#include <sys/stat.h>
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
	;{
		unsigned int d;
		if (ioctl(fd, DIOCGSECTORSIZE, &d) == 0)
			return d;
	}
#endif
	;{
		struct disklabel dl;
		if (ioctl(fd, DIOCGDINFO, &dl) == 0)
			return dl.d_secsize;
	}
#ifdef DIOCGSLICEINFO
	;{
		struct diskslices dss;
		if (ioctl(fd, DIOCGSLICEINFO, &dss) == 0)
			return dss.dss_secsize;
	}
#endif
	return 0;
}

int
sys_bsd_getsectors(int fd, unsigned long *s)
{
	/* XXX */
	struct disklabel dl;
#if defined(DIOCGMEDIASIZE) && defined(DIOCGSECTORSIZE)
	;{
		off_t fullsize;
		unsigned sectsize;
		if (ioctl(fd, DIOCGMEDIASIZE, &fullsize) == 0 &&
		    ioctl(fd, DIOCGSECTORSIZE, &sectsize) == 0)
		{
			*s = fullsize / sectsize;
			return 0;
		}
	}
#endif
#ifdef DIOCGSLICEINFO
	/* XXX it is somehow ugly, but seems to work on 4.x. */
	;{
		struct diskslices dss;
		struct stat st;
		if (ioctl(fd, DIOCGSLICEINFO, &dss) == 0 &&
		    fstat(fd, &st) == 0)
		{
			int slice = 31 & (st.st_rdev >> 16);
			/* If it have disklabel, fall to disklabel case,
			 * because it shows more exact info.
			 */
			if (slice != WHOLE_DISK_SLICE &&
			    dss.dss_slices[slice].ds_label != NULL &&
			    ioctl(fd, DIOCGDINFO, &dl) == 0) {
				*s = (unsigned long) dl.d_secperunit;
				return 0;
			}
			*s = dss.dss_slices[slice].ds_size;
			return 0;
		}
	}
#endif
	/* Fallback method. */
	if (ioctl(fd, DIOCGDINFO, &dl) == 0) {
		*s = (unsigned long) dl.d_secperunit;
		return 0;
	}
	return -1;
}

int
sys_bsd_ptsync(int fd)
{
#ifdef DIOCSYNCSLICEINFO
	return ioctl(fd, DIOCSYNCSLICEINFO, NULL);
#else
	/* XXX I suppose here GEOM systems which:
	 * 1) Don't allow writing to raw disk if it is mounted anywhere,
	 * 2) Automatically update GEOM structures after writing to disk.
	 * Hence, no explicit syncing is required.
	 */
	return 0;
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

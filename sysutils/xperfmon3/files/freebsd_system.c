
/*
 * freebsd_system.c für FreeBSD-3.X
 * COPYRIGHT 1998 by Lars Köller <Lars.Koeller@Uni-Bielefeld.de>
 *
 * Work has started on 7th Sep 1998 on Northsea island Föhr.
 *
 *      $Id: freebsd_system.c,v 3.8 2001/04/10 19:39:44 lkoeller Exp lkoeller $
 */

/*
 * Copyright (c) 1998  Lars Köller
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 */

/*
 *
 * Parts of this program are derived from the iostat program:
 *
 * Copyright (c) 1997, 1998  Kenneth D. Merry.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 */

/*
 * Parts of this program are derived from other original FreeBSD programs:
 *
 * Copyright (c) 1986, 1991, 1993
 *      The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *      This product includes software developed by the University of
 *      California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
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
 */

#ifndef LINT
static char rcsid[] = "$Id: freebsd_system.c,v 3.8 2001/04/10 19:39:44 lkoeller Exp lkoeller $";
#endif

#include "fbsd_vers.h"

#include <X11/IntrinsicP.h>

#include "system.h"
#include "is.h"

#include <sys/file.h>
#include <sys/param.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/sysctl.h>
#include <sys/dkstat.h>
#include <sys/time.h>
#include <vm/vm.h>
#include <net/if.h>
#include <net/if_var.h>
#include <netinet/in.h>
#include <sys/stat.h>
#include <sys/conf.h>
#if __FreeBSD_version < 400000
#include <sys/rlist.h>
#endif
#include <sys/mount.h>
#include <nfs/rpcv2.h>
#include <nfs/nfsproto.h>
#include <nfs/nfs.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <ctype.h>
#include <paths.h>
#include <kvm.h>
#include <nlist.h>
#include <limits.h>
#include <errno.h>
#include <err.h>
#include <devstat.h>


struct nlist namelist[] = {
#define X_HZ          0
    { "_hz" },
#define X_STATHZ      1
    { "_stathz" },
#define X_CP_TIME     2
    { "_cp_time" },
#define X_TK_NIN      3
    { "_tk_nin" },
#define X_TK_NOUT     4
    { "_tk_nout" },
#define N_IFNET       5
    { "_ifnet" },
#define X_INTRCNT     6
    { "_intrcnt" },
#define X_EINTRCNT    7
    { "_eintrcnt" },
#define X_BOOTTIME    8
    { "_boottime" },
#if __FreeBSD_version < 400000
#define VM_NSWAP      9
    { "_nswap" },
#define VM_NSWDEV    10
    { "_nswdev" },
#define VM_DMMAX     11
    { "_dmmax" },
#define VM_SWAPLIST  12
    { "_swaplist" },
#define VM_SWDEVT    13
    { "_swdevt" },
#define X_END        13
    { NULL },
#else
#define X_END         8
    { NULL },
#endif /* __FreeBSD_version < 400000 */

};

extern Widget perfmon[NUM_GRAPHS];
extern char *info1;

double current_values[NUM_GRAPHS];

static kvm_t *kd;
static char errbuf[_POSIX2_LINE_MAX];
static int has_nfs;
static int hz, stathz;
static double etime, pct;
static long tmp;
struct vfsconf vfc;

/*
 * Variables holding the statistic information
 */
static struct statinfo cur, last;
static struct nfsstats nfsstats;
static struct _nfsStats {
    int ServerCalls, ServerCacheHit, ServerCacheMis;
    int ClientCalls, ClientCacheHit, ClientCacheMis;
} nfsStats, old_nfsStats;
static struct _packets {
    int input, output, collisions;
} packets, old_packets;
static int interrupts, old_interrupts;

/*
 * Variables need for devstat to get diskio statistics
 */
static struct statinfo cur, last;
static struct devstat_match *matches = NULL;
static struct device_selection *dev_select = NULL;
static int num_matches = 0, num_devices = 0, ncpu;
static int num_selected = 0, num_selections = 0;
static int num_devices_specified = 0, maxshowdevs;
static long generation, select_generation;
static char **specified_devices = NULL;
static struct _diskstat {
    long double da_trsf, da_mb;
    long double cd_trsf, cd_mb;
    long double sa_trsf, sa_mb;
} diskstat;

void sys_setup(void);
void update_stats(void);

static   void get_namelist(const char *kernel_name, const char *memory_name);
static   void kread(int nlx, void *addr, size_t size);
static double get_load(void);
static   void get_cpustat(void);
static   void get_ttystat(void);
static   void get_interrupts(void);
static   void init_diskio(void);
static   void get_diskio(void);
static double get_swapspace(void);
static   void get_netstat(void);
static   void get_nfsstat(void);


void
sys_setup(void)
{
    int size;

    get_namelist(getbootfile(), _PATH_MEM);

    /* To make calc of etime independent of number of CPUs */
    size = sizeof(ncpu);
    if (sysctlbyname("hw.ncpu", &ncpu, &size, NULL, 0) < 0)
	ncpu = 1;

    /* Initialize all stats, i.e. global variables */
    get_cpustat();
    get_load();
    get_ttystat();
    interrupts=0;
    get_interrupts();
    init_diskio();
    get_diskio();
    get_netstat();
    /*
     * To force first scale of 'free swapspace' to 100%, we need
     * set it the first time by hand!
     */
    current_values[FREE_MEM] = 100 * SCALE_HACK;
    /*
     * Check if we have NFS in the kernel
     */
    if (getvfsbyname("nfs", &vfc) < 0) {
	fprintf(stderr, "xperfmon++: getvfsbyname: NFS not compiled into kernel\n");
	has_nfs = FALSE;
    } else {
	has_nfs = TRUE;
	get_nfsstat();
    }
}


void
update_stats(void)
{
    static int firsttime = 1, i = FREE_MEM_INT;
    /*
     * For any stat we need etime, so get it!
     */
    get_cpustat();
    current_values[  USER_CPU_PERCENTAGE] = cur.cp_time[CP_USER] * pct * SCALE_HACK;
    current_values[  NICE_CPU_PERCENTAGE] = cur.cp_time[CP_NICE] * pct * SCALE_HACK;
    current_values[SYSTEM_CPU_PERCENTAGE] = cur.cp_time[CP_SYS]  * pct * SCALE_HACK;
    current_values[ INTER_CPU_PERCENTAGE] = cur.cp_time[CP_INTR] * pct * SCALE_HACK;
    current_values[  IDLE_CPU_PERCENTAGE] = cur.cp_time[CP_IDLE] * pct * SCALE_HACK;

    if (perfmon[LOAD])
	current_values[LOAD] = get_load() * SCALE_HACK;

    if (perfmon[TTY_CHARS_IN] || perfmon[TTY_CHARS_OUT]) {
        get_ttystat();
	current_values[TTY_IN]  = cur.tk_nin/etime * SCALE_HACK;
	current_values[TTY_OUT] = cur.tk_nout/etime * SCALE_HACK;
    }

    if (perfmon[INTERRUPTS]) {
	get_interrupts();
	current_values[INTERRUPTS] = (interrupts - old_interrupts)/etime * SCALE_HACK;
    }

    if (perfmon[FREE_MEM] && !firsttime) {
	/* Calc swapspace only every FREE_MEM_INT intervals */
	if ( i == FREE_MEM_INT ) {
	    i = 1;
	    current_values[FREE_MEM] = get_swapspace() * SCALE_HACK;
	} else
	    i++;
    } else {
	/* First time called we set freeswap to 100% to have full scale!*/
	firsttime--;
	current_values[FREE_MEM] = 100 * SCALE_HACK;
    }

    if (perfmon[DISK_TRANSFERS]  || perfmon[DISK_MB] ||
	perfmon[TAPE_TRANSFERS]  || perfmon[TAPE_MB] ||
	perfmon[CDROM_TRANSFERS] || perfmon[CDROM_MB] ) {
	get_diskio();
	current_values[DISK_TRANSFERS] = diskstat.da_trsf * SCALE_HACK;
	current_values[DISK_MB] = diskstat.da_mb * SCALE_HACK;
	current_values[TAPE_TRANSFERS] = diskstat.sa_trsf * SCALE_HACK;
	current_values[TAPE_MB] = diskstat.sa_mb * SCALE_HACK;
	current_values[CDROM_TRANSFERS] = diskstat.cd_trsf * SCALE_HACK;
	current_values[CDROM_MB] = diskstat.cd_mb * SCALE_HACK;
    }

    if (perfmon[INPUT_PACKETS]  || perfmon[OUTPUT_PACKETS] ||
	perfmon[COLLISION_PACKETS]){
	get_netstat();
	current_values[    INPUT_PACKETS] =
	    (packets.input  - old_packets.input)/etime * SCALE_HACK;
	current_values[   OUTPUT_PACKETS] =
	    (packets.output - old_packets.output)/etime * SCALE_HACK;
	/* LK!!! DEBUG
	   printf("input: %f   output: %f\n",current_values[INPUT_PACKETS]/SCALE_HACK,
	   current_values[   OUTPUT_PACKETS]/SCALE_HACK); */
	current_values[COLLISION_PACKETS] =
	    (packets.collisions - old_packets.collisions)/etime * SCALE_HACK;
    }

    if (has_nfs && (perfmon[NFS_CLIENT_CALLS] ||
		    perfmon[NFS_CLIENT_HIT]   ||
		    perfmon[NFS_CLIENT_MIS]   ||
		    perfmon[NFS_SERVER_CALLS] ||
		    perfmon[NFS_SERVER_HIT]   ||
		    perfmon[NFS_SERVER_MIS])) {
	get_nfsstat();
	current_values[NFS_CLIENT_CALLS] =
	    (nfsStats.ClientCalls - old_nfsStats.ClientCalls)/etime * SCALE_HACK;
	current_values[NFS_SERVER_CALLS] =
	    (nfsStats.ServerCalls - old_nfsStats.ServerCalls)/etime * SCALE_HACK;
	current_values[NFS_CLIENT_HIT] =
	    (nfsStats.ClientCacheHit - old_nfsStats.ClientCacheHit)/etime * SCALE_HACK;
	current_values[NFS_CLIENT_MIS] =
	    (nfsStats.ClientCacheMis - old_nfsStats.ClientCacheMis)/etime * SCALE_HACK;
	current_values[NFS_SERVER_HIT] =
	    (nfsStats.ServerCacheHit - old_nfsStats.ServerCacheHit)/etime * SCALE_HACK;
	current_values[NFS_SERVER_MIS] =
	    (nfsStats.ServerCacheMis - old_nfsStats.ServerCacheMis)/etime * SCALE_HACK;
    }
}


static void
get_namelist(kernel_name, memory_name)
    const char *kernel_name, *memory_name;
{
    register int i, ret;
    time_t now, boottime;
    int nintv;

    kd = kvm_openfiles(kernel_name, memory_name, NULL, O_RDONLY, errbuf);
    if (kd == 0)
	errx(1, "xperfmon++: kvm_openfiles: %s", errbuf);

    if ((ret = kvm_nlist(kd, namelist)) != 0) {
	if (ret > 0) {
	    (void)fprintf(stderr, "xperfmon++: undefined symbols:");
	    for (i = 0; i < sizeof(namelist)/sizeof(namelist[0]); i++)
		if (namelist[i].n_type == 0 || namelist[i].n_value == 0)
		    fprintf(stderr, "%s", namelist[i].n_name);
	    fprintf(stderr, "\n");
	} else
	    errx(1, "xperfmon++: kvm_nlist: %s", kvm_geterr(kd));
	exit(1);
    }

    kread(X_HZ, &hz, sizeof(hz));
    kread(X_STATHZ, &stathz, sizeof(stathz));

    if (stathz)
	hz = stathz;

    kread(X_BOOTTIME, &boottime, sizeof(boottime));
    time(&now);
    nintv = now - boottime;
    if (nintv <= 0 || nintv > 60*60*24*365*10)
	errx(1, "Time makes no sense ... namelist must be wrong");
}


static void
kread(nlx, addr, size)
    int nlx; void *addr; size_t size;
{
    char *sym;

    if (kvm_read(kd, namelist[nlx].n_value, addr, size) != size) {
	sym = namelist[nlx].n_name;
	if (*sym == '_')
	    ++sym;
	errx(1, "xperfmon++: %s: %s", sym, kvm_geterr(kd));
    }
}


static void
get_cpustat(void)
{
    register int i;
    double tot;

    kread(X_CP_TIME, cur.cp_time, sizeof(cur.cp_time));

    etime = 0.0;
    for (i = 0; i < CPUSTATES; i++) {
	tmp = cur.cp_time[i];
	cur.cp_time[i] -= last.cp_time[i];
	last.cp_time[i] = tmp;
	etime += cur.cp_time[i];
    }
    tot = etime;

    if (etime == 0.0 )
	etime = 1.0;

    etime /= (float)hz;
    etime /= ncpu;

    /*
     * scale to percent
     */
    if(tot)
	pct = 100.0 / tot;
    else
	pct = 0;
}


static double
get_load(void)
{
    double loadavg[3];

    loadavg[0] = 0.0;
    if (getloadavg(loadavg, sizeof(loadavg)/sizeof(loadavg[0])) == -1) {
	fprintf(stderr, "xperfmon++: getloadavg() returned no values\n");
	return(0.0);
    }
    return(loadavg[0]);
}


static void
get_ttystat(void)
{
    kread(X_TK_NIN,  &cur.tk_nin,  sizeof(cur.tk_nin));
    kread(X_TK_NOUT, &cur.tk_nout, sizeof(cur.tk_nout));

    tmp = cur.tk_nin;
    cur.tk_nin -= last.tk_nin;
    last.tk_nin = tmp;

    tmp = cur.tk_nout;
    cur.tk_nout -= last.tk_nout;
    last.tk_nout = tmp;
}


static void
get_interrupts(void)
{
    register int i;
    unsigned long *intrcnt;
    int nintr;

    old_interrupts = interrupts;

    nintr = namelist[X_EINTRCNT].n_value - namelist[X_INTRCNT].n_value;
    if ((intrcnt = (unsigned long *)malloc((size_t) nintr)) == NULL)
	err(1, "xperfmon++: malloc failed in get_interrupts()");
    nintr /= sizeof(long);
    kread(X_INTRCNT, intrcnt, (size_t)nintr*sizeof(long));
    for (i = 0, interrupts = 0; i < nintr; i++)
	interrupts += *(intrcnt + i);
    free(intrcnt);
}


/*
 * Parts extracted from /usr/src/usr.bin/nfsstat/nfsstat.c
 * pay attention Copyrights!
 */
static void
get_nfsstat(void)
{
#if __FreeBSD_version < 400001
    int name[3];
    size_t size = sizeof(nfsstats);

    name[0] = CTL_VFS;
    name[1] = vfc.vfc_typenum;
    name[2] = NFS_NFSSTATS;
    if (sysctl(name, 3, &nfsstats, &size, (void *)0, (size_t)0) < 0) {
#else
    size_t size = sizeof(nfsstats);
    if (sysctlbyname("vfs.nfs.nfsstats", &nfsstats, &size, (void *)0, (size_t)0) < 0) {
#endif
	fprintf(stderr, "xperfmon++: get_nfsstat(): Can't get NFS statistics with sysctl()\n");
	return;
    }

    old_nfsStats = nfsStats;

    nfsStats.ClientCalls =    nfsstats.rpccnt[NFSPROC_GETATTR] +
                              nfsstats.rpccnt[NFSPROC_SETATTR] +
                              nfsstats.rpccnt[NFSPROC_LOOKUP] +
                              nfsstats.rpccnt[NFSPROC_READLINK] +
                              nfsstats.rpccnt[NFSPROC_READ] +
                              nfsstats.rpccnt[NFSPROC_WRITE] +
                              nfsstats.rpccnt[NFSPROC_CREATE] +
                              nfsstats.rpccnt[NFSPROC_REMOVE] +
                              nfsstats.rpccnt[NFSPROC_RENAME] +
                              nfsstats.rpccnt[NFSPROC_LINK] +
                              nfsstats.rpccnt[NFSPROC_SYMLINK] +
                              nfsstats.rpccnt[NFSPROC_MKDIR] +
                              nfsstats.rpccnt[NFSPROC_RMDIR] +
                              nfsstats.rpccnt[NFSPROC_READDIR] +
                              nfsstats.rpccnt[NFSPROC_READDIRPLUS]+
                              nfsstats.rpccnt[NFSPROC_ACCESS] +
                              nfsstats.rpccnt[NFSPROC_MKNOD] +
                              nfsstats.rpccnt[NFSPROC_FSSTAT] +
                              nfsstats.rpccnt[NFSPROC_FSINFO] +
                              nfsstats.rpccnt[NFSPROC_PATHCONF] +
                              nfsstats.rpccnt[NFSPROC_COMMIT] +
                              nfsstats.rpccnt[NQNFSPROC_GETLEASE] +
                              nfsstats.rpccnt[NQNFSPROC_VACATED] +
                              nfsstats.rpccnt[NQNFSPROC_EVICTED];

    nfsStats.ClientCacheHit = nfsstats.attrcache_hits  +
                              nfsstats.lookupcache_hits +
                              nfsstats.biocache_reads  -
                              nfsstats.read_bios  +
                              nfsstats.biocache_writes -
                              nfsstats.write_bios  +
                              nfsstats.biocache_readlinks -
                              nfsstats.readlink_bios  +
                              nfsstats.biocache_readdirs -
                              nfsstats.readdir_bios  +
                              nfsstats.direofcache_hits;

    nfsStats.ClientCacheMis = nfsstats.attrcache_misses +
                              nfsstats.lookupcache_misses +
                              nfsstats.read_bios  +
                              nfsstats.write_bios  +
                              nfsstats.readlink_bios  +
                              nfsstats.readdir_bios  +
                              nfsstats.direofcache_misses;

    nfsStats.ServerCalls =    nfsstats.srvrpccnt[NFSPROC_GETATTR] +
                              nfsstats.srvrpccnt[NFSPROC_SETATTR] +
                              nfsstats.srvrpccnt[NFSPROC_LOOKUP] +
                              nfsstats.srvrpccnt[NFSPROC_READLINK] +
                              nfsstats.srvrpccnt[NFSPROC_READ] +
                              nfsstats.srvrpccnt[NFSPROC_WRITE] +
                              nfsstats.srvrpccnt[NFSPROC_CREATE] +
                              nfsstats.srvrpccnt[NFSPROC_REMOVE] +
                              nfsstats.srvrpccnt[NFSPROC_RENAME] +
                              nfsstats.srvrpccnt[NFSPROC_LINK] +
                              nfsstats.srvrpccnt[NFSPROC_SYMLINK] +
                              nfsstats.srvrpccnt[NFSPROC_MKDIR] +
                              nfsstats.srvrpccnt[NFSPROC_RMDIR] +
                              nfsstats.srvrpccnt[NFSPROC_READDIR] +
                              nfsstats.srvrpccnt[NFSPROC_READDIRPLUS]+
                              nfsstats.srvrpccnt[NFSPROC_ACCESS] +
                              nfsstats.srvrpccnt[NFSPROC_MKNOD] +
                              nfsstats.srvrpccnt[NFSPROC_FSSTAT] +
                              nfsstats.srvrpccnt[NFSPROC_FSINFO] +
                              nfsstats.srvrpccnt[NFSPROC_PATHCONF] +
                              nfsstats.srvrpccnt[NFSPROC_COMMIT] +
                              nfsstats.srvrpccnt[NQNFSPROC_GETLEASE] +
                              nfsstats.srvrpccnt[NQNFSPROC_VACATED] +
                              nfsstats.srvrpccnt[NQNFSPROC_EVICTED];

    nfsStats.ServerCacheHit = nfsstats.srvcache_inproghits  +
                              nfsstats.srvcache_idemdonehits +
                              nfsstats.srvcache_nonidemdonehits;

    nfsStats.ServerCacheMis = nfsstats.srvcache_misses;
}


/*
 * Stolen from /usr/src/usr.sbin/pstat/pstat.c  and
 *             /usr/src/usr.bin/top/machine.c       (pay attention Copyrights!)
 */
static double
get_swapspace(void)
{
#if __FreeBSD_version >= 400000
    /* based on swapmode from /usr/src/usr.bin/top/machine.c */
    int n;
    int percentfree;
    struct kvm_swap swapary[1];

    n = kvm_getswapinfo(kd, swapary, 1, 0);
    if (n < 0 || swapary[0].ksw_total == 0)
	return(0);

    percentfree = ((((double)swapary[0].ksw_total -
		     (double)swapary[0].ksw_used) * 100.0) /
		   (double)swapary[0].ksw_total);
    return(percentfree);

#else
    /* based on /usr/src/usr.sbin/pstat/pstat.c */
    char *header;
    int hlen, nswap, nswdev, dmmax;
    int i, div, avail, nfree, npfree, used;
    struct swdevt *sw;
    long blocksize, *perdev;
    struct rlist head;
    struct rlisthdr swaplist;
    struct rlist *swapptr;
    u_long ptr;

    kread(VM_NSWAP, &nswap, sizeof(nswap));
    kread(VM_NSWDEV, &nswdev, sizeof(nswdev));
    kread(VM_DMMAX, &dmmax, sizeof(dmmax));
    kread(VM_SWAPLIST, &swaplist, sizeof(swaplist));
    if ((sw = malloc(nswdev * sizeof(*sw))) == NULL ||
	(perdev = malloc(nswdev * sizeof(*perdev))) == NULL)
	err(1, "xperfmon++ malloc in get_swapspace");
    kread(VM_SWDEVT, &ptr, sizeof(ptr));
    kvm_read(kd, ptr, sw, nswdev * sizeof(*sw));

    /* Count up swap space. */
    nfree = 0;
    memset(perdev, 0, nswdev * sizeof(*perdev));
    swapptr = swaplist.rlh_list;
    while (swapptr) {
	int top, bottom, next_block;
	kvm_read(kd, (u_long)swapptr, &head, sizeof(struct rlist));
	top = head.rl_end;
	bottom = head.rl_start;

	nfree += top - bottom + 1;

	/*
	 * Swap space is split up among the configured disks.
	 *
	 * For interleaved swap devices, the first dmmax blocks
	 * of swap space some from the first disk, the next dmmax
	 * blocks from the next, and so on up to nswap blocks.
	 *
	 * The list of free space joins adjacent free blocks,
	 * ignoring device boundries.  If we want to keep track
	 * of this information per device, we'll just have to
	 * extract it ourselves.
	 */
	while (top / dmmax != bottom / dmmax) {
	    next_block = ((bottom + dmmax) / dmmax);
	    perdev[(bottom / dmmax) % nswdev] +=
		next_block * dmmax - bottom;
	    bottom = next_block * dmmax;
	}
	perdev[(bottom / dmmax) % nswdev] +=
	    top - bottom + 1;
	swapptr = head.rl_next;
    }
    header = getbsize(&hlen, &blocksize);
    div = blocksize / 512;
    avail = npfree = 0;
    for (i = 0; i < nswdev; i++) {
	int xsize, xfree;

	/*
	 * Don't report statistics for partitions which have not
	 * yet been activated via swapon(8).
	 */
	if (!(sw[i].sw_flags & SW_FREED))
	    continue;

	/* The first dmmax is never allocated to avoid trashing of
	 * disklabels
	 */
	xsize = sw[i].sw_nblks - dmmax;
	xfree = perdev[i];
	used = xsize - xfree;
	npfree++;
	avail += xsize;
    }

    /*
     * If only one partition has been set up via swapon(8), we don't
     * need to bother with totals.
     */
    used = avail - nfree;
    free(sw);
    free(perdev);

    return((100.0*nfree)/avail);

#endif /* __FreeBSD_version >= 400000 */
}



/*
 * Stolen from /usr/src/usr.bin/netstat/if.c
 * pay attention Copyrights!
 */
static void
get_netstat(void)
{
    off_t ifnetaddr;
    char name[32], tname[16], *interface = '\0';

    if ((ifnetaddr = namelist[N_IFNET].n_value) != 0) {
	struct ifnet ifnet;
	struct ifnethead ifnethead;
	u_long ifaddraddr, ifnetfound;
	struct ifaddr ifa;

	if(kvm_read(kd, ifnetaddr, (char *)&ifnethead, sizeof(ifnethead)) == -1)
	    return;
	ifnetaddr = (u_long)ifnethead.tqh_first;
	if(kvm_read(kd, ifnetaddr, (char *)&ifnet, sizeof(ifnet)) == -1)
	    return;

	old_packets = packets;
	packets.input = packets.output = packets.collisions = 0;
	ifaddraddr = 0;
	while (ifnetaddr || ifaddraddr) {
	    if (ifaddraddr == 0) {
		ifnetfound = ifnetaddr;
		/* Get stats and interface name to select a specific one (TODO) */
		if(kvm_read(kd, ifnetaddr, (char *)&ifnet, sizeof ifnet) == -1 ||
		   kvm_read(kd, (u_long)ifnet.if_name, (char *)tname, 16) ==  -1)
		    return;
		tname[15] = '\0';
		ifnetaddr = (u_long)ifnet.if_link.tqe_next;
		snprintf(name, 32, "%s%d", tname, ifnet.if_unit);
                if (interface != 0 && (strcmp(name, interface) != 0))
		    continue;
		ifaddraddr = (u_long)ifnet.if_addrhead.tqh_first;
	    }
	    if (kvm_read(kd, ifaddraddr, (char *)&ifa, sizeof ifa) == -1) {
		ifaddraddr = 0;
		continue;
	    }
	ifaddraddr = (u_long)ifa.ifa_link.tqe_next;
	/* Normalize number of packets, we count interface four timess */
	packets.input += (ifnet.if_ipackets >> 2);
	packets.output += (ifnet.if_opackets >> 2);
	packets.collisions += ifnet.if_collisions;
	}
    }
}

/*
 * Many thanks to Kenneth Merry <ken@plutotech.com> who helped to code
 * the initial disk statistic routines
 */
static void
init_diskio(void)
{
    int retval;

    cur.dinfo = (struct devinfo *) malloc(sizeof(struct devinfo));
    last.dinfo = (struct devinfo *) malloc(sizeof(struct devinfo));
    bzero(cur.dinfo, sizeof(struct devinfo));
    bzero(last.dinfo, sizeof(struct devinfo));

    if (checkversion() < 0)
	errx(1, "xperfmon++: %s", devstat_errbuf);

    /*
     * man muß über specified devices gehen, um da1,... zu
     * selektieren, siehe /usr/src/usr.sbin/iostat/iostat.c
     */

/*    printf("%s\n", info1); LK!!! */
    if (buildmatch("da", &matches, &num_matches) != 0)
	errx(1, "xperfmon++: %s", devstat_errbuf);
    if (buildmatch("sa", &matches, &num_matches) != 0)
	errx(1, "xperfmon++: %s", devstat_errbuf);
    if (buildmatch("cd", &matches, &num_matches) != 0)
	errx(1, "xperfmon++: %s", devstat_errbuf);

    if (getdevs(&cur) == -1)
	errx(1, "xperfmon++: %s", devstat_errbuf);

    maxshowdevs = 50;

    num_devices = cur.dinfo->numdevs;
    generation = cur.dinfo->generation;

    retval = selectdevs(&dev_select, &num_selected,
			&num_selections, &select_generation,
			generation, cur.dinfo->devices,
			num_devices, matches, num_matches,
			specified_devices, num_devices_specified,
			DS_SELECT_ONLY, maxshowdevs, 0);
    switch (retval) {
	case -1:
	    errx(1, "xperfmon++: %s", devstat_errbuf);
	    break;
	default:
	    break;
    }
}


static void
get_diskio(void)
{
    register int dn;
    long double busy_seconds;
    long double transfers_per_second, mb_per_second;
    struct devinfo *tmp_dinfo;

    tmp_dinfo = last.dinfo;
    last.dinfo = cur.dinfo;
    cur.dinfo = tmp_dinfo;
    last.busy_time = cur.busy_time;

    switch (getdevs(&cur)) {
	case -1:
		errx(1, "xperfmon++: %s", devstat_errbuf);
		break;
	case 1: {
		int retval;

		num_devices = cur.dinfo->numdevs;
		generation = cur.dinfo->generation;
		retval = selectdevs(&dev_select, &num_selected,
				    &num_selections, &select_generation,
				    generation, cur.dinfo->devices,
				    num_devices, matches, num_matches,
				    specified_devices, num_devices_specified,
				    DS_SELECT_ONLY, maxshowdevs, 0);
		switch (retval) {
		case -1:
			errx(1, "xperfmon++: %s", devstat_errbuf);
			break;
		default:
			break;
		}
		break;
		}
	default:
		break;
	}

    /*
     * Calculate elapsed time up front, since it's the same for all
     * devices.
     */

    diskstat.da_trsf = diskstat.da_mb = 0.0;
    diskstat.sa_trsf = diskstat.sa_mb = 0.0;
    diskstat.cd_trsf = diskstat.cd_mb = 0.0;

    busy_seconds = compute_etime(cur.busy_time, last.busy_time);

    for (dn = 0; dn < num_devices; dn++) {
	int di;

	if (dev_select[dn].selected == 0)
	    continue;

	di = dev_select[dn].position;

	if (compute_stats(&cur.dinfo->devices[di],
			  &last.dinfo->devices[di], busy_seconds,
			  NULL, NULL,
			  NULL, NULL,
			  &transfers_per_second, &mb_per_second,
			  NULL, NULL) != 0)
	    errx(1, "xperfmon++: %s", devstat_errbuf);

	if (strcmp(cur.dinfo->devices[di].device_name, "da") == 0 ||
	    strcmp(cur.dinfo->devices[di].device_name, "ad") == 0 ||
	    strcmp(cur.dinfo->devices[di].device_name, "wd") == 0) {
#ifdef DEBUG
	    printf( "da%d: %Lf %Lf\n", cur.dinfo->devices[di].unit_number, transfers_per_second, mb_per_second);
#endif
	    diskstat.da_trsf += transfers_per_second;
	    diskstat.da_mb   += mb_per_second;
	}
	if (strcmp(cur.dinfo->devices[di].device_name, "sa") == 0) {
#ifdef DEBUG
	    printf( "sa%d: %Lf %Lf\n", cur.dinfo->devices[di].unit_number, transfers_per_second, mb_per_second);
#endif
	    diskstat.sa_trsf += transfers_per_second;
	    diskstat.sa_mb   += mb_per_second;
	}
	if (strcmp(cur.dinfo->devices[di].device_name, "cd")  == 0 ||
	    strcmp(cur.dinfo->devices[di].device_name, "acd") == 0) {
#ifdef DEBUG
	    printf( "cd%d: %Lf %Lf\n", cur.dinfo->devices[di].unit_number, transfers_per_second, mb_per_second);
#endif
	    diskstat.cd_trsf += transfers_per_second;
	    diskstat.cd_mb   += mb_per_second;
	}

    }

}

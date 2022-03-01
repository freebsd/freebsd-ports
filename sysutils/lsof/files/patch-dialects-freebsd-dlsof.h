--- dialects/freebsd/dlsof.h.orig	2020-11-10 19:00:21 UTC
+++ dialects/freebsd/dlsof.h
@@ -52,27 +52,7 @@
 #include <sys/_lock.h>
 #undef _KERNEL
 #endif         /* FREEBSDV>=13000 */
-# if	FREEBSDV>=4000
-#  if	FREEBSDV>=5000
-#   if	FREEBSDV<6020
-#    if	defined(__alpha__)
-/*
- * For Alpha below 6.2, #include <machine/pcpu.h> before #define'ing _KERNEL.
- * Then #define PCPU_MD_FIELDS independently.  This hack avoids a compiler
- * complaint about register use.
- */
-
-#include <machine/pcpu.h>       
-#define PCPU_MD_FIELDS                                                  \
-	struct alpha_pcb pc_idlepcb;            /* pcb for idling */    \
-	u_int64_t       pc_idlepcbphys;         /* pa of pc_idlepcb */  \
-	u_int64_t       pc_pending_ipis;        /* pending IPI's */     \
-	u_int32_t       pc_next_asn;            /* next ASN to alloc */ \
-	u_int32_t       pc_current_asngen       /* ASN rollover check */
-#    endif	/* defined(__alpha__) */
-#   endif	/* FREEBSDV<6020 */
 #define	_KERNEL	1
-#  endif	/* FREEBSDV>=5000 */
 
 #  if	defined(HAS_VM_MEMATTR_T)
 /*
@@ -129,23 +109,17 @@ typedef	struct device	*device_t;
 #include "fbsd_minor.h"
 #  endif	/* defined(HAS_CONF_MINOR) */
 
-#  if	FREEBSDV>=5000
 #undef	_KERNEL
-#  endif	/* FREEBSDV>=5000 */
-# endif	/* FREEBSDV>=4000 */
 
 #include <sys/filedesc.h>
 #include <sys/mbuf.h>
 #define	NFS
 #define m_stat	mnt_stat
 
-# if	FREEBSDV>=3020
 #define	_KERNEL
-# endif	/* FREEBSDV>=3020 */
 
 #include <sys/mount.h>
 
-# if	FREEBSDV>=3020
 #  if	defined(__clang__)
 /*
  * This definition is needed when clang is used, because <sys/mount.h> must
@@ -156,7 +130,6 @@ int     getmntinfo(struct statfs **, int);
 #  endif	/* defined(__clang__) */
 
 #undef	_KERNEL
-# endif	/* FREEBSDV>=3020 */
 
 #include <rpc/types.h>
 #include <sys/protosw.h>
@@ -167,9 +140,7 @@ int     getmntinfo(struct statfs **, int);
 #define	_WANT_UNPCB
 #include <sys/unpcb.h>
 
-# if	FREEBSDV>=3000
 #undef	INADDR_LOOPBACK
-# endif	/* FREEBSDV>=3000 */
 
 #include <netinet/in.h>
 #include <netinet/in_systm.h>
@@ -202,21 +173,9 @@ int     getmntinfo(struct statfs **, int);
 #include <rpc/pmap_prot.h>
 #undef	pmap
 
-# if	FREEBSDV<2000
-#include <ufs/quota.h>
-#include <ufs/inode.h>
-#include <ufs/ufsmount.h>
-#include <ufs/mfsnode.h>
-# else	/* FREEBSDV>=2000 */
 #include <paths.h>
 #include <ufs/ufs/quota.h>
 
-#  if	FREEBSDV>=4000 && FREEBSDV<5000
-#   if	defined(__alpha__) || defined(__sparc64__)
-#define	dev_t	void *
-#   endif	/* defined(__alpha__) || defined(__sparc64__) */
-#  endif /* FREEBSDV>=4000 && FREEBSDV<5000 */
-
 #include <ufs/ufs/inode.h>
 
 # if	defined(HAS_UFS1_2)
@@ -250,59 +209,28 @@ struct vop_setextattr_args;
 #undef	_KERNEL
 # endif	/* defined(HAS_UFS1_2) */
 
-#  if	FREEBSDV>=5010
 #undef	i_devvp
-#  endif	/* FREEBSDV>=5010 */
 
-#  if	FREEBSDV>=4000 && FREEBSDV<5000
-#   if	defined(__alpha__) || defined(__sparc64__)
-#undef	dev_t
-#   endif	/* defined(__alpha__) || defined(__sparc64__) */
-#  endif /* FREEBSDV>=4000 && FREEBSDV<5000 */
-
-#  if   FREEBSDV<2020
-#include <ufs/mfs/mfsnode.h>
-#  endif        /* FREEBSDV<2020 */
-
-# endif	/* FREEBSDV<2000 */
-
-# if	FREEBSDV<5000
-#include <nfs/nfsv2.h>
-# else	/* FREEBSDV>=5000 */
 #include <nfs/nfsproto.h>
-# endif	/* FREEBSDV<5000 */
 
 # if	defined(HASRPCV2H)
 #include <nfs/rpcv2.h>
 # endif	/* defined(HASRPCV2H) */
 
-# if	FREEBSDV>=5000
 #include <nfsclient/nfs.h>
 #include <nfsclient/nfsnode.h>
-# else	/* FREEBSDV<5000 */
-#include <nfs/nfs.h>
-#include <nfs/nfsnode.h>
-# endif	/* FREEBSDV>=5000 */
 
 #include <sys/proc.h>
 #include <kvm.h>
 #undef	TRUE
 #undef	FALSE
 
-# if	FREEBSDV<2000
-#include <sys/kinfo.h>
-# else	/* FREEBSDV>=2000 */
 #include <sys/sysctl.h>
-# endif	/* FREEBSDV<2000 */
 
 # if	defined(HASFDESCFS)
 #define	_KERNEL
 #define	KERNEL
-#  if	FREEBSDV>=5000
 #include <fs/fdescfs/fdesc.h>
-#  else	/* FREEBSDV<5000 */
-#include <miscfs/fdesc/fdesc.h>
-#  endif	/* FREEBSDV>=5000 */
 #undef	_KERNEL
 #undef	KERNEL
 # endif	/* defined(HASFDESCFS) */
@@ -311,24 +239,13 @@ struct vop_setextattr_args;
 #define	_KERNEL
 #define	KERNEL
 struct vop_generic_args;
-#  if	FREEBSDV>=5000
 #include <fs/nullfs/null.h>
-#  else	/* FREEBSDV<5000 */
-#include <miscfs/nullfs/null.h>
-#  endif	/* FREEBSDV>=5000 */
 #undef	_KERNEL
 #undef	KERNEL
 # endif	/* defined(HASNULLFS) */
 
 # if	defined(HASPROCFS)
-#  if	FREEBSDV<2000
-#include <procfs/pfsnode.h>
-# else	/* FREEBSDV>=2000 */
-#  if	FREEBSDV<5000
-#include <miscfs/procfs/procfs.h>
-#  endif	/* FREEBSDV<5000 */
 #include <machine/reg.h>
-# endif	/* FREEBSDV<2000 */
 
 #define	PNSIZ		5
 # endif	/* defined(HASPROCFS) */
@@ -342,24 +259,6 @@ struct vop_generic_args;
 # endif	/* defined(HAS_ZFS) */
 
 
-# if	FREEBSDV<2000
-#define	P_COMM		p_comm
-#define	P_FD		p_fd
-#define	P_PID		p_pid
-#define	P_PGID		p_pgrp
-#define	P_STAT		p_stat
-#define	P_VMSPACE	p_vmspace
-# else	/* FREEBSDV>=2000 */
-#  if	FREEBSDV<5000
-#define	P_ADDR		kp_eproc.e_paddr
-#define	P_COMM		kp_proc.p_comm
-#define	P_FD		kp_proc.p_fd
-#define	P_PID		kp_proc.p_pid
-#define	P_PGID		kp_eproc.e_pgid
-#define	P_PPID		kp_eproc.e_ppid
-#define	P_STAT		kp_proc.p_stat
-#define	P_VMSPACE	kp_proc.p_vmspace
-#  else	/* FREEBSDV>=5000 */
 #define	P_ADDR		ki_paddr
 #define	P_COMM		ki_comm
 #define	P_FD		ki_fd
@@ -368,8 +267,6 @@ struct vop_generic_args;
 #define	P_PPID		ki_ppid
 #define	P_STAT		ki_stat
 #define	P_VMSPACE	ki_vmspace
-#  endif	/* FREEBSDV<5000 */
-# endif	/* FREEBSDV<2000 */
 
 #include <vm/vm.h>
 
@@ -431,20 +328,12 @@ int     open(const char *, int, ...);
 
 # if	defined(DTYPE_KQUEUE)
 #define	HASKQUEUE				/* has the kqueue file type */
-#   if	FREEBSDV>=4090
 #define	_KERNEL
-#   endif	/* FREEBSDV>=4090 */
 #include <sys/eventvar.h>
-#   if	FREEBSDV>=4090
 #undef	_KERNEL
-#   endif	/* FREEBSDV>=4090 */
 # endif	/* defined(DTYPE_KQUEUE) */
 
-# if	FREEBSDV<2000
-#include <ufs/lockf.h>
-# else	/* FREEBSDV>=2000 */
 struct vop_advlock_args { int dummy; };	/* to pacify lf_advlock() prototype */
-#  if	FREEBSDV>=5000
 #undef	MALLOC_DECLARE
 #define	MALLOC_DECLARE(type)	extern struct malloc_type type[1]
 					/* to pacify <sys/lockf.h> */
@@ -460,23 +349,15 @@ struct vop_advlock_args { int dummy; };	/* to pacify l
 
 #include <fs/devfs/devfs.h>
 #undef	_KERNEL
-#  endif	/* FREEBSDV>=5000 */
 #include <sys/lockf.h>
-# endif	/* FREEBSDV<2000 */
 
-#  if   FREEBSDV>=2020
-#   if	FREEBSDV>=4090
 #define	_KERNEL
-#   endif	/* FREEBSDV>=4090 */
 #include <sys/pipe.h>
-#   if	FREEBSDV>=4090
 #undef	_KERNEL
-#   endif	/* FREEBSDV>=4090 */
 #   if	defined(HASVMLOCKH)
 #include <vm/lock.h>
 #   endif	/* defined(HASVMLOCKH) */
 #include <vm/pmap.h>
-#  endif        /* FREEBSDV>=2020 */
 
 #include <vm/vm_map.h>
 
@@ -492,21 +373,13 @@ struct vop_advlock_args { int dummy; };	/* to pacify l
 #include <vm/vm_object.h>
 #include <vm/vm_pager.h>
 
-# if   FREEBSDV>=2020
 #undef	B_NEEDCOMMIT
 
-#  if	FREEBSDV>=5000
 #include <sys/bio.h>
-#  endif	/* FREEBSDV>=5000 */
 
 #include <sys/buf.h>
 #include <sys/user.h>
 
-#  if	FREEBSDV<5000
-#include <ufs/mfs/mfsnode.h>
-#  endif	/* FREEBSDV<5000 */
-# endif        /* FREEBSDV>=2020 */
-
 #undef	bcmp		/* avoid _KERNEL conflict */
 #undef	bcopy		/* avoid _KERNEL conflict */
 #undef	bzero		/* avoid _KERNEL conflict */
@@ -521,11 +394,7 @@ struct vop_advlock_args { int dummy; };	/* to pacify l
 #define DEVINCR		1024	/* device table malloc() increment */
 
 # if	!defined(FREEBSD_KA_T)
-#  if	FREEBSDV<2000
-typedef	off_t		KA_T;
-#  else	/* FREEBSDV>=2000 */
 typedef	u_long		KA_T;
-#  endif	/* FREEBSDV<2000 */
 # endif	/* !defined(FREEBSD_KA_T) */
 
 #define	KMEM		"/dev/kmem"
@@ -559,11 +428,9 @@ typedef	u_long		KA_T;
  * Global storage definitions (including their structure definitions)
  */
 
-struct file * Cfp;
+extern struct file * Cfp;
 
-# if	FREEBSDV>=2000
 extern kvm_t *Kd;
-# endif	/* FREEBSDV>=2000 */
 
 # if	defined(P_ADDR)
 extern KA_T Kpa;
@@ -607,9 +474,7 @@ extern KA_T X_bfopsa;
 
 extern int Np;				/* number of kernel processes */
 
-# if	FREEBSDV>=2000
 extern struct kinfo_proc *P;		/* local process table copy */
-# endif	/* FREEBSDV>=2000 */
 
 struct sfile {
 	char *aname;			/* argument file name */
@@ -626,15 +491,8 @@ struct sfile {
 
 };
 
-# if	FREEBSDV==4100 || FREEBSDV==4110
-#define	XDR_VOID	(xdrproc_t)xdr_void
-#define	XDR_PMAPLIST	(xdrproc_t)xdr_pmaplist
-# endif	/* FREEBSDV==4100 || FREEBSDV==4110 */
-
-# if	FREEBSDV>=5000
 #define	XDR_VOID	(const xdrproc_t)xdr_void
 #define	XDR_PMAPLIST	(const xdrproc_t)xdr_pmaplist
-# endif	/* FREEBSDV>=5000 */
 
 
 /*
@@ -651,9 +509,9 @@ struct sfile {
 
 # if     defined(HASNCACHE)
 #include <sys/uio.h>
-#  if	FREEBSDV<4000 || (FREEBSDV>=4000 && defined(HASNAMECACHE))
+#  if	 defined(HASNAMECACHE)
 #include <sys/namei.h>
-#  else	/* FREEBSDV>=4000 && !defined(HASNAMECACHE) */
+#  else	/* !defined(HASNAMECACHE) */
 /*
  * The namecache struct definition should come from a header file that
  * can be #include'd, but it has been moved to a kernel source file in
@@ -663,9 +521,9 @@ struct sfile {
  */
 
 struct	namecache {
-	LIST_ENTRY(namecache) nc_hash;	/* hash chain */
 	LIST_ENTRY(namecache) nc_src;	/* source vnode list */
 	TAILQ_ENTRY(namecache) nc_dst;	/* destination vnode list */
+	LIST_ENTRY(namecache) nc_hash;	/* hash chain */
 	struct	vnode *nc_dvp;		/* vnode of parent of name */
 	struct	vnode *nc_vp;		/* vnode the name refers to */
 	u_char	nc_flag;		/* flag bits */
@@ -682,22 +540,14 @@ struct	namecache {
 					 * suggesting the guess is a safe one.
 					 * (VAA, 10 Apr 2002) */
 };
-#  endif	/* FREEBSDV<4000 || (FREEBSDV>=4000 && defined(HASNAMECACHE)) */
+#  endif	/* defined(HASNAMECACHE) */
 
 #define	NCACHE		namecache	/* kernel's structure name */
 #define	NCACHE_NM	nc_name		/* name in NCACHE */
 #define	NCACHE_NMLEN	nc_nlen		/* name length in NCACHE */
 
-#  if	FREEBSDV<2005
-#define	NCACHE_NXT	nc_nxt		/* link in NCACHE */
-#  else	/* FREEBSDV>=2005 */
-#   if	FREEBSDV<2010
-#define	NCACHE_NXT	nc_lru.tqe_next	/* link in NCACHE */
-#   else	/* FREEBSDV>=2010 */
 #include <stddef.h>
 #define	NCACHE_NXT	nc_hash.le_next	/* link in NCACHE */
-#   endif	/* FREEBSDV<2010 */
-#  endif	/* FREEBSDV<2005 */
 
 #define	NCACHE_NODEADDR	nc_vp		/* node address in NCACHE */
 #define	NCACHE_PARADDR	nc_dvp		/* parent node address in NCACHE */
@@ -708,9 +558,7 @@ struct	namecache {
 #  endif	/* DEFINED(HASNCVPID) */
 # endif  /* defined(HASNCACHE) */
 
-# if	FREEBSDV>=5000
 #define	VNODE_VFLAG	v_iflag
 #define	NCACHE_VROOT	VV_ROOT
-# endif	/* FREEBSDV>=5000 */
 
 #endif	/* defined(FREEBSD_LSOF_H) */

--- dialects/freebsd/dproc.c.orig	2020-11-10 19:00:21 UTC
+++ dialects/freebsd/dproc.c
@@ -125,6 +125,9 @@ gather_proc_info()
 					 *	   streams with eXPORT data,
 					 *	   where supported */
 	struct filedesc fd;
+#if	defined(PWDDESC_KVM_LOAD_PWD)
+	struct pwddesc pd;
+#endif	/* defined(PWDDESC_KVM_LOAD_PWD) */
 	int i, nf;
 	MALLOC_S nb;
 
@@ -157,13 +160,7 @@ gather_proc_info()
 	int tid;			/* thread (task) ID */
 	uid_t uid;
 
-#if	FREEBSDV<2000
-	struct proc *p;
-	struct pcred pc;
-	struct pgrp pg;
-#else	/* FREEBSDV>=2000 */
 	struct kinfo_proc *p;
-#endif	/* FREEBSDV<2000 */
 
 #if	defined(HASFSTRUCT) && !defined(HAS_FILEDESCENT)
 	static char *pof = (char *)NULL;
@@ -223,9 +220,6 @@ gather_proc_info()
  * Read the process table.
  */
 
-#if	FREEBSDV<2000
-	if ((Np = kvm_getprocs(KINFO_PROC_ALL, 0)) < 0)
-#else	/* FREEBSDV>=2000 */
 
 # if	!defined(KERN_PROC_PROC)
 #define	KERN_PROC_PROC  KERN_PROC_ALL
@@ -234,18 +228,11 @@ gather_proc_info()
 	if ((P = kvm_getprocs(Kd, Ftask ? KERN_PROC_ALL : KERN_PROC_PROC,
 			      0, &Np))
 	== NULL)
-#endif	/* FREEBSDV<2000 */
 
 	{
 	    (void) fprintf(stderr, "%s: can't read process table: %s\n",
 		Pn,
-
-#if	FREEBSDV<2000
-		kvm_geterr()
-#else	/* FREEBSDV>=2000 */
 		kvm_geterr(Kd)
-#endif	/* FREEBSDV<2000 */
-
 	    );
 	    Exit(1);
 	}
@@ -253,43 +240,13 @@ gather_proc_info()
  * Examine proc structures and their associated information.
  */
 
-#if	FREEBSDV<2000
-	for (px = 0; px < Np; px++)
-#else	/* FREEBSDV>=2000 */
 	for (p = P, px = 0; px < Np; p++, px++)
-#endif	/* FREEBSDV<2000 */
-
 	{
 
-#if	FREEBSDV<2000
-	/*
-	 * Read process information, process group structure (if
-	 * necessary), and User ID (if necessary).
-	 */
-	    if (!(p = kvm_nextproc()))
-		continue;
 	    if (p->P_STAT == 0 || p->P_STAT == SZOMB)
 		continue;
-	    pg.pg_id = 0;
-	    if (Fpgid && p->P_PGID) {
-		if (kread((KA_T)p->P_PGID, (char *)&pg, sizeof(pg)))
-		    continue;
-	    }
-	    pgid = pg.pg_id;
-	    if (!p->p_cred
-	    ||  kread((KA_T)p->p_cred, (char *)&pc, sizeof(pc)))
-		continue;
-	    uid = pc.p_ruid;
-#else	/* FREEBSDV>=2000 */
-	    if (p->P_STAT == 0 || p->P_STAT == SZOMB)
-		continue;
 	    pgid = p->P_PGID;
-# if	FREEBSDV<5000
-	    uid = p->kp_eproc.e_ucred.cr_uid;
-# else	/* FREEBSDV>=5000 */
 	    uid = p->ki_uid;
-# endif	/* FREEBSDV<5000 */
-#endif	/* FREEBSDV<2000 */
 
 #if	defined(HASPPID)
 	    ppid = p->P_PPID;
@@ -330,7 +287,11 @@ gather_proc_info()
 
 #if	defined(HAS_PWD)
 	    cdir = rdir = jdir = NULL;
+#if       defined(PWDDESC_KVM_LOAD_PWD)
+	    pwd_addr = (KA_T)PWDDESC_KVM_LOAD_PWD(&pd);
+#else   /* defined(PWDDESC_KVM_LOAD_PWD) */
 	    pwd_addr = (KA_T)FILEDESC_KVM_LOAD_PWD(&fd);
+#endif  /* defened(PWDDESC_KVM_LOAD_PWD) */
 	    if (pwd_addr != 0) {
 		    if (!kread(pwd_addr, (char *)&pwd, sizeof(pwd))) {
 			    cdir = pwd.pwd_cdir;
@@ -397,7 +358,6 @@ gather_proc_info()
 		    link_lfile();
 	    }
 
-#if	FREEBSDV>=5000
 	/*
 	 * Save jail directory information.
 	 */
@@ -408,7 +368,6 @@ gather_proc_info()
 		if (Lf->sf)
 		    link_lfile();
 	    }
-#endif	/* FREEBSDV>=5000 */
 
 	/*
 	 * Save information on the text file.
@@ -561,23 +520,13 @@ get_kernel_access()
  * Open kernel memory access.
  */
 
-#if	FREEBSDV<2000
-	if (kvm_openfiles(Nmlst, Memory, NULL) == -1)
-#else	/* FREEBSDV>=2000 */
 	if ((Kd = kvm_open(Nmlst, Memory, NULL, O_RDONLY, NULL)) == NULL)
-#endif	/* FREEBSDV<2000 */
 
 	{
 	    (void) fprintf(stderr,
 		"%s: kvm_open%s(execfile=%s, corefile=%s): %s\n",
 		Pn,
-
-#if	FREEBSDV<2000
-		"files",
-#else	/* FREEBSDV>=2000 */
 		"",
-#endif	/* FREEBSDV<2000 */
-
 		Nmlst ? Nmlst : "default",
 		Memory ? Memory :
 
@@ -678,11 +627,7 @@ kread(addr, buf, len)
 {
 	int br;
 
-#if	FREEBSDV<2000
-	br = kvm_read((void *)addr, (void *)buf, len);
-#else	/* FREEBSDV>=2000 */
 	br = kvm_read(Kd, (u_long)addr, buf, len);
-#endif	/* FREEBSDV<2000 */
 
 	return((br == len) ? 0 : 1);
 }
@@ -724,9 +669,6 @@ process_text(vm)
 	struct vm_object vmo;
 	struct vmspace vmsp;
 
-#if	FREEBSDV<2020
-	struct pager_struct pg;
-#endif	/* FREEBSDV<2020 */
 
 /*
  * Read the vmspace structure for the process.
@@ -762,30 +704,16 @@ process_text(vm)
 		 j < 2 && ka;
 		 j++,
 
-#if	FREEBSDV<2020
-		 ka = (KA_T)vmo.shadow
-#else	/* FREEBSDV>=2020 */
 		 ka = (KA_T)vmo.backing_object
-#endif	/* FREEBSDV<2020 */
 		 )
 	    {
 		if (kread(ka, (char *)&vmo, sizeof(vmo)))
 		    break;
 
-#if	FREEBSDV<2020
-		if ((ka = (KA_T)vmo.pager) == NULL
-		||  kread(ka, (char *)&pg, sizeof(pg)))
-		    continue;
-		if (pg.pg_handle == NULL || pg.pg_type != PG_VNODE)
-		    continue;
-		(void) (enter_vn_text((KA_T)pg.pg_handle, &n));
-#else	/* FREEBSDV>=2020 */
 		if (vmo.type != OBJT_VNODE
 		||  vmo.handle == (void *)NULL)
 		    continue;
 		(void) (enter_vn_text((KA_T)vmo.handle, &n));
-#endif	/* FREEBSDV<2020 */
-
 	    }
 	}
 }

--- ps/ps.c.orig	2024-08-02 07:55:02.072464000 -0700
+++ ps/ps.c	2024-08-02 08:09:25.924815000 -0700
@@ -87,6 +87,9 @@
 #define	proc	process
 #undef	p_pgid
 #undef	p_pctcpu
+#if !defined(PS_SWAPPINGOUT) && defined(P_SWAPPINGOUT)
+#define PS_SWAPPINGOUT P_SWAPPINGOUT
+#endif
 #if defined (__DragonFly__)
 #endif	/* __DragonFly__ */
 #elif defined (__hpux)
@@ -491,6 +494,7 @@
 
 static void		postproc(struct proc *);
 static enum okay	selectproc(struct proc *);
+static kvm_t		*kv;
 
 /************************************************************************
  * 			Utility functions				*
@@ -2139,7 +2143,6 @@
 static enum okay
 getproc_kvm(struct proc *p)
 {
-	static kvm_t	*kv;
 	struct kinfo_proc	*kp;
 	int	c;
 
@@ -2205,8 +2208,10 @@
 #else	/* __FreeBSD__ >= 5 */
 	if (kp->ki_sflag & PS_INMEM)
 		p->p_flag |= FL_LOAD;
+#if (__FreeBSD__) < 15
 	if (kp->ki_sflag & PS_SWAPPINGOUT)
 		p->p_flag |= FL_SWAP;
+#endif	/* __FreeBSD__ < 15 */
 	p->p_oldpri = ((double)kp->ki_pri.pri_user - PRI_MIN) /
 		(PRI_MAX - PRI_MIN) * 60 + 60;
 	p->p_pri = 40 - ((double)kp->ki_pri.pri_user - PRI_MIN) /
@@ -4874,6 +4879,7 @@
 #ifdef	__GLIBC__
 	putenv("POSIXLY_CORRECT=1");
 #endif
+	kv = NULL;
 	progname = basename(argv[0]);
 	sysname(argc, argv);
 	defaults();

--- ps/ps.c.orig	2007-02-02 06:40:20.000000000 -0800
+++ ps/ps.c	2009-03-06 14:51:53.455864840 -0800
@@ -88,6 +88,9 @@
 #define	proc	process
 #undef	p_pgid
 #undef	p_pctcpu
+#if !defined(PS_SWAPPINGOUT) && defined(P_SWAPPINGOUT)
+#define PS_SWAPPINGOUT P_SWAPPINGOUT
+#endif
 #if defined (__DragonFly__)
 #endif	/* __DragonFly__ */
 #elif defined (__hpux)
@@ -492,6 +495,7 @@
 
 static void		postproc(struct proc *);
 static enum okay	selectproc(struct proc *);
+static kvm_t		*kv;
 
 /************************************************************************
  * 			Utility functions				*
@@ -2140,7 +2144,6 @@
 static enum okay
 getproc_kvm(struct proc *p)
 {
-	static kvm_t	*kv;
 	struct kinfo_proc	*kp;
 	int	c;
 
@@ -4875,6 +4878,7 @@
 #ifdef	__GLIBC__
 	putenv("POSIXLY_CORRECT=1");
 #endif
+	kv = NULL;
 	progname = basename(argv[0]);
 	sysname(argc, argv);
 	defaults();

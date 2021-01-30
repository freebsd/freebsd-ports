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
 
@@ -330,7 +333,11 @@ gather_proc_info()
 
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

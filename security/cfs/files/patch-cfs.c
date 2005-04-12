
$FreeBSD$

--- cfs.c.orig
+++ cfs.c
@@ -43,7 +43,7 @@
 
 struct in_addr validhost;
 
-#if defined(SOLARIS2X) || defined(__NetBSD__)
+#if defined(SOLARIS2X) || defined(__NetBSD__) || defined(__FreeBSD__) || defined(__OpenBSD__)
 void nfs_program_2();
 void adm_program_2();
 #include <string.h>
@@ -240,7 +240,7 @@
  	setuid(0);
 	umask(0);
 
-#if defined(__NetBSD__) || defined(__bsdi__)
+#if defined(__NetBSD__) || defined(__bsdi__) || defined(__FreeBSD__) || defined(__OpenBSD__)
 #ifndef DEBUG
 	/* detach from terminal */
 	daemon(0,0);

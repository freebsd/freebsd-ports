--- src/usr.bin/make/make.h.orig	2020-08-29 02:06:40 UTC
+++ src/usr.bin/make/make.h
@@ -446,7 +446,7 @@ extern pid_t	myPid;
  *	There is one bit per module.  It is up to the module what debug
  *	information to print.
  */
-FILE *debug_file;		/* Output written here - default stdout */
+extern FILE *debug_file;		/* Output written here - default stdout */
 extern int debug;
 #define	DEBUG_ARCH	0x00001
 #define	DEBUG_COND	0x00002

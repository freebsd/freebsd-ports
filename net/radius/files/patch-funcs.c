--- src/funcs.c.orig	Sun Aug 26 03:03:53 2001
+++ src/funcs.c	Sun Aug 26 03:14:07 2001
@@ -8333,9 +8333,9 @@
 			return 1;
 		}
 
-/*The following two lines do not compile on Solaris or Linux or BSDI. */
-#if !(defined(sys5) || defined(linux) || defined (BSDI))
 		close (fileno(fp));
+/*The following two lines do not compile on Solaris or Linux or BSDI. */
+#if !(defined(sys5) || defined(linux) || defined (BSDI) || defined (__FreeBSD__))
 		fileno(fp) = STDERR_FILENO;
 #endif	/* sys5 */
 

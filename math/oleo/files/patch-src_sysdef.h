--- src/sysdef.h.orig	Sun Feb  4 16:54:21 2001
+++ src/sysdef.h	Sun Jun  6 23:08:43 2004
@@ -119,7 +119,9 @@
 
 #endif /* !defined(__STDC__) */
 
+#ifndef __FreeBSD__
 extern char *getenv ();
+#endif
 
 #ifndef RETSIGTYPE
 #define RETSIGTYPE void

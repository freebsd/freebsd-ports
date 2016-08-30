--- src/sysdef.h.orig	2001-02-04 15:54:21 UTC
+++ src/sysdef.h
@@ -119,7 +119,9 @@ extern char *strstr ();
 
 #endif /* !defined(__STDC__) */
 
+#ifndef __FreeBSD__
 extern char *getenv ();
+#endif
 
 #ifndef RETSIGTYPE
 #define RETSIGTYPE void

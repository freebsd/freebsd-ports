--- tacacs.h.orig	2010-02-12 18:13:56.000000000 -0500
+++ tacacs.h	2010-02-12 18:14:51.000000000 -0500
@@ -83,6 +83,10 @@ XXX unknown
 #define MSCHAP_DIGEST_LEN 49
 #endif /* MSCHAP */
 
+#ifdef FREEBSD
+#include <sys/param.h>
+#endif
+
 #if HAVE_STRING_H
 # include <string.h>
 #endif
@@ -124,7 +128,11 @@ XXX unknown
 # include <sys/syslog.h>
 #endif
 
+#if defined(FREEBSD) && __FreeBSD_version >= 900007
+#include <utmpx.h>
+#else
 #include <utmp.h>
+#endif
 
 #include <unistd.h>
 

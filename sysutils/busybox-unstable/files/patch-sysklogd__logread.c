--- ./sysklogd/logread.c.orig	2012-06-26 13:35:45.000000000 +0000
+++ ./sysklogd/logread.c	2012-07-17 02:08:37.000000000 +0000
@@ -20,6 +20,20 @@
 #include <sys/sem.h>
 #include <sys/shm.h>
 
+#include <osreldate.h>
+#if __FreeBSD_version < 800067
+size_t strnlen(const char *s, size_t maxlen);
+size_t strnlen(const char *s, size_t maxlen)
+{
+       size_t i;
+       for (i = 0; i < maxlen; i++) {
+               if (s[i] == '\0')
+                       break;
+       }
+       return i;
+}
+#endif
+
 #define DEBUG 0
 
 /* our shared key (syslogd.c and logread.c must be in sync) */

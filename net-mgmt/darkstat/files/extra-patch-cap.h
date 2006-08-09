--- cap.h.orig	Wed Jun 21 12:25:20 2006
+++ cap.h	Wed Aug  9 15:56:25 2006
@@ -5,6 +5,7 @@
  */
 
 #include <sys/types.h> /* OpenBSD needs this before select */
+#include <sys/time.h> /* FreeBSD 4 needs this for struct timeval */
 #include <sys/select.h>
 
 void cap_init(const char *device, const char *filter);

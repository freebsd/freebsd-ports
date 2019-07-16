--- sysklogd/klogd.c.orig	2018-12-30 15:14:20 UTC
+++ sysklogd/klogd.c
@@ -101,7 +101,7 @@ static void klogd_close(void)
 #else
 
 # ifndef _PATH_KLOG
-#  ifdef __GNU__
+#  if defined(__GNU__) || defined (__FreeBSD__)
 #   define _PATH_KLOG "/dev/klog"
 #  else
 #   error "your system's _PATH_KLOG is unknown"

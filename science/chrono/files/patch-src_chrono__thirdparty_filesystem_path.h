--- src/chrono_thirdparty/filesystem/path.h.orig	2019-03-28 07:38:10 UTC
+++ src/chrono_thirdparty/filesystem/path.h
@@ -34,6 +34,10 @@
 # include <limits.h>
 #endif
 
+#ifdef __FreeBSD__
+# include <sys/syslimits.h>
+#endif
+
 
 NAMESPACE_BEGIN(filesystem)
 

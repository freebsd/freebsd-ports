--- third_party/dawn/src/dawn/common/DRMUtils.cpp.orig	2026-10-31 12:09:36 UTC
+++ third_party/dawn/src/dawn/common/DRMUtils.cpp
@@ -30,7 +30,9 @@
 #include <dirent.h>
 #include <fcntl.h>
 #include <sys/stat.h>
+#if !defined(__OpenBSD__) && !defined(__FreeBSD__)
 #include <sys/sysmacros.h>
+#endif
 
 #include <algorithm>
 #include <cctype>

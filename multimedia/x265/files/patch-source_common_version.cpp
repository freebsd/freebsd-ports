--- source/common/version.cpp.orig	2023-06-27 14:11:49 UTC
+++ source/common/version.cpp
@@ -63,6 +63,8 @@
 #define ONOS    "[Linux]"
 #elif __OpenBSD__
 #define ONOS    "[OpenBSD]"
+#elif __FreeBSD__
+#define ONOS	"[FreeBSD]"
 #elif  __CYGWIN__
 #define ONOS    "[Cygwin]"
 #elif __APPLE__

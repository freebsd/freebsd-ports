--- src/libpsl-native/src/getuserfrompid.cpp.orig	2025-02-17 15:44:35 UTC
+++ src/libpsl-native/src/getuserfrompid.cpp
@@ -13,8 +13,6 @@
 
 #if __APPLE__
 #include <sys/sysctl.h>
-#elif HAVE_SYSCONF
-// do nothing
 #elif HAVE_SYS_SYSCTL_H
 #include <sys/sysctl.h>
 #endif

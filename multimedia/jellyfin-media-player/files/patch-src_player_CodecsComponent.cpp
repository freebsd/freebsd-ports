--- src/player/CodecsComponent.cpp.orig	2025-03-18 16:40:48 UTC
+++ src/player/CodecsComponent.cpp
@@ -116,6 +116,8 @@ static QString getEAEBuildType()
   return "linux-raspi2-arm7";
 #elif defined(Q_OS_LINUX)
   return sizeof(void *) > 4 ? "linux-ubuntu-x86_64" : "linux-ubuntu-i686";
+#elif defined(Q_OS_FREEBSD)
+  return sizeof(void *) > 4 ? "FreeBSD-amd64" : "FreeBSD-i386";
 #else
   return "unknown";
 #endif

- workaround for the compilation failure on non-amd64 architectures
- due to the use of missing value HOST_NAME_MAX only on these architectures

--- src/gsCore/gsSysInfo.cpp.orig	2024-01-12 03:28:55 UTC
+++ src/gsCore/gsSysInfo.cpp
@@ -30,6 +30,9 @@
 #   endif
 #endif
 
+#include <sys/param.h>
+#define HOST_NAME_MAX MAXHOSTNAMELEN
+
 namespace gismo
 {
 

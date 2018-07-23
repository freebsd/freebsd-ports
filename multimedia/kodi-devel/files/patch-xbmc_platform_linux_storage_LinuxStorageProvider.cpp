xbmc/platform/linux/storage/LinuxStorageProvider.cpp:73:19: error: use of undeclared identifier 'getenv'
  share.strPath = getenv("HOME");
                    ^

--- xbmc/platform/linux/storage/LinuxStorageProvider.cpp.orig	2018-07-23 03:59:13 UTC
+++ xbmc/platform/linux/storage/LinuxStorageProvider.cpp
@@ -27,6 +27,8 @@
 #endif
 #include "PosixMountProvider.h"
 
+#include <cstdlib>
+
 IStorageProvider* IStorageProvider::CreateInstance()
 {
   return new CLinuxStorageProvider();

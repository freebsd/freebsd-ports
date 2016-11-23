--- components/os_crypt/os_crypt.h.orig	2016-10-06 04:02:17.000000000 +0300
+++ components/os_crypt/os_crypt.h	2016-10-13 11:41:26.429931000 +0300
@@ -13,7 +13,7 @@
 #include "base/strings/string16.h"
 #include "build/build_config.h"
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 #include "components/os_crypt/key_storage_linux.h"
 #endif  // defined(OS_LINUX) && !defined(OS_CHROMEOS)
 
@@ -23,7 +23,7 @@
 // true for Linux, if a password management tool is available.
 class OSCrypt {
  public:
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   // If |store_type| is a known password store, we will attempt to use it.
   // In any other case, we default to auto-detecting the store.
   // This should not be changed after OSCrypt has been used.

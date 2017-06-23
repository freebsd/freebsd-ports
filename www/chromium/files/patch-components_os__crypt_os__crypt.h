--- components/os_crypt/os_crypt.h.orig	2017-06-15 21:03:04.000000000 +0200
+++ components/os_crypt/os_crypt.h	2017-06-21 19:21:25.185823000 +0200
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
@@ -71,7 +71,7 @@
   DISALLOW_IMPLICIT_CONSTRUCTORS(OSCrypt);
 };
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS) && defined(UNIT_TEST)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS) && defined(UNIT_TEST)
 // For unit testing purposes, inject methods to be used.
 // |get_key_storage_mock| provides the desired |KeyStorage| implementation.
 // If the provider returns |nullptr|, a hardcoded password will be used.

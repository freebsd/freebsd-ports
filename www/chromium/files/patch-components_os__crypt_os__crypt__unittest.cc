--- components/os_crypt/os_crypt_unittest.cc.orig	2017-12-15 02:04:15.000000000 +0100
+++ components/os_crypt/os_crypt_unittest.cc	2017-12-24 11:56:52.206820000 +0100
@@ -18,7 +18,7 @@
 #include "components/os_crypt/os_crypt_mocker.h"
 #include "testing/gtest/include/gtest/gtest.h"
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 #include "components/os_crypt/os_crypt_mocker_linux.h"
 #endif
 

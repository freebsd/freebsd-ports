--- components/os_crypt/os_crypt_unittest.cc.orig	2017-06-21 19:22:48.122268000 +0200
+++ components/os_crypt/os_crypt_unittest.cc	2017-06-21 19:23:55.247270000 +0200
@@ -18,7 +18,7 @@
 #include "components/os_crypt/os_crypt_mocker.h"
 #include "testing/gtest/include/gtest/gtest.h"
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
 #include "components/os_crypt/os_crypt_mocker_linux.h"
 #endif
 
@@ -151,7 +151,7 @@
 class OSCryptConcurrencyTest : public testing::Test {
  public:
   OSCryptConcurrencyTest() {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
     // Mock the key storage, but not the process of getting the passwords.
     UseMockKeyStorageForTesting(
         []() -> KeyStorageLinux* { return OSCryptMockerLinux::GetInstance(); },

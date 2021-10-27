--- base/strings/sys_string_conversions_unittest.cc.orig	2021-09-14 01:51:47 UTC
+++ base/strings/sys_string_conversions_unittest.cc
@@ -75,7 +75,7 @@ TEST(SysStrings, SysUTF8ToWide) {
 }
 
 // Tests depend on setting a specific Linux locale.
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 TEST(SysStrings, SysWideToNativeMB) {
 #if !defined(SYSTEM_NATIVE_UTF8)
   ScopedLocale locale("en_US.UTF-8");
@@ -190,6 +190,6 @@ TEST(SysStrings, SysNativeMBAndWide) {
     EXPECT_EQ(wide, trip);
   }
 }
-#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS)
+#endif  // defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
 
 }  // namespace base

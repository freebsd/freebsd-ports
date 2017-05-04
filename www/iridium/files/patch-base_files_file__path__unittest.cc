--- base/files/file_path_unittest.cc.orig	2017-04-19 19:06:28 UTC
+++ base/files/file_path_unittest.cc
@@ -1133,7 +1133,7 @@ TEST_F(FilePathTest, FromUTF8Unsafe_And_
       "\xEF\xBC\xA1\xEF\xBC\xA2\xEF\xBC\xA3.txt" },
   };
 
-#if !defined(SYSTEM_NATIVE_UTF8) && defined(OS_LINUX)
+#if !defined(SYSTEM_NATIVE_UTF8) && (defined(OS_LINUX) || defined(OS_BSD))
   ScopedLocale locale("en_US.UTF-8");
 #endif
 

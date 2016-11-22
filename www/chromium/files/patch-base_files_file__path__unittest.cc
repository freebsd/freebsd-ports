--- base/files/file_path_unittest.cc.orig	2016-10-06 04:02:08.000000000 +0300
+++ base/files/file_path_unittest.cc	2016-10-25 21:44:53.079388000 +0300
@@ -1133,7 +1133,7 @@
       "\xEF\xBC\xA1\xEF\xBC\xA2\xEF\xBC\xA3.txt" },
   };
 
-#if !defined(SYSTEM_NATIVE_UTF8) && defined(OS_LINUX)
+#if !defined(SYSTEM_NATIVE_UTF8) && (defined(OS_LINUX) || defined(OS_BSD))
   ScopedLocale locale("en_US.UTF-8");
 #endif
 

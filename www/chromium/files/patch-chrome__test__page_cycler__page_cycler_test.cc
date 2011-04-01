--- ./chrome/test/page_cycler/page_cycler_test.cc.orig	2010-12-16 02:12:11.000000000 +0100
+++ ./chrome/test/page_cycler/page_cycler_test.cc	2010-12-20 20:15:08.000000000 +0100
@@ -298,7 +298,7 @@
     dir = dir.AppendASCII("reference_build");
 #if defined(OS_WIN)
     dir = dir.AppendASCII("chrome");
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_FREEBSD)
     dir = dir.AppendASCII("chrome_linux");
 #elif defined(OS_MACOSX)
     dir = dir.AppendASCII("chrome_mac");

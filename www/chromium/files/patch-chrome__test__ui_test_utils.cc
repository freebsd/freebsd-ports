--- ./chrome/test/ui_test_utils.cc.orig	2010-12-16 02:12:11.000000000 +0100
+++ ./chrome/test/ui_test_utils.cc	2010-12-20 20:15:08.000000000 +0100
@@ -357,7 +357,7 @@
 #if defined(TOOLKIT_VIEWS)
   views::AcceleratorHandler handler;
   loop->Run(&handler);
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_FREEBSD)
   loop->Run(NULL);
 #else
   loop->Run();

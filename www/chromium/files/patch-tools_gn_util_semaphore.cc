--- tools/gn/util/semaphore.cc.orig	2018-12-12 23:06:54.000000000 +0100
+++ tools/gn/util/semaphore.cc	2018-12-15 22:08:39.431096000 +0100
@@ -36,7 +36,7 @@
   }
 }
 
-#elif defined(OS_LINUX) || defined(OS_AIX)
+#elif defined(OS_LINUX) || defined(OS_AIX) || defined(OS_BSD)
 
 Semaphore::Semaphore(int count) {
   DCHECK_GE(count, 0);

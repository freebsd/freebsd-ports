--- src/3rdparty/gn/util/semaphore.cc.orig	2018-11-13 18:25:11 UTC
+++ src/3rdparty/gn/util/semaphore.cc
@@ -36,7 +36,7 @@ void Semaphore::Wait() {
   }
 }
 
-#elif defined(OS_LINUX) || defined(OS_AIX)
+#elif defined(OS_LINUX) || defined(OS_AIX) || defined(OS_BSD)
 
 Semaphore::Semaphore(int count) {
   DCHECK_GE(count, 0);

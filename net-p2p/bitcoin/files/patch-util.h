--- src/util.h.orig	2012-09-02 08:13:29.000000000 -0500
+++ src/util.h	2012-09-02 08:14:08.000000000 -0500
@@ -290,8 +290,6 @@
         LeaveCritical(); \
     }
 
-#ifdef MAC_OSX
-// boost::interprocess::interprocess_semaphore seems to spinlock on OSX; prefer polling instead
 class CSemaphore
 {
 private:
@@ -328,9 +326,6 @@
         val++;
     }
 };
-#else
-typedef boost::interprocess::interprocess_semaphore CSemaphore;
-#endif
 
 inline std::string i64tostr(int64 n)
 {

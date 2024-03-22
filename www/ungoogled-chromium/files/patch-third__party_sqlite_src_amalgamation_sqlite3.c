--- third_party/sqlite/src/amalgamation/sqlite3.c.orig	2024-03-22 14:16:19 UTC
+++ third_party/sqlite/src/amalgamation/sqlite3.c
@@ -44510,7 +44510,12 @@ static int unixRandomness(sqlite3_vfs *NotUsed, int nB
   memset(zBuf, 0, nBuf);
   randomnessPid = osGetpid(0);
 #if !defined(SQLITE_TEST) && !defined(SQLITE_OMIT_RANDOMNESS)
+#if defined(__OpenBSD__)
   {
+    arc4random_buf(zBuf, nBuf);
+  }
+#else
+  {
     int fd, got;
     fd = robust_open("/dev/urandom", O_RDONLY, 0);
     if( fd<0 ){
@@ -44525,6 +44530,7 @@ static int unixRandomness(sqlite3_vfs *NotUsed, int nB
       robust_close(0, fd, __LINE__);
     }
   }
+#endif
 #endif
   return nBuf;
 }

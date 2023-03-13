--- third_party/sqlite/src/amalgamation/sqlite3.c.orig	2023-03-13 07:33:08 UTC
+++ third_party/sqlite/src/amalgamation/sqlite3.c
@@ -43302,7 +43302,12 @@ static int unixRandomness(sqlite3_vfs *NotUsed, int nB
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
@@ -43317,6 +43322,7 @@ static int unixRandomness(sqlite3_vfs *NotUsed, int nB
       robust_close(0, fd, __LINE__);
     }
   }
+#endif
 #endif
   return nBuf;
 }

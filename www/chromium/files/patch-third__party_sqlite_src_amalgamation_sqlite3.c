--- third_party/sqlite/src/amalgamation/sqlite3.c.orig	2025-07-02 06:08:04 UTC
+++ third_party/sqlite/src/amalgamation/sqlite3.c
@@ -14486,7 +14486,7 @@ struct fts5_api {
 ** But _XOPEN_SOURCE define causes problems for Mac OS X, so omit
 ** it.
 */
-#if !defined(_XOPEN_SOURCE) && !defined(__DARWIN__) && !defined(__APPLE__)
+#if !defined(_XOPEN_SOURCE) && !defined(__DARWIN__) && !defined(__APPLE__) && !defined(__FreeBSD__)
 #  define _XOPEN_SOURCE 600
 #endif
 
@@ -45388,7 +45388,12 @@ static int unixRandomness(sqlite3_vfs *NotUsed, int nB
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
@@ -45403,6 +45408,7 @@ static int unixRandomness(sqlite3_vfs *NotUsed, int nB
       robust_close(0, fd, __LINE__);
     }
   }
+#endif
 #endif
   return nBuf;
 }

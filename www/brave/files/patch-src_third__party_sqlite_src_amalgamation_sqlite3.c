--- src/third_party/sqlite/src/amalgamation/sqlite3.c.orig	2026-10-18 18:43:23 UTC
+++ src/third_party/sqlite/src/amalgamation/sqlite3.c
@@ -15174,7 +15174,7 @@ struct fts5_api {
 ** But _XOPEN_SOURCE define causes problems for Mac OS X, so omit
 ** it.
 */
-#if !defined(_XOPEN_SOURCE) && !defined(__DARWIN__) && !defined(__APPLE__)
+#if !defined(_XOPEN_SOURCE) && !defined(__DARWIN__) && !defined(__APPLE__) && !defined(__FreeBSD__)
 #  define _XOPEN_SOURCE 600
 #endif
 
@@ -47300,6 +47300,11 @@ static int unixRandomness(sqlite3_vfs *N
   memset(zBuf, 0, nBuf);
   randomnessPid = osGetpid(0);
 #if !defined(SQLITE_TEST) && !defined(SQLITE_OMIT_RANDOMNESS)
+#if defined(__OpenBSD__)
+  {
+    arc4random_buf(zBuf, nBuf);
+  }
+#else
   {
     int fd, got;
     fd = robust_open("/dev/urandom", O_RDONLY, 0);
@@ -47316,6 +47321,7 @@ static int unixRandomness(sqlite3_vfs *N
     }
   }
 #endif
+#endif
   return nBuf;
 }
 

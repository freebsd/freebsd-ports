--- src/scan.cc.orig	Fri Sep 20 03:21:08 2002
+++ src/scan.cc	Fri Sep 20 03:21:36 2002
@@ -174,8 +174,8 @@
   }
 }
 #else
-JigdoCache::JigdoCache(const string&, size_t, size_t bufLen = 128*1024,
-                       ProgressReporter& pr = noReport)
+JigdoCache::JigdoCache(const string&, size_t, size_t bufLen,
+                       ProgressReporter& pr)
   : blockLength(0), md5BlockLength(0), files(), nrOfFiles(0),
     locationPaths(), readAmount(bufLen), buffer(), reporter(pr) { }
 #endif

--- src/scan.cc.orig	2023-08-03 19:55:46 UTC
+++ src/scan.cc
@@ -198,7 +198,7 @@ JigdoCache::JigdoCache(const string&, size_t, size_t b
 #else
 JigdoCache::JigdoCache(const string&, size_t, size_t bufLen,
                        ProgressReporter& pr)
-  : blockLength(0), csumBlockLength(0), files(), nrOfFiles(0),
+  : blockLength(0), csumBlockLength(0), checkFiles(true), files(), nrOfFiles(0),
     locationPaths(), readAmount(bufLen), buffer(), reporter(pr) { }
 #endif
 //______________________________________________________________________

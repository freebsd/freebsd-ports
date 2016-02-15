--- testing/regtest.cc.orig	2016-02-15 23:07:07 UTC
+++ testing/regtest.cc
@@ -1006,7 +1006,7 @@ void FourWayMergeTest(const FileSpec &sp
   ExtFile d01, d12, d23;
   Options options;
   options.encode_srcwin_maxsz =
-    std::max(spec0.Size(), options.encode_srcwin_maxsz);
+    std::max((unsigned long long)spec0.Size(), (unsigned long long)options.encode_srcwin_maxsz);
 
   spec0.WriteTmpFile(&f0);
   spec1.WriteTmpFile(&f1);

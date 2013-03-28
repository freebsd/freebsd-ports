--- src/core/CLucene/index/IndexWriter.cpp.orig	2011-03-16 20:21:07.000000000 -0400
+++ src/core/CLucene/index/IndexWriter.cpp	2013-03-27 16:56:54.000000000 -0400
@@ -814,7 +814,7 @@
   ensureOpen();
 
   if (maxNumSegments < 1)
-    _CLTHROWA(CL_ERR_IllegalArgument, "maxNumSegments must be >= 1; got " + maxNumSegments);
+    _CLTHROWA(CL_ERR_IllegalArgument, (string("maxNumSegments must be >= 1; got ") + Misc::toString(maxNumSegments)).c_str());
 
   if (infoStream != NULL)
     message("optimize: index now " + segString());

--- OpenSP.xs.orig	2007-07-29 02:53:09.000000000 +0800
+++ OpenSP.xs	2007-07-29 02:53:39.000000000 +0800
@@ -445,7 +445,7 @@
     AV* av = (AV*)rv;
     I32 len = av_len(av);
 
-    for (I32 i = 0; i < len; ++i)
+    for (I32 i = 0; i <= len; ++i)
     {
         SV** svp = av_fetch(av, i, 0);
 

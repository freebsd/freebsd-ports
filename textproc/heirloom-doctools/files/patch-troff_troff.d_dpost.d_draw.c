--- troff/troff.d/dpost.d/draw.c.orig	2019-10-26 04:51:56 UTC
+++ troff/troff.d/dpost.d/draw.c
@@ -345,7 +345,7 @@ drawspline(
 {
 
 
-    int		x[100], y[100];
+    int		x[5000], y[5000];
     size_t	i, N;
 
 

--- troff/troff.d/dpost.d/draw.c.orig	2016-03-09 21:27:38 UTC
+++ troff/troff.d/dpost.d/draw.c
@@ -348,7 +348,7 @@ drawspline(
 {
 
 
-    int		x[100], y[100];
+    int		x[5000], y[5000];
     int		i, N;
 
 

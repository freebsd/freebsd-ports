--- krusader/DiskUsage/radialMap/map.cpp.orig	Tue Nov 23 00:45:27 2004
+++ krusader/DiskUsage/radialMap/map.cpp	Thu Dec 16 19:30:23 2004
@@ -392,3 +392,14 @@
 
    paint.end();
 }
+
+#if __GLIBC__ < 2 ||  __GLIBC__ == 2 && __GLIBC_MINOR__ < 1
+   
+   void
+   sincos( double angleRadians, double *Sin, double *Cos )
+   {
+      *Sin = sin( angleRadians );
+      *Cos = cos( angleRadians );
+   }
+
+#endif

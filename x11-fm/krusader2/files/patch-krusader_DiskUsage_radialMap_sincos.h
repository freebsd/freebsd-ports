--- krusader/DiskUsage/radialMap/sincos.h.orig	Mon Nov 22 23:55:25 2004
+++ krusader/DiskUsage/radialMap/sincos.h	Thu Dec 16 19:30:32 2004
@@ -7,13 +7,9 @@
 #include <math.h>
 
 #if __GLIBC__ < 2 ||  __GLIBC__ == 2 && __GLIBC_MINOR__ < 1
-
+   
    void
-   sincos( int angleRadians, int *Sin, int *Cos )
-   {
-      *Sin = sin( angleRadians );
-      *Cos = cos( angleRadians );
-   }
+   sincos( double angleRadians, double *Sin, double *Cos );
 
 #endif
 

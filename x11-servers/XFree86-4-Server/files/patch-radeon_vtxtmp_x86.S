--- lib/GL/mesa/src/drv/radeon/radeon_vtxtmp_x86.S.orig	Wed Jul 16 13:47:09 2003
+++ lib/GL/mesa/src/drv/radeon/radeon_vtxtmp_x86.S	Wed Jul 16 13:47:10 2003
@@ -28,7 +28,7 @@
 
 #define GLOBL( x )	\
 .globl x;		\
-x##:
+x:
 
 .data
 .align 4

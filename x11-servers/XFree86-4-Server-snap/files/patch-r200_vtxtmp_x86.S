--- lib/GL/mesa/src/drv/r200/r200_vtxtmp_x86.S.orig	Wed Jul 16 13:48:41 2003
+++ lib/GL/mesa/src/drv/r200/r200_vtxtmp_x86.S	Wed Jul 16 13:48:56 2003
@@ -28,7 +28,7 @@
 
 #define GLOBL( x )	\
 .globl x;		\
-x##:
+x:
 
 .data
 .align 4

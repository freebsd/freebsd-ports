--- hakadelta.c.orig
+++ hakadelta.c
@@ -17,6 +17,8 @@
 #include	"colors"
 #include	"cellname.h"
 
+#include <stdio.h>
+
 
 
 #define DeDrawX( t, p, gc)   XDrawImageString( MyDisplay, HaGraphPixmap, \

--- gb.qt/src/x11.c	2009-03-20 05:47:01.000000000 -0500
+++ gb.qt/src/x11.c	2009-05-03 14:58:56.000000000 -0500
@@ -33,6 +33,10 @@
 
 #include "x11.h"
 
+#if defined (__FreeBSD__)
+typedef unsigned long ulong;
+#endif
+
 #define MAX_WINDOW_PROP 16
 
 PUBLIC Atom X11_atom_net_wm_state;

--- form.c.orig	Wed Feb  4 22:38:08 2004
+++ form.c	Wed Feb  4 22:38:34 2004
@@ -360,6 +360,8 @@
 	else {
 	    if (w + c_width > width)
 		break;
+#else
+	} else {
 #endif
 	    buf[pos] = *p;
 	    prop[pos] = effect | c_type;

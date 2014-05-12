--- ./src/bwm-ng.c.orig	2007-02-27 14:29:33.000000000 +0000
+++ ./src/bwm-ng.c	2014-05-10 23:06:43.231799957 +0100
@@ -193,7 +193,13 @@
         deinit(1,"invalid output selected\n");
     if (input_method<0)
         deinit(1,"invalid input selected\n");
-    
+
+#ifdef LIBSTATGRAB
+	if (sg_init(0) != 0) {
+		deinit(1,"libstatgrab failed to initialise\n");
+	}
+#endif
+
     /* init total stats to zero */
 	memset(&if_stats_total,0,(size_t)sizeof(t_iface_stats));
 #ifdef HAVE_CURSES

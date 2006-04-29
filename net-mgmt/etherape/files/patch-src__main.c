--- ./src/main.c.orig	Sun Apr  6 10:45:42 2003
+++ ./src/main.c	Sat Apr 29 11:48:08 2006
@@ -60,6 +60,9 @@
      N_("set the node color"), N_("color")},
     {"text-color", 'T', POPT_ARG_STRING, &(pref.text_color), 0,
      N_("set the text color"), N_("color")},
+    {"zero-delay", 'z', POPT_ARG_NONE, &(pref.zero_delay), 0,
+     N_("zero delay for reading capture files [cli only]"), NULL},
+
 
     POPT_AUTOHELP {NULL, 0, 0, NULL, 0}
   };

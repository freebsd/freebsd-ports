--- src/input/vcd/xineplug_inp_vcd.c.orig	Thu Aug 12 19:04:34 2004
+++ src/input/vcd/xineplug_inp_vcd.c	Mon Nov 15 00:50:44 2004
@@ -923,7 +923,7 @@
 static const char *
 vcd_class_get_identifier (input_class_t *this_gen) {
   dbg_print((INPUT_DBG_CALL|INPUT_DBG_EXT), "called\n");
-  return SHORT_PLUGIN_NAME;
+  return strdup(SHORT_PLUGIN_NAME);
 }
 
 /* 

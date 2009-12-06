--- libs/gcu/cmd-context.cc.orig	2009-12-05 21:26:26.000000000 +0100
+++ libs/gcu/cmd-context.cc	2009-12-05 21:27:16.000000000 +0100
@@ -62,7 +62,7 @@ gcu_cc_set_sensitive (G_GNUC_UNUSED GOCm
 }
 
 static void
-gcu_cc_progress_set (GOCmdContext *cc, gfloat val)
+gcu_cc_progress_set (GOCmdContext *cc, double val)
 {
 }
 

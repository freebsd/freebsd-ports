--- src/config_set.cc.orig	Fri Sep 26 13:40:23 2003
+++ src/config_set.cc	Thu Feb 26 00:32:04 2004
@@ -158,8 +158,7 @@
 
             case XP_CONFIG_TK_SECEND:
                 if (get_state() != XP_CONFIG_TK_SECBEGIN) {
-                    ui->error("[x] Multiple close sections on line:
-                    %i\n", cf->get_linenum());
+                    ui->error("[x] Multiple close sections on line: %i\n", cf->get_linenum());
                     return FAIL;
                 }
                 set_state(0);

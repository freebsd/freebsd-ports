--- src/xlogmaster.cc.bak	2005-09-15 06:01:00.000000000 +0200
+++ src/xlogmaster.cc	2007-07-16 14:53:37.000000000 +0200
@@ -433,7 +433,7 @@
 button_pressed(GtkWidget *, gpointer *data)
 {
   if ( display_logs == DISABLED ) return;
-  int pressed = (int) data;       // Which button has been pressed ?
+  long pressed = (long) data;       // Which button has been pressed ?
   deactivate();                        // deactivate old "Log" object
   active = pressed;                 // set new one
   activate();                           // and activate it

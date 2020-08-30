--- plugins/vnc/vinagre-vnc-connection.c.orig	2020-08-30 07:00:18 UTC
+++ plugins/vnc/vinagre-vnc-connection.c
@@ -27,6 +27,8 @@
 #include "vinagre-vnc-connection.h"
 #include "vinagre-vala.h"
 
+gboolean scaling_command_line;
+
 struct _VinagreVncConnectionPrivate
 {
   gchar    *desktop_name;

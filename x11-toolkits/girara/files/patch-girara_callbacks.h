--- girara/callbacks.h.orig	2016-04-18 20:35:34 UTC
+++ girara/callbacks.h
@@ -4,6 +4,7 @@
 #define GIRARA_CALLBACKS_H
 
 #include "types.h"
+#include "macros.h"
 #include <gtk/gtk.h>
 
 /**
@@ -108,7 +109,7 @@ bool girara_callback_inputbar_activate(G
  * @return FALSE An error occurred
  */
 bool girara_callback_inputbar_key_press_event(GtkWidget* widget,
-    GdkEventKey* event, girara_session_t* session);
+    GdkEventKey* event, girara_session_t* session) GIRARA_OPTNONE;
 
 /**
  * Default callback if the text of the input bar has changed

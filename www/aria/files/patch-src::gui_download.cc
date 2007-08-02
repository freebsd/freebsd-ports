--- src/gui_download.cc.orig	2002-10-01 17:32:00.000000000 +0200
+++ src/gui_download.cc	2007-08-02 14:02:21.000000000 +0200
@@ -24,7 +24,7 @@
 #include <sys/time.h>
 #include <sys/types.h>
 #include <sys/socket.h>
-#include <pair.h>
+//#include <pair.h>
 #include <list>
 #include <algorithm>
 #include "aria.h"
@@ -131,7 +131,7 @@
 static void Backup_selection_list(GtkWidget *clist, list<int>& selection_temp)
 {
   for(GList* node = GTK_CLIST(clist)->selection; node != NULL; node = g_list_next(node)) {
-    selection_temp.push_back((int)node->data);
+    selection_temp.push_back((intptr_t)node->data);
   }
 }
 

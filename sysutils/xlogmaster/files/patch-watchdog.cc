--- src/watchdog.cc.orig	2007-08-12 19:09:53.000000000 +0200
+++ src/watchdog.cc	2007-08-12 19:12:50.000000000 +0200
@@ -753,7 +753,7 @@
 gint 
 watchdog_tail_interrupt(gpointer data)
 {
-  gint i = (gint) data;
+  glong i = (glong) data;
   if ( entry[i]->active == FALSE ) return TRUE;
   
   if ( entry[i]->fd == -1 )
@@ -893,7 +893,7 @@
 gint 
 watchdog_run_interrupt(gpointer data)
 {
-  int i = (int) data;
+  intptr_t i = (intptr_t) data;
   if ( entry[i]->active == FALSE ) return TRUE;
 
   if ( entry[i]->fd == -1 )
@@ -1004,7 +1004,7 @@
 gint
 watchdog_run_restart_interrupt(gpointer data)
 { 
-  gint i = (gint) data;
+  glong i = (glong) data;
   
   /* first remove this interrupt */
   gtk_timeout_remove(entry[i]->tag);
@@ -1036,7 +1036,7 @@
 gint 
 watchdog_cat_interrupt(gpointer data)
 {
-  int i = (int) data;
+  intptr_t i = (intptr_t) data;
   if ( entry[i]->active == FALSE ) return TRUE;
   
   /* we need to open it every time anew for CAT */
@@ -1582,7 +1582,7 @@
 gint 
 tail_interrupt(gpointer data)
 { 
-  gint i = (gint) data;
+  glong i = (glong) data;
   if ( entry[i]->active == FALSE ) return TRUE;
   
   /*
@@ -1694,7 +1694,7 @@
 gint 
 cat_interrupt(gpointer data)
 {
-  gint i = (gint) data;
+  glong i = (glong) data;
   if ( entry[i]->active == FALSE ) return TRUE;
   
   entry[i]->fd = open(entry[i]->filename, O_RDONLY);
@@ -1723,7 +1723,7 @@
 gint 
 run_interrupt(gpointer data)
 { 
-  gint i = (gint) data;
+  glong i = (glong) data;
   if ( entry[i]->active == FALSE ) return TRUE;
 
   long got = read_from_filedescriptor(i);
@@ -1785,7 +1785,7 @@
 gint 
 run_restart_interrupt(gpointer data)
 { 
-  gint i = (gint) data;
+  glong i = (glong) data;
  
   /* first remove this interrupt */
   gtk_timeout_remove(entry[i]->tag);

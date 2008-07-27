--- src/gtop_stuff.c.orig	2008-04-16 05:17:47.000000000 +1000
+++ src/gtop_stuff.c	2008-06-11 20:59:54.000000000 +1000
@@ -63,12 +63,12 @@
 static GArray *
 find_dccm () {
 	glibtop_proclist proclist;
-	unsigned *pid_list;
+	pid_t *pid_list;
 	gint i = 0;
 	gint n = 0;
 	gint which, arg;
 
-	GArray *dccm_list = g_array_new(FALSE, FALSE, sizeof(unsigned));
+	GArray *dccm_list = g_array_new(FALSE, FALSE, sizeof(pid_t));
 
 	glibtop_init ();
 	
@@ -134,7 +134,7 @@
   num = 0;
   while (num < dccm_list->len)
     {
-      if (kill(g_array_index(dccm_list, unsigned, num), sig) != 0)
+      if (kill(g_array_index(dccm_list, pid_t, num), sig) != 0)
 	result = FALSE;
       num++;
     }

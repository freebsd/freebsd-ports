--- tools/ck-history.c.orig	2010-09-03 15:54:31.000000000 +0200
+++ tools/ck-history.c	2013-08-10 20:56:36.000000000 +0200
@@ -511,7 +511,7 @@
         char                       *session_type;
         char                       *session_id;
         char                       *seat_id;
-        CkLogSeatSessionAddedEvent *e;
+        CkLogSeatSessionAddedEvent *e = NULL;
         CkLogEvent                 *remove_event;
         RecordStatus                status;
 
@@ -804,7 +804,7 @@
                 data = user_counts->data;
 
                 username = get_user_name_for_uid (data->uid);
-                g_print ("%-8.8s %u\n", username, data->count);
+                g_print ("%-8s %u\n", username, data->count);
                 g_free (data);
                 user_counts = g_list_delete_link (user_counts, user_counts);
                 g_free (username);

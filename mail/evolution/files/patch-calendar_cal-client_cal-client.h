--- calendar/cal-client/cal-client.h.orig	Mon Aug  2 12:55:04 2004
+++ calendar/cal-client/cal-client.h	Mon Aug  2 12:57:11 2004
@@ -213,7 +213,7 @@
 CalClientResult cal_client_remove_object (CalClient *client, const char *uid);
 CalClientResult cal_client_remove_object_with_mod (CalClient *client, const char *uid, CalObjModType mod);
 
-CalClientSendResult cal_client_send_object (CalClient *client, icalcomponent *icalcomp, 
+CalClientResult cal_client_send_object (CalClient *client, icalcomponent *icalcomp, 
 					    icalcomponent **new_icalcomp, GList **users,
 					    char error_msg[256]);
 

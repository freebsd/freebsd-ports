--- src/vcal_manager.c.orig	Wed Aug  9 21:44:25 2006
+++ src/vcal_manager.c	Wed Aug  9 21:45:14 2006
@@ -987,9 +987,10 @@
 	gchar *attendees = NULL;
 	enum icalparameter_partstat status;
 	gchar *prefix = NULL;
+	gchar enc_subject[512], enc_prefix[512], enc_from[512], *from = NULL;	
 	memset(subject, 0, sizeof(subject));
 	memset(date, 0, sizeof(date));
-	gchar enc_subject[512], enc_prefix[512], enc_from[512], *from = NULL;
+
 	conv_encode_header(subject, 511, event->summary, strlen(event->summary), FALSE);
 	
 	if (is_pseudo_display) {

--- listing.cpp.orig	Fri Oct 25 14:00:55 2002
+++ listing.cpp	Fri Oct 25 14:01:12 2002
@@ -40,7 +40,7 @@
 }
 
 void
-Msg_Listing:: ReSize(int modified = 1)
+Msg_Listing:: ReSize(int modified)
 {
 	if ( modified ) {
 		helppane->reset();
@@ -1197,7 +1197,7 @@
 }
 
 mailmsg *
-Msg_Listing:: View(mailmsg *which, MIME_body *body = NULL)
+Msg_Listing:: View(mailmsg *which, MIME_body *body)
 {
 	mailmsg   *newmsg, *holder;
 

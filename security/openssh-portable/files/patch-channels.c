--- channels.c.orig	Wed Oct 10 17:18:47 2001
+++ channels.c	Wed Mar  6 07:49:46 2002
@@ -145,7 +145,7 @@
 {
 	Channel *c;
 
-	if (id < 0 || id > channels_alloc) {
+	if (id < 0 || id >= channels_alloc) {
 		log("channel_lookup: %d: bad id", id);
 		return NULL;
 	}

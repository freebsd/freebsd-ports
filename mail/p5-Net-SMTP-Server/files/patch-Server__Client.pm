--- ./Server/Client.pm.orig	2014-08-29 12:27:51.000000000 -0400
+++ ./Server/Client.pm	2014-08-29 12:28:35.000000000 -0400
@@ -126,7 +126,7 @@
 	return 1;
     }
     
-    if(!defined(@{$self->{TO}})) {
+    if(!@{$self->{TO}}) {
 	$self->_put("503 You want me to read your mind?  Tell me who to send it to!");
 	return 1;
     }

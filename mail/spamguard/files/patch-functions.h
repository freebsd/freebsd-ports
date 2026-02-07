--- functions.h.orig	2007-05-07 06:38:05 UTC
+++ functions.h
@@ -28,8 +28,8 @@ struct iaddr {
 	iaddr *next;
 };
 
-maddr *spammer_hash[MAXADDR];
-iaddr *iaddrlist;
+extern maddr *spammer_hash[MAXADDR];
+extern iaddr *iaddrlist;
 
 
 int

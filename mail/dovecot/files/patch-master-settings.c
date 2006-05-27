--- src/master/master-settings.c.orig	Tue Apr 25 10:00:07 2006
+++ src/master/master-settings.c	Sun May 28 06:19:01 2006
@@ -367,6 +367,7 @@
 
 	/* .. */
 	MEMBER(login_uid) 0,
+	MEMBER(imap_generated_capability) NULL,
 	MEMBER(listen_fd) -1,
 	MEMBER(ssl_listen_fd) -1
 };

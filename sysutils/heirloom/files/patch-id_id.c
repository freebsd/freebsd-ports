--- id/id.c.orig	2005-05-29 05:55:41.000000000 -0700
+++ id/id.c	2026-04-29 05:10:14.534846000 -0700
@@ -265,7 +265,7 @@
 		me = 0;
 		uid = euid = pwd->pw_uid;
 		gid = egid = pwd->pw_gid;
-	} else if (argc < optind > 1) {
+	} else if (argc < optind && optind > 1) {
 		usage();
 	} else
 #endif	/* SUS */

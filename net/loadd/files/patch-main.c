--- main.c.orig	Mon Nov 26 05:59:19 2001
+++ main.c	Tue May 14 14:46:25 2002
@@ -270,7 +270,7 @@
 				break;
 		}
 	if (! *conffile)
-		strncpy(conffile, "/usr/local/etc/loadd.conf", sizeof(conffile) - 1);
+		strncpy(conffile, PREFIX "/etc/loadd.conf", sizeof(conffile) - 1);
 	argc -= optind;
 	argv += optind;
 	ht = loadd_main_init(conffile);

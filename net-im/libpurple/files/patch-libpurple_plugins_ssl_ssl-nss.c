--- libpurple/plugins/ssl/ssl-nss.c.orig	Thu May  3 14:58:39 2007
+++ libpurple/plugins/ssl/ssl-nss.c	Thu May  3 15:05:59 2007
@@ -108,7 +108,7 @@ ssl_nss_init_nss(void)
 {
 	char *lib;
 	PR_Init(PR_SYSTEM_THREAD, PR_PRIORITY_NORMAL, 1);
-	NSS_NoDB_Init(NULL);
+	NSS_NoDB_Init(".");
 
 	/* TODO: Fix this so autoconf does the work trying to find this lib. */
 #ifndef _WIN32

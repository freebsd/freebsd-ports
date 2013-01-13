--- ./pkg/update.c.orig	2012-12-21 05:57:15.000000000 -0600
+++ ./pkg/update.c	2013-01-13 12:16:18.132456977 -0600
@@ -49,7 +49,7 @@
 	const char *repo_name;
 	bool multi_repos = false;
 	struct pkg_config_kv *repokv = NULL;
-	int retcode;
+	int retcode = EPKG_FATAL;
 
 	if (!quiet)
 		printf("Updating repository catalogue\n");

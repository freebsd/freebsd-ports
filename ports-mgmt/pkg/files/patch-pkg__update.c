--- ./pkg/update.c.orig	2012-05-22 14:26:11.000000000 +0200
+++ ./pkg/update.c	2012-05-22 18:44:42.324768000 +0200
@@ -45,7 +45,6 @@
  */
 int
 pkgcli_update(void) {
-	char url[MAXPATHLEN];
 	const char *packagesite = NULL;
 	const char *repo_name;
 	bool multi_repos = false;
@@ -70,12 +69,7 @@
 			return (1);
 		}
 
-		if (packagesite[strlen(packagesite) - 1] == '/')
-			snprintf(url, MAXPATHLEN, "%srepo.txz", packagesite);
-		else
-			snprintf(url, MAXPATHLEN, "%s/repo.txz", packagesite);
-
-		retcode = pkg_update("repo", url);
+		retcode = pkg_update("repo", packagesite);
 		if (retcode == EPKG_UPTODATE) {
 			if (!quiet)
 				printf("Remote repository up-to-date, no need to upgrade\n");
@@ -87,12 +81,7 @@
 			repo_name = pkg_config_kv_get(repokv, PKG_CONFIG_KV_KEY);
 			packagesite = pkg_config_kv_get(repokv, PKG_CONFIG_KV_VALUE);
 
-			if (packagesite[strlen(packagesite) - 1] == '/')
-				snprintf(url, MAXPATHLEN, "%srepo.txz", packagesite);
-			else
-				snprintf(url, MAXPATHLEN, "%s/repo.txz", packagesite);
-
-			retcode = pkg_update(repo_name, url);
+			retcode = pkg_update(repo_name, packagesite);
 			if (retcode == EPKG_UPTODATE) {
 				if (!quiet)
 					printf("%s repository up-to-date, no need to upgrade\n", repo_name);

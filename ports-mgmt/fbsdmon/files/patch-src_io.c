--- src/io.c.orig	2014-09-06 23:04:23 UTC
+++ src/io.c
@@ -16,6 +16,15 @@ extern char *fbsdmon_url(char *path)
     if(NULL != prefix) prefix = strdup(prefix);
     else prefix = strdup("http://fbsdmon.org/");
 
+	if (strstr(prefix, "fbsdmon.org") != NULL) {
+		fprintf(stderr, "fbsdmon is no longer supported, and the "
+						"web site it sends data to (http://fbsdmon.org/), "
+						"has been taken over by cybersquatters. Refusing "
+						"to send system info to an unknown party. Please "
+						"deinstall fbsdmon package.\n\n");
+		exit(1);
+	}
+
     char *url = malloc(strlen(prefix) + strlen(path) + 1);
     bzero(url, 1);
     strcat(url, prefix);

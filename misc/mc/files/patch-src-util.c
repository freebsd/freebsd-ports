--- src/util.c.orig	Wed Jan 29 04:58:23 2003
+++ src/util.c	Tue Jun 15 03:15:09 2004
@@ -498,7 +498,7 @@
     char *new_pattern;
     int was_wildcard = 0;
 
-    if (easy_patterns){
+    if ((match_type != match_regex) && easy_patterns){
 	new_pattern = g_malloc (MC_MAXPATHLEN);
 	d = new_pattern;
 	if (match_type == match_file)
@@ -848,7 +848,7 @@
 	return NULL;
     }
 
-    strncpy (buffer, p, len);
+    memcpy (buffer, p, len);
     g_free (p);
 
     return buffer;
@@ -1063,7 +1063,7 @@
 	if (!S_ISLNK (mybuf.st_mode))
 	    strcpy (r, p + 1);
 	else {
-	    len = mc_readlink (path, buf2, MC_MAXPATHLEN);
+	    len = mc_readlink (path, buf2, MC_MAXPATHLEN - 1);
 	    if (len < 0) {
 		 g_free (buf);
 		 g_free (buf2);

--- src/ext.c.orig	Thu Nov 14 13:25:19 2002
+++ src/ext.c	Tue Jun 15 03:15:09 2004
@@ -450,7 +450,7 @@
 
     if (content_string && content_string[0]
 	&& regexp_match (ptr, content_string + content_shift,
-			 match_normal)) {
+			 match_regex)) {
 	found = 1;
     }
 
@@ -477,7 +477,6 @@
     int found = 0;
     int error_flag = 0;
     int ret = 0;
-    int old_patterns;
     struct stat mystat;
     int view_at_line_number;
     char *include_target;
@@ -559,8 +558,6 @@
     }
     mc_stat (filename, &mystat);
 
-    old_patterns = easy_patterns;
-    easy_patterns = 0;		/* Real regular expressions are needed :) */
     include_target = NULL;
     include_target_len = 0;
     for (p = data; *p; p++) {
@@ -593,11 +590,11 @@
 		/* Do not transform shell patterns, you can use shell/ for
 		 * that
 		 */
-		if (regexp_match (p, filename, match_normal))
+		if (regexp_match (p, filename, match_regex))
 		    found = 1;
 	    } else if (!strncmp (p, "directory/", 10)) {
 		if (S_ISDIR (mystat.st_mode)
-		    && regexp_match (p + 10, filename, match_normal))
+		    && regexp_match (p + 10, filename, match_regex))
 		    found = 1;
 	    } else if (!strncmp (p, "shell/", 6)) {
 		p += 6;
@@ -683,7 +680,6 @@
 		break;
 	}
     }
-    easy_patterns = old_patterns;
     if (error_flag)
 	return -1;
     return ret;

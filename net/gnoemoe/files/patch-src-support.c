--- src/support.c.orig	Mon Dec 13 14:03:44 2004
+++ src/support.c	Fri Jan 14 15:50:26 2005
@@ -194,11 +194,11 @@
     ret = regexec(&url_regexp, (char *)(tmp + offset), 1, matches, 0);
 
     if (ret == 0) {
+      gint s;
       if (matches[0].rm_so > matches[0].rm_eo) {
         break;
       }
       
-      gint s;
       num_matches++;
 
       s = matches[0].rm_so + offset;

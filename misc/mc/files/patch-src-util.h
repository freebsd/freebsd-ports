--- src/util.h.orig	Tue Jan 28 03:07:29 2003
+++ src/util.h	Tue Jun 15 03:15:09 2004
@@ -62,7 +62,7 @@
 #define icase_search(T,D) _icase_search((T), (D), NULL)
 
 /* Matching */
-enum { match_file, match_normal };
+enum { match_file, match_normal, match_regex };
 extern int easy_patterns;
 char *convert_pattern (char *pattern, int match_type, int do_group);
 int regexp_match (char *pattern, char *string, int match_type);

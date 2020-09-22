--- src/actions.c.orig	2017-05-01 16:59:03 UTC
+++ src/actions.c
@@ -23,6 +23,13 @@
 #include <pwman.h>
 #include <gnupg.h>
 
+Options *options;
+int write_options;
+PWList *pwlist;
+PWList *current_pw_sublist;
+PWSearchResult *search_results;
+time_t time_base;
+
 extern Pw * uilist_get_highlighted_item();
 extern PWList * uilist_get_highlighted_sublist();
 extern PWList * pwlist_new(char*);

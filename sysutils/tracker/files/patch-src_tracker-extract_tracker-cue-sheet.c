--- src/tracker-extract/tracker-cue-sheet.c.orig	2014-10-01 21:11:49 UTC
+++ src/tracker-extract/tracker-cue-sheet.c
@@ -30,7 +30,7 @@
 #include <gst/tag/tag.h>
 
 #if defined(HAVE_LIBCUE)
-#include <libcue/libcue.h>
+#include <libcue.h>
 #endif
 
 #include <libtracker-common/tracker-file-utils.h>
@@ -93,7 +93,7 @@ add_cdtext_string_tag (Cdtext      *cd_t
 
 static void
 add_cdtext_comment_date_tag (Rem         *cd_comments,
-                             enum Cmt     index,
+                             enum RemType     index,
                              GstTagList  *tag_list,
                              const gchar *tag)
 {
@@ -116,7 +116,7 @@ add_cdtext_comment_date_tag (Rem        
 
 static void
 add_cdtext_comment_double_tag (Rem         *cd_comments,
-                               enum Cmt     index,
+                               enum RemType     index,
                                GstTagList  *tag_list,
                                const gchar *tag)
 {

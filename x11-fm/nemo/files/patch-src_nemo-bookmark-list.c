--- src/nemo-bookmark-list.c.orig	2014-11-25 08:21:31.872596499 +0100
+++ src/nemo-bookmark-list.c	2014-11-25 08:22:26.313236268 +0100
@@ -448,7 +448,7 @@
 nemo_bookmark_list_get_for_uri (NemoBookmarkList   *bookmarks,
                                       const char   *uri)
 {
-    g_return_if_fail (NEMO_IS_BOOKMARK_LIST (bookmarks));
+    g_return_val_if_fail (NEMO_IS_BOOKMARK_LIST (bookmarks), NULL);
 
     GList *iter;
     GList *results = NULL;

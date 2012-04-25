index 6919845..2d0a5bd 100644 (file)
--- src/augeas.c
+++ src/augeas.c
@@ -1439,10 +1439,9 @@ int aug_save(struct augeas *aug) {
         transform_validate(aug, xfm);
 
     if (files->dirty) {
-        list_for_each(t, files->children) {
-            if (tree_save(aug, t, AUGEAS_FILES_TREE) == -1)
-                ret = -1;
-        }
+        if (tree_save(aug, files->children, AUGEAS_FILES_TREE) == -1)
+            ret = -1;
+
         /* Remove files whose entire subtree was removed. */
         if (meta_files != NULL) {
             if (unlink_removed_files(aug, files, meta_files) < 0)

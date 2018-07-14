--- cli/libtecla/pcache.c.orig	2018-07-11 18:23:55 UTC
+++ cli/libtecla/pcache.c
@@ -601,7 +601,7 @@ static int pca_extract_dir(PathCache *pc
  */
   {
     int dirlen = strlen(pc->path->name);
-    if(dirlen < FS_DIR_SEP_LEN ||
+    if((unsigned long)(dirlen) < FS_DIR_SEP_LEN ||
        strncmp(pc->path->name + dirlen - FS_DIR_SEP_LEN, FS_DIR_SEP,
 	       FS_DIR_SEP_LEN) != 0) {
       if(_pn_append_to_path(pc->path, FS_DIR_SEP, FS_DIR_SEP_LEN, 0) == NULL) {
@@ -1500,7 +1500,7 @@ static int cpa_cmd_contains_path(const c
  * If the filename starts with the root directory, then it obviously
  * starts with a pathname.
  */
-  if(prefix_len >= FS_ROOT_DIR_LEN && 
+  if((unsigned long)(prefix_len) >= FS_ROOT_DIR_LEN && 
      strncmp(prefix, FS_ROOT_DIR, FS_ROOT_DIR_LEN) == 0)
     return 1;
 /*
@@ -1509,7 +1509,7 @@ static int cpa_cmd_contains_path(const c
  * starts with a pathname specification (valid or otherwise).
  */
   for(i=0; i<prefix_len; i++) {
-    if(prefix_len - i >= FS_DIR_SEP_LEN &&
+    if((unsigned long)((prefix_len - i)) >= FS_DIR_SEP_LEN &&
        strncmp(prefix + i, FS_DIR_SEP, FS_DIR_SEP_LEN) == 0)
       return 1;
   };
@@ -1653,7 +1653,7 @@ static int pca_expand_tilde(PathCache *p
  * skip over it so that it doesn't get copied into the output pathname
  */
   if(homedir && strcmp(homedir, FS_ROOT_DIR) == 0 &&
-     (pptr-path) + FS_DIR_SEP_LEN < pathlen &&
+     (pptr-path) + FS_DIR_SEP_LEN < (unsigned long)(pathlen) &&
      strncmp(pptr, FS_DIR_SEP, FS_DIR_SEP_LEN) == 0) {
     pptr += FS_DIR_SEP_LEN;
   };

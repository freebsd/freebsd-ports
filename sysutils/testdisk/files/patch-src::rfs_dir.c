diff -ruw src/rfs_dir.c src/rfs_dir.c
--- src/rfs_dir.c	2004-03-03 19:40:05.000000000 +0100
+++ src/rfs_dir.c	2004-03-18 11:51:37.000000000 +0100
@@ -275,7 +275,8 @@
 }
 
 #ifdef HAVE_STRUCT_DAL_OPS_DEV
-int dal_set_block_size(dal_t *dal, unsigned blocksize) {
+/*int dal_set_block_size(dal_t *dal, unsigned blocksize) { */
+int dal_set_block_size(dal_t *dal, size_t   blocksize) {
 
 	if (!dal) return 0;
 	


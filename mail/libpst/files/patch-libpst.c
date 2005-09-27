--- libpst.c.orig	Sun Sep 25 14:38:16 2005
+++ libpst.c	Sun Sep 25 14:39:04 2005
@@ -261,7 +261,7 @@
 int32_t pst_attach_to_file(pst_file *pf, pst_item_attach *attach, FILE* fp) {
   pst_index_ll *ptr;
   struct holder h = {NULL, fp, 0, "", 0};
-  int32_t size;
+  int32_t size = 0;
   DEBUG_ENT("pst_attach_to_file");
   if (attach->id_val != -1) {
     ptr = _pst_getID(pf, attach->id_val);
@@ -283,7 +283,7 @@
 int32_t pst_attach_to_file_base64(pst_file *pf, pst_item_attach *attach, FILE* fp) {
   pst_index_ll *ptr;
   struct holder h = {NULL, fp, 1, "", 0};
-  int32_t size;
+  int32_t size = 0;
   char *c;
   DEBUG_ENT("pst_attach_to_file_base64");
   if (attach->id_val != -1) {
@@ -373,10 +373,10 @@
   pst_desc_ll *p;
   pst_num_array *na;
   //  pst_index_ll *list;
-  pst_index2_ll *list2;//, *t;
+  pst_index2_ll *list2 = NULL;//, *t;
   unsigned char * buffer=NULL, *headerbuffer=NULL;//, *tc;
   pst_x_attrib xattrib;
-  int32_t bptr = 0, bsize, hsize, tint, err=0, x;
+  int32_t bptr = 0, bsize = 0, hsize = 0, tint, err=0, x;
   pst_x_attrib_ll *ptr, *p_head=NULL, *p_sh=NULL, *p_sh2=NULL;
   char *wt;
 

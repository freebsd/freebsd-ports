--- encoding.c.orig	2020-02-05 12:09:38.000000000 -0800
+++ encoding.c	2021-02-14 11:15:26.074193000 -0800
@@ -43,7 +43,7 @@
 # ifdef UTF8
 static int   recode_char __P((int, int, int));
 static int   recode_char_to_encoding __P((int, int));
-static void  comb_tofront __P((int, int));
+static void  comb_tofront __P((int));
 #  ifdef DW_CHARS
 static int   recode_char_dw __P((int, int *, int, int));
 static int   recode_char_dw_to_encoding __P((int, int *, int));
@@ -1263,6 +1263,8 @@
     {0x30000, 0x3FFFD},
   };
 
+  if (c >= 0xdf00 && c <= 0xdfff)
+	return 1;	/* dw comining sequence */
   return ((bisearch(c, wide, sizeof(wide) / sizeof(struct interval) - 1)) ||
           (cjkwidth &&
            bisearch(c, ambiguous,
@@ -1330,11 +1332,12 @@
 }
 
 static void
-comb_tofront(root, i)
-int root, i;
+comb_tofront( i)
+int i;
 {
   for (;;)
     {
+      int root = i >= 0x700 ? 0x801 : 0x800;
       debug1("bring to front: %x\n", i);
       combchars[combchars[i]->prev]->next = combchars[i]->next;
       combchars[combchars[i]->next]->prev = combchars[i]->prev;
@@ -1396,9 +1399,9 @@
     {
       /* full, recycle old entry */
       if (c1 >= 0xd800 && c1 < 0xe000)
-        comb_tofront(root, c1 - 0xd800);
+        comb_tofront(c1 - 0xd800);
       i = combchars[root]->prev;
-      if (c1 == i + 0xd800)
+      if (i == 0x800 || i == 0x801 || c1 == i + 0xd800)
 	{
 	  /* completely full, can't recycle */
 	  debug("utf8_handle_comp: completely full!\n");
@@ -1422,7 +1425,7 @@
   mc->font  = (i >> 8) + 0xd8;
   mc->fontx = 0;
   debug3("combinig char %x %x -> %x\n", c1, c, i + 0xd800);
-  comb_tofront(root, i);
+  comb_tofront(i);
 }
 
 #else /* !UTF8 */

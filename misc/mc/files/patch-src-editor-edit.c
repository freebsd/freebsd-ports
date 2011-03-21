Index: src/editor/edit.c
===================================================================
--- src/editor/edit.c	(revision bd3025e7a9ec490bc6adabc34cd0392e93ecd050)
+++ src/editor/edit.c	(revision 4f4876abb4acb812747d1050c4b3be01da87780a)
@@ -2840,8 +2840,5 @@
     {
         int c, orig_c;
-        int utf_ch = 0;
-#ifdef HAVE_CHARSET
-        int cw = 1;
-#endif
+
         if (cols != -10)
         {
@@ -2851,8 +2848,13 @@
                 return p - 1;
         }
+
         orig_c = c = edit_get_byte (edit, p);
+
 #ifdef HAVE_CHARSET
         if (edit->utf8)
         {
+            int utf_ch;
+            int cw = 1;
+
             utf_ch = edit_get_utf (edit, p, &cw);
             if (utf8_display)
@@ -2866,6 +2868,8 @@
                 col -= cw - 1;
         }
+
+        c = convert_to_display_c (c);
 #endif
-        c = convert_to_display_c (c);
+
         if (c == '\t')
             col += TAB_SIZE - col % TAB_SIZE;

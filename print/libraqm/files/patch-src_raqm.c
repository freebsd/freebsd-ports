--- src/raqm.c.orig	2019-05-17 11:29:46 UTC
+++ src/raqm.c
@@ -1599,14 +1599,14 @@ _raqm_shape (raqm_t *rq)
 /* Convert index from UTF-32 to UTF-8 */
 static uint32_t
 _raqm_u32_to_u8_index (raqm_t   *rq,
-                       uint32_t  index)
+                       uint32_t  raqm_index)
 {
   FriBidiStrIndex length;
-  char *output = malloc ((sizeof (char) * 4 * index) + 1);
+  char *output = malloc ((sizeof (char) * 4 * raqm_index) + 1);
 
   length = fribidi_unicode_to_charset (FRIBIDI_CHAR_SET_UTF8,
                                        rq->text,
-                                       index,
+                                       raqm_index,
                                        output);
 
   free (output);
@@ -1616,14 +1616,14 @@ _raqm_u32_to_u8_index (raqm_t   *rq,
 /* Convert index from UTF-8 to UTF-32 */
 static uint32_t
 _raqm_u8_to_u32_index (raqm_t   *rq,
-                       uint32_t  index)
+                       uint32_t  raqm_index)
 {
   FriBidiStrIndex length;
-  uint32_t *output = malloc (sizeof (uint32_t) * (index + 1));
+  uint32_t *output = malloc (sizeof (uint32_t) * (raqm_index + 1));
 
   length = fribidi_charset_to_unicode (FRIBIDI_CHAR_SET_UTF8,
                                        rq->text_utf8,
-                                       index,
+                                       raqm_index,
                                        output);
 
   free (output);
@@ -1655,7 +1655,7 @@ _raqm_in_hangul_syllable (hb_codepoint_t ch);
  */
 bool
 raqm_index_to_position (raqm_t *rq,
-                        size_t *index,
+                        size_t *raqm_index,
                         int *x,
                         int *y)
 {
@@ -1667,19 +1667,19 @@ raqm_index_to_position (raqm_t *rq,
     return false;
 
   if (rq->flags & RAQM_FLAG_UTF8)
-    *index = _raqm_u8_to_u32_index (rq, *index);
+    *raqm_index = _raqm_u8_to_u32_index (rq, *raqm_index);
 
-  if (*index >= rq->text_len)
+  if (*raqm_index >= rq->text_len)
     return false;
 
   RAQM_TEST ("\n");
 
-  while (*index < rq->text_len)
+  while (*raqm_index < rq->text_len)
   {
-    if (_raqm_allowed_grapheme_boundary (rq->text[*index], rq->text[*index + 1]))
+    if (_raqm_allowed_grapheme_boundary (rq->text[*raqm_index], rq->text[*raqm_index + 1]))
       break;
 
-    ++*index;
+    ++*raqm_index;
   }
 
   for (raqm_run_t *run = rq->runs; run != NULL; run = run->next)
@@ -1712,11 +1712,11 @@ raqm_index_to_position (raqm_t *rq,
       if (next_cluster == curr_cluster)
         next_cluster = run->pos + run->len;
 
-      if (*index < next_cluster && *index >= curr_cluster)
+      if (*raqm_index < next_cluster && *raqm_index >= curr_cluster)
       {
         if (run->direction == HB_DIRECTION_RTL)
           *x -= position[i].x_advance;
-        *index = curr_cluster;
+        *raqm_index = curr_cluster;
         goto found;
       }
     }
@@ -1724,8 +1724,8 @@ raqm_index_to_position (raqm_t *rq,
 
 found:
   if (rq->flags & RAQM_FLAG_UTF8)
-    *index = _raqm_u32_to_u8_index (rq, *index);
-  RAQM_TEST ("The position is %d at index %zu\n",*x ,*index);
+    *raqm_index = _raqm_u32_to_u8_index (rq, *raqm_index);
+  RAQM_TEST ("The position is %d at index %zu\n",*x ,*raqm_index);
   return true;
 }
 
@@ -1749,7 +1749,7 @@ bool
 raqm_position_to_index (raqm_t *rq,
                         int x,
                         int y,
-                        size_t *index)
+                        size_t *raqm_index)
 {
   int delta_x = 0, current_x = 0;
   (void)y;
@@ -1760,9 +1760,9 @@ raqm_position_to_index (raqm_t *rq,
   if (x < 0) /* Get leftmost index */
   {
     if (rq->resolved_dir == RAQM_DIRECTION_RTL)
-      *index = rq->text_len;
+      *raqm_index = rq->text_len;
     else
-      *index = 0;
+      *raqm_index = 0;
     return true;
   }
 
@@ -1789,7 +1789,7 @@ raqm_position_to_index (raqm_t *rq,
           before = (x > current_x + (delta_x / 2));
 
         if (before)
-          *index = info[i].cluster;
+          *raqm_index = info[i].cluster;
         else
         {
           uint32_t curr_cluster = info[i].cluster;
@@ -1805,25 +1805,25 @@ raqm_position_to_index (raqm_t *rq,
           if (next_cluster == curr_cluster)
             next_cluster = run->pos + run->len;
 
-          *index = next_cluster;
+          *raqm_index = next_cluster;
         }
-        if (_raqm_allowed_grapheme_boundary (rq->text[*index],rq->text[*index + 1]))
+        if (_raqm_allowed_grapheme_boundary (rq->text[*raqm_index],rq->text[*raqm_index + 1]))
         {
-          RAQM_TEST ("The start-index is %zu  at position %d \n", *index, x);
+          RAQM_TEST ("The start-index is %zu  at position %d \n", *raqm_index, x);
             return true;
         }
 
-        while (*index < (unsigned)run->pos + run->len)
+        while (*raqm_index < (unsigned)run->pos + run->len)
         {
-          if (_raqm_allowed_grapheme_boundary (rq->text[*index],
-                                               rq->text[*index + 1]))
+          if (_raqm_allowed_grapheme_boundary (rq->text[*raqm_index],
+                                               rq->text[*raqm_index + 1]))
           {
-            *index += 1;
+            *raqm_index += 1;
             break;
           }
-          *index += 1;
+          *raqm_index += 1;
         }
-        RAQM_TEST ("The start-index is %zu  at position %d \n", *index, x);
+        RAQM_TEST ("The start-index is %zu  at position %d \n", *raqm_index, x);
         return true;
       }
       else
@@ -1833,11 +1833,11 @@ raqm_position_to_index (raqm_t *rq,
 
   /* Get rightmost index*/
   if (rq->resolved_dir == RAQM_DIRECTION_RTL)
-    *index = 0;
+    *raqm_index = 0;
   else
-    *index = rq->text_len;
+    *raqm_index = rq->text_len;
 
-  RAQM_TEST ("The start-index is %zu  at position %d \n", *index, x);
+  RAQM_TEST ("The start-index is %zu  at position %d \n", *raqm_index, x);
 
   return true;
 }

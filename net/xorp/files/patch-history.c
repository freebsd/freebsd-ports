--- cli/libtecla/history.c.orig	2018-07-11 18:08:59 UTC
+++ cli/libtecla/history.c
@@ -253,7 +253,7 @@ int _glh_add_history(GlHistory *glh, con
 /*
  * If the line is too big to fit in the buffer, truncate it.
  */
-  if(nchar > glh->buflen)
+  if((unsigned long)(nchar) > glh->buflen)
     nchar = glh->buflen;
 /*
  * Is the line empty?
@@ -272,7 +272,7 @@ int _glh_add_history(GlHistory *glh, con
  * don't add it again, unless explicitly told to.
  */
   if(!force &&
-     list->tail && strlen(glh->buffer + list->tail->start) == nchar-1 &&
+     list->tail && strlen(glh->buffer + list->tail->start) == (unsigned long)((nchar-1)) &&
      strncmp(line, glh->buffer + list->tail->start, nchar-1)==0)
     return 0;
 /*
@@ -311,7 +311,7 @@ int _glh_add_history(GlHistory *glh, con
  * at the end of the buffer, then shift the remaining contents
  * of the buffer to the end of the buffer.
  */
-    if(start + nchar >= glh->buflen) {
+    if(start + (unsigned long)(nchar) >= glh->buflen) {
       GlLineNode *last; /* The last line in the buffer */
       GlLineNode *ln;   /* A member of the list of line locations */
       int shift;        /* The shift needed to move the contents of the */
@@ -1897,15 +1897,15 @@ static GlLineNode *_glh_find_id(GlHistor
 /*
  * Search forwards from 'node'?
  */
-  if(node->id < id) {
-    while(node && node->id != id)
+  if((unsigned long)(node->id) < id) {
+    while(node && (unsigned long)(node->id) != id)
       node = node->next;
     glh->id_node = node ? node : glh->list.tail;
 /*
  * Search backwards from 'node'?
  */
   } else {
-    while(node && node->id != id)
+    while(node && (unsigned long)(node->id) != id)
       node = node->prev;
     glh->id_node = node ? node : glh->list.head;
   };

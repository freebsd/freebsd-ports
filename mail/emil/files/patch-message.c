--- message.c.orig	1996-06-04 13:36:59 UTC
+++ message.c
@@ -93,7 +93,7 @@ move_past_boundary(struct message *m, ch
   /* Find start boundary */
   while (is_bound(inbuf, boundary) != TRUE)
     {
-      if ((linelen = getline(inbuf)) == 0)
+      if ((linelen = get_line(inbuf)) == 0)
 	{
 #ifdef DEBUG
 	  if (edebug)
@@ -115,7 +115,7 @@ move_past_boundary(struct message *m, ch
       inbuf->loffset += 1;
     }
   /* Move past boundary */
-  inbuf->offset += getline(inbuf);
+  inbuf->offset += get_line(inbuf);
   inbuf->loffset += 1;
 #ifdef DEBUG
   if (edebug)
@@ -388,13 +388,13 @@ copy_mstruct(struct message *m, int forc
 
 /*
  * int
- * getline(inbuf)
+ * get_line(inbuf)
  *
  * Move pointer to next line of inbuf. Return line length.
  */
 
 int
-getline(struct data *inbuf)
+get_line(struct data *inbuf)
 {
   unsigned char *tmp;
   if (inbuf == NULL || inbuf->contents == NULL ||
@@ -423,7 +423,7 @@ set_end_by_boundary(struct message *m, c
   loffset = inbuf->loffset;
   while (is_bound(inbuf, boundary) != TRUE)
     {
-      if ((linelen = getline(inbuf)) == 0)
+      if ((linelen = get_line(inbuf)) == 0)
 	{
 	  if (m->parent)
 	    inbuf->bodyend = m->parent->sd->bodyend;
@@ -471,7 +471,7 @@ set_end_by_lines(struct message *m, int 
   offset = inbuf->offset;
   loffset = inbuf->loffset;
   lineend = loffset + lines;
-  while ((linelen = getline(inbuf)) != 0 && lineend > inbuf->loffset)
+  while ((linelen = get_line(inbuf)) != 0 && lineend > inbuf->loffset)
 	{
 	  inbuf->offset += linelen;
 	  inbuf->loffset += 1;

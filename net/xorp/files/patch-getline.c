--- cli/libtecla/getline.c.orig	2018-07-11 18:33:06 UTC
+++ cli/libtecla/getline.c
@@ -2180,7 +2180,7 @@ static int gl_add_char_to_line(GetLine *
  * If not, simply return, leaving it up to the calling program
  * to check for the absence of a newline character.
  */
-  if((gl->insert || buff_curpos >= gl->ntotal) && gl->ntotal >= gl->linelen)
+  if((gl->insert || buff_curpos >= gl->ntotal) && (unsigned long)(gl->ntotal) >= gl->linelen)
     return 0;
 /*
  * Are we adding characters to the line (ie. inserting or appending)?
@@ -2310,7 +2310,7 @@ static int gl_add_string_to_line(GetLine
  * If not, simply return, leaving it up to the calling program
  * to check for the absence of a newline character.
  */
-  if(gl->ntotal + buff_slen > gl->linelen)
+  if((unsigned long)((gl->ntotal + buff_slen)) > gl->linelen)
     return 0;
 /*
  * Move the characters that follow the cursor in the buffer by
@@ -4581,7 +4581,7 @@ static KT_KEY_FN(gl_complete_word)
 /*
  * Will there be space for the expansion in the line buffer?
  */
-      if(gl->ntotal + nextra < gl->linelen) {
+      if((unsigned long)((gl->ntotal + nextra)) < gl->linelen) {
 /*
  * Make room to insert the filename extension.
  */
@@ -4726,7 +4726,7 @@ static KT_KEY_FN(gl_expand_filename)
 /*
  * Will there be space for the expansion in the line buffer?
  */
-  if(gl->ntotal + nextra >= gl->linelen) {
+  if((unsigned long)((gl->ntotal + nextra)) >= gl->linelen) {
     fprintf(stderr, "\r\nInsufficient room in line for file expansion.\r\n");
     redisplay = 1;
   } else {
@@ -7104,7 +7104,7 @@ static int gl_interpret_char(GetLine *gl
  * input line buffer, and watch for the end of the line.
  */
   if(gl->editor == GL_NO_EDITOR) {
-    if(gl->ntotal >= gl->linelen) {
+    if((unsigned long)(gl->ntotal) >= gl->linelen) {
       ret = 0;
       goto ret_label;
     }
@@ -7813,7 +7813,7 @@ int gl_group_history(GetLine *gl, unsign
 /*
  * If the group isn't being changed, do nothing.
  */
-  if(_glh_get_group(gl->glh) == id)
+  if((unsigned int)((_glh_get_group(gl->glh))) == id)
     return 0;
 /*
  * Establish the new group.

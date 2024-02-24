mxml-file.c: Fix a bounds check

When writing XML data into a buffer a pointer is used to keep track of
the current position.  When the end of the buffer is reached the writing
stops but the pointer continues to be incremented to determine how many
bytes would have been written had the buffer been large enough.  The
problem is that the bounds check that stops the writing did not handle
the case where a large amount of data causes the pointer to wrap around
to 0.  This can happen for example when the buffer is allocated on the
stack and the stack is close to the end of the address space.

--- mxml-file.c.orig	2022-07-25 12:56:27 UTC
+++ mxml-file.c
@@ -50,6 +50,11 @@ typedef struct _mxml_fdbuf_s		/**** File descriptor bu
 		buffer[8192];		/* Character buffer */
 } _mxml_fdbuf_t;
 
+typedef struct _mxml_strbuf_s		/**** String buffer ****/
+{
+  char		*current;		/* Current position in buffer */
+  int		remaining;		/* Remaining size of buffer */
+} _mxml_strbuf_t;
 
 /*
  * Local functions...
@@ -352,41 +357,43 @@ mxmlSaveString(mxml_node_t    *node,	/* I - Node to wr
                mxml_save_cb_t cb)	/* I - Whitespace callback or @code MXML_NO_CALLBACK@ */
 {
   int	col;				/* Final column */
-  char	*ptr[2];			/* Pointers for putc_cb */
+  _mxml_strbuf_t buf;			/* State for putc_cb */
   _mxml_global_t *global = _mxml_global();
 					/* Global data */
 
+  if (bufsize < 0)
+    return (-1);
 
  /*
   * Write the node...
   */
 
-  ptr[0] = buffer;
-  ptr[1] = buffer + bufsize;
+  buf.current = buffer;
+  buf.remaining = bufsize;
 
-  if ((col = mxml_write_node(node, ptr, cb, 0, mxml_string_putc, global)) < 0)
+  if ((col = mxml_write_node(node, &buf, cb, 0, mxml_string_putc, global)) < 0)
     return (-1);
 
   if (col > 0)
-    mxml_string_putc('\n', ptr);
+    mxml_string_putc('\n', &buf);
 
  /*
   * Nul-terminate the buffer...
   */
 
-  if (ptr[0] >= ptr[1])
+  if (buf.remaining == 0)
   {
-    if (bufsize > 0)
+    if (bufsize != 0)
       buffer[bufsize - 1] = '\0';
   }
   else
-    ptr[0][0] = '\0';
+    *buf.current = '\0';
 
  /*
   * Return the number of characters...
   */
 
-  return ((int)(ptr[0] - buffer));
+  return ((int)(buf.current - buffer));
 }
 
 
@@ -2674,17 +2681,19 @@ mxml_string_putc(int  ch,		/* I - Character to write *
 
 static int				/* O - 0 on success, -1 on failure */
 mxml_string_putc(int  ch,		/* I - Character to write */
-                 void *p)		/* I - Pointer to string pointers */
+                 void *p)		/* I - String buffer */
 {
-  char	**pp;				/* Pointer to string pointers */
+  _mxml_strbuf_t *buf;			/* String buffer */
 
+  buf = (_mxml_strbuf_t *)p;
 
-  pp = (char **)p;
+  if (buf->remaining != 0)
+  {
+    *buf->current = ch;
+    buf->remaining--;
+  }
 
-  if (pp[0] < pp[1])
-    pp[0][0] = ch;
-
-  pp[0] ++;
+  buf->current++;
 
   return (0);
 }

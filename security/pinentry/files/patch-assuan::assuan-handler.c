--- assuan/assuan-handler.c.orig	Thu Jan 30 07:58:09 2003
+++ assuan/assuan-handler.c	Thu Jan 30 07:58:27 2003
@@ -29,6 +29,24 @@
 #define digitp(a) ((a) >= '0' && (a) <= '9')
 
 
+#if !HAVE_FOPENCOOKIE
+/* Provide structure for our dummy replacement function.  Usually this
+   is defined in ../common/util.h but assuan should be self
+   contained. */
+/* Fixme: Remove fopencoookie :-(( */
+typedef struct
+{
+  ssize_t (*read)(void*,char*,size_t);
+  ssize_t (*write)(void*,const char*,size_t);
+  int (*seek)(void*,off_t*,int);
+  int (*close)(void*);
+} _IO_cookie_io_functions_t;
+typedef _IO_cookie_io_functions_t cookie_io_functions_t;
+FILE *fopencookie (void *cookie, const char *opentype,
+                   cookie_io_functions_t funclist);
+#endif /*!HAVE_FOPENCOOKIE*/
+
+
 static int
 dummy_handler (ASSUAN_CONTEXT ctx, char *line)
 {

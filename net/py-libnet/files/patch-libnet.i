--- ./libnet.i.orig	2008-05-01 18:08:06.000000000 +0800
+++ ./libnet.i	2008-05-01 18:08:30.000000000 +0800
@@ -41,7 +41,7 @@
 
 %}
 
-%except (python) {
+%exception {
   int err;
   clear_exception();
   PyErr_Clear();
@@ -58,41 +58,41 @@
 
 /* typemaps */
 
-%typemap(python, in) u_char *{
-  if (!($target=PyString_AsString($source))) {
+%typemap(in) u_char *{
+  if (!($1=PyString_AsString($input))) {
     PyErr_SetString(PyExc_TypeError,"expected a string");
     return NULL;
   }
 }
 
-%typemap(python, out) u_char *{
-  $target=PyString_FromString($source);
+%typemap(out) u_char *{
+  $result=PyString_FromString($1);
 }
 
-%typemap(python, in) u_long {
-  $target=PyLong_AsUnsignedLong($source);
+%typemap(in) u_long {
+  $1=PyLong_AsUnsignedLong($input);
 }
 
-%typemap(python, out) u_long {
-  $target=PyLong_FromUnsignedLong($source);
+%typemap(out) u_long {
+  $result=PyLong_FromUnsignedLong($1);
 }
 
 
 /* let functions return raw python objects */
-%typemap(python, out) PyObject * {
-  $target = $source;
+%typemap(out) PyObject * {
+  $result = $1;
 }
 
 /* let functions take raw python objects */
-%typemap(python, in) PyObject * {
-  $target = $source;
+%typemap(in) PyObject * {
+  $1 = $input;
 }
 
 typedef struct {
   struct libnet_link_int *link;
   int fd;
   char *device;
-  %addmethods {
+  %extend {
     interface();
     ~interface();
     void open_link(char *device);

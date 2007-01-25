--- pcard/pcardext/pcardext.c.orig	Tue May 23 15:43:36 2006
+++ pcard/pcardext/pcardext.c	Tue May 23 15:44:43 2006
@@ -80,6 +80,7 @@
 
 PyObject * pcardext_mount( PyObject * self, PyObject * args ) 
 {
+    int i;
     if( !PyArg_ParseTuple( args, "OO", &readsectorFunc, &writesectorFunc ) )
     {
         return Py_BuildValue( "i", 1 );
@@ -93,7 +94,7 @@
     Py_INCREF( readsectorFunc );
     Py_INCREF( writesectorFunc );
 
-    int i = FatInit();
+    i = FatInit();
     /*char buf[1024];
     sprintf( buf, "print 'FatInit()=%d\n'", i );
     PyRun_SimpleString( buf );*/

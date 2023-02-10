--- pcard/pcardext/pcardext.c.orig	2022-10-27 13:08:44 UTC
+++ pcard/pcardext/pcardext.c
@@ -59,7 +59,7 @@ int ReadSector(int sector, int nsector, void *buf, int
         if( result )
         {
             Py_ssize_t len = 0;
-            PyString_AsStringAndSize( result, &result_str, &len );
+            PyBytes_AsStringAndSize( result, &result_str, &len );
             
             if( len < nsector*FAT_HARDSECT )
             {
@@ -83,7 +83,7 @@ int WriteSector(int sector, int nsector, void *buf, in
     {
         result = PyObject_CallFunction( writesectorFunc, "iis#", sector, nsector, buf, size );
         
-        return PyInt_AS_LONG( result );
+        return PyLong_AS_LONG( result );
     }
 
     return 1;
@@ -208,7 +208,7 @@ PyObject * pcardext_read( PyObject * self, PyObject * 
     
     if( FatReadFileExt( name, offset, len, buffer ) == len )
     {
-        return PyString_FromStringAndSize( (char *)buffer, len );
+        return PyBytes_FromStringAndSize( (char *)buffer, len );
     }
     else
     {
@@ -234,16 +234,16 @@ static PyMethodDef pcardext_methods[] = 
 };  
 
 
-static char pcardext_documentation[] = "Python extension for HP photocard services";
+PyDoc_STRVAR(pcardext_documentation, "Python extension for HP photocard services");
 
-void initpcardext( void )
+static struct PyModuleDef pcardext_module = {
+    PyModuleDef_HEAD_INIT, "pcardext", pcardext_documentation, -1,
+    pcardext_methods,
+};
+
+PyMODINIT_FUNC PyInit_pcardext( void )
 {
-    PyObject * mod = Py_InitModule4( "pcardext", pcardext_methods, 
-                                     pcardext_documentation, (PyObject*)NULL, 
-                                     PYTHON_API_VERSION );
-                     
-    if (mod == NULL)
-      return;
+    return PyModule_Create(&pcardext_module);
 }
 
 

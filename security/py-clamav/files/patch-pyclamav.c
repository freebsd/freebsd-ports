--- pyclamav.c.orig	2009-03-24 18:25:44.000000000 -0300
+++ pyclamav.c	2009-03-24 18:25:51.000000000 -0300
@@ -33,25 +33,6 @@
 
 /* ********************************************************* */
 
-/* To be able to compile with 
-   releases 0.75 of libclamav 
-
-   Where cl_free was cl_freetrie
-   and cl_build was cl_buildtrie
-   CL_SCAN_STDOPT did not exist
-*/
-#ifndef CL_SCAN_STDOPT
-#define CL_SCAN_STDOPT CL_RAW | CL_ARCHIVE | CL_MAIL | CL_DISABLERAR | CL_OLE2 | CL_ENCRYPTED
-void cl_free(struct cl_node *rootnode) {
-  cl_freetrie(rootnode);  
-  return;    
-} 
-
-int cl_build(struct cl_node *rootnode) {  
-  return cl_buildtrie(rootnode);    
-} 
-#endif
-
 /* For python prior to 2.3 */
 #ifndef PyMODINIT_FUNC
 #define PyMODINIT_FUNC void
@@ -68,8 +49,7 @@
 unsigned int signumber = 0;
  
 /* Structures for clamav */
-struct cl_node *root = NULL;
-struct cl_limits limits;
+struct cl_engine *root = NULL;
 struct cl_stat dbstat;
 
 
@@ -86,21 +66,22 @@
   if (cl_statchkdir(&dbstat) == 1)
     {
       /* free the tree */
-      cl_free(root); 
+      cl_engine_free(root); 
       signumber=0;
       root=NULL;
 
       /* Load DB */
-      if((ret = cl_load(cl_retdbdir(), &root, &signumber, CL_DB_STDOPT))) {
+      if((ret = cl_load(cl_retdbdir(), root, &signumber, CL_DB_STDOPT)) != CL_SUCCESS) {
 	/* Raise exception with error message */
 	PyErr_SetString(PyclamavError,  cl_strerror(ret));
+	cl_engine_free(root);
 	return -2;
       }
 
       /* build the final tree */
-      if((ret = cl_build(root))) {
+      if((ret = cl_engine_compile(root)) != CL_SUCCESS) {
 	/* free the partial tree */
-	cl_free(root); 
+	cl_engine_free(root); 
 	/* Raise exception with error message */
 	PyErr_SetString(PyclamavError, cl_strerror(ret));
 	return -2;
@@ -231,7 +212,7 @@
     return NULL;     
   }
 
-  ret = cl_scanfile(file_to_scan, &virname, &size, root, &limits, CL_SCAN_STDOPT);
+  ret = cl_scanfile(file_to_scan, &virname, &size, root, CL_SCAN_STDOPT);
 
   /* Test return code */
   switch (ret) {
@@ -278,17 +259,28 @@
   /* Set documentation string for the module */
   PyDict_SetItemString(dict, "__doc__", PyString_FromString("pyclamav :\n\n  This is a python binding to the C libclamav library\n  (from the Clamav project - http://www.clamav.net).\n  It can be used to easily allow a Python script to scan\n  a file or a buffer against known viruses.\n\nAuthor : Alexandre Norman [norman@xael.org]\n\nFunctions :\n  - scanfile(string filename) : Scan a file for virus.\n  - get_numsig() : Return the number of known signatures.\n  - get_version() : Return the version of Clamav.\n  - version() : Return the version of pyclamav.\n"));
 
+  if((ret = cl_init(CL_INIT_DEFAULT)) != CL_SUCCESS) {
+    /* Raise exception with error message */
+    PyErr_SetString(PyclamavError,  cl_strerror(ret));
+    return;
+  }
 
-  if((ret = cl_load(cl_retdbdir(), &root, &signumber, CL_DB_STDOPT))) {
+  if(!(root = cl_engine_new())) {
+    PyErr_SetString(PyclamavError, "Can't create new engine.");
+    return;
+  }
+
+  if((ret = cl_load(cl_retdbdir(), root, &signumber, CL_DB_STDOPT)) != CL_SUCCESS) {
     /* Raise exception with error message */
     PyErr_SetString(PyclamavError,  cl_strerror(ret));
+    cl_engine_free(root);
     return;
   }
 
   /* build the final tree */
-  if((ret = cl_build(root))) {
+  if((ret = cl_engine_compile(root)) != CL_SUCCESS) {
     /* free the partial tree */
-    cl_free(root); 
+    cl_engine_free(root); 
     /* Raise exception with error message */
     PyErr_SetString(PyclamavError, cl_strerror(ret));
     return;
@@ -301,13 +293,6 @@
 
 
 
-  /* set up archive limits */
-  memset(&limits, 0, sizeof(struct cl_limits));
-  limits.maxfiles = 1000; /* max files */
-  limits.maxfilesize = 10 * 1048576; /* maximal archived file size == 10 Mb */
-  limits.maxreclevel = 5; /* maximal recursion level */
-  limits.archivememlim = 0; /* disable memory limit for bzip2 scanner */
-
   return ;
 }
 

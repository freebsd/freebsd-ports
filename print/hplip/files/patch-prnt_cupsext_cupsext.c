--- prnt/cupsext/cupsext.c.orig	Tue May 23 15:45:57 2006
+++ prnt/cupsext/cupsext.c	Tue May 23 15:49:34 2006
@@ -253,11 +253,23 @@
 
 PyObject * getPrinters( PyObject * self, PyObject * args )
 {
+    int max_count;
+    char * device_uri;
+    char * printer_uri;
+    char * info;
+    char * location;
+    char * make_model;
+    char * name;
+    /*char * ppd_name;*/
+    cups_ptype_t type;
+    ipp_pstate_t state;
+    int i = 0;
     http_t *http=NULL;     /* HTTP object */
     ipp_t *request=NULL;  /* IPP request object */
     ipp_t *response=NULL; /* IPP response object */
     ipp_attribute_t *attr;     /* Current IPP attribute */
     PyObject * printer_list;
+    printer_Object * printer;
     cups_lang_t * language;
     static const char * attrs[] = /* Requested attributes */
         {
@@ -300,7 +312,7 @@
         goto abort;
     }
 
-    int max_count = 0;
+    max_count = 0;
 
     for ( attr = ippFindAttribute(response, "printer-name", IPP_TAG_NAME),
             max_count = 0;
@@ -311,16 +323,7 @@
 
     printer_list = PyList_New( max_count );
 
-    char * device_uri;
-    char * printer_uri;
-    char * info;
-    char * location;
-    char * make_model;
-    char * name;
-    /*char * ppd_name;*/
-    cups_ptype_t type;
-    ipp_pstate_t state;
-    int i = 0;
+    i = 0;
 
     for (attr = response->attrs; attr != NULL; attr = attr->next)
     {
@@ -392,7 +395,6 @@
                 continue;
         }
 
-        printer_Object * printer;
         printer = (printer_Object *)_newPrinter( device_uri, name, printer_uri, location, make_model,
                                                  info, state/*, ppd_name*/ );
         PyList_SET_ITEM( printer_list, i, (PyObject *)printer );
@@ -925,13 +927,13 @@
 PyObject *  getPPD( PyObject * self, PyObject * args )
 {
     char * printer;
+    const char * ppd;
 
     if ( !PyArg_ParseTuple( args, "z", &printer ) )
     {
         return Py_BuildValue( "" ); // None
     }
 
-    const char * ppd;
     ppd = cupsGetPPD( (const char *)printer );
 
     return Py_BuildValue( "s", ppd ); 
@@ -941,16 +943,16 @@
 
 PyObject *  getPPDOption( PyObject * self, PyObject * args )
 {
+    char * option;
+    ppd_choice_t * marked_choice;
     if( ppd_file != NULL )
     {
-        char * option;
 
         if ( !PyArg_ParseTuple( args, "z", &option ) )
         {
             return Py_BuildValue( "" ); // None
         }
 
-        ppd_choice_t * marked_choice;
         marked_choice = ppdFindMarkedChoice( ppd_file, option );
 
         if (marked_choice == NULL )

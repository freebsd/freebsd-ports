--- prnt/cupsext/cupsext.c.orig	Thu Sep 14 12:51:40 2006
+++ prnt/cupsext/cupsext.c	Wed Oct 18 00:39:28 2006
@@ -259,11 +259,23 @@
 
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
@@ -306,7 +318,7 @@
         goto abort;
     }
 
-    Py_ssize_t max_count = 0;
+    max_count = 0;
 
     for (attr = ippFindAttribute(response, "printer-name", IPP_TAG_NAME),
             max_count = 0;
@@ -317,16 +329,7 @@
 
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
@@ -398,7 +401,6 @@
                 continue;
         }
 
-        printer_Object * printer;
         printer = (printer_Object *)_newPrinter( device_uri, name, printer_uri, location, make_model,
                                                  info, state/*, ppd_name*/ );
         PyList_SET_ITEM( printer_list, i, (PyObject *)printer );
@@ -935,13 +937,13 @@
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
@@ -951,16 +953,16 @@
 
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

--- src/nautilus-python.h.orig	2020-09-13 15:43:39 UTC
+++ src/nautilus-python.h
@@ -43,37 +43,37 @@ extern NautilusPythonDebug nautilus_python_debug;
 #define debug_enter_args(x, y) { if (nautilus_python_debug & NAUTILUS_PYTHON_DEBUG_MISC) \
                                      g_printf("%s: entered " x "\n", __FUNCTION__, y); }
 
-PyTypeObject *_PyGtkWidget_Type;
+extern PyTypeObject *_PyGtkWidget_Type;
 #define PyGtkWidget_Type (*_PyGtkWidget_Type)
 
-PyTypeObject *_PyNautilusColumn_Type;
+extern PyTypeObject *_PyNautilusColumn_Type;
 #define PyNautilusColumn_Type (*_PyNautilusColumn_Type)
 
-PyTypeObject *_PyNautilusColumnProvider_Type;
+extern PyTypeObject *_PyNautilusColumnProvider_Type;
 #define PyNautilusColumnProvider_Type (*_PyNautilusColumnProvider_Type)
 
-PyTypeObject *_PyNautilusInfoProvider_Type;
+extern PyTypeObject *_PyNautilusInfoProvider_Type;
 #define PyNautilusInfoProvider_Type (*_PyNautilusInfoProvider_Type)
 
-PyTypeObject *_PyNautilusLocationWidgetProvider_Type;
+extern PyTypeObject *_PyNautilusLocationWidgetProvider_Type;
 #define PyNautilusLocationWidgetProvider_Type (*_PyNautilusLocationWidgetProvider_Type)
 
-PyTypeObject *_PyNautilusMenu_Type;
+extern PyTypeObject *_PyNautilusMenu_Type;
 #define PyNautilusMenu_Type (*_PyNautilusMenu_Type)
 
-PyTypeObject *_PyNautilusMenuItem_Type;
+extern PyTypeObject *_PyNautilusMenuItem_Type;
 #define PyNautilusMenuItem_Type (*_PyNautilusMenuItem_Type)
 
-PyTypeObject *_PyNautilusMenuProvider_Type;
+extern PyTypeObject *_PyNautilusMenuProvider_Type;
 #define PyNautilusMenuProvider_Type (*_PyNautilusMenuProvider_Type)
 
-PyTypeObject *_PyNautilusPropertyPage_Type;
+extern PyTypeObject *_PyNautilusPropertyPage_Type;
 #define PyNautilusPropertyPage_Type (*_PyNautilusPropertyPage_Type)
 
-PyTypeObject *_PyNautilusPropertyPageProvider_Type;
+extern PyTypeObject *_PyNautilusPropertyPageProvider_Type;
 #define PyNautilusPropertyPageProvider_Type (*_PyNautilusPropertyPageProvider_Type)
 
-PyTypeObject *_PyNautilusOperationHandle_Type;
+extern PyTypeObject *_PyNautilusOperationHandle_Type;
 #define PyNautilusOperationHandle_Type (*_PyNautilusOperationHandle_Type)
 
 #endif /* NAUTILUS_PYTHON_H */

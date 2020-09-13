--- src/nautilus-python-object.c.orig	2020-09-13 15:40:21 UTC
+++ src/nautilus-python-object.c
@@ -49,7 +49,7 @@ int __PyString_Check(PyObject *obj) {
 #endif
 }
 
-char* __PyString_AsString(PyObject *obj) {
+const char* __PyString_AsString(PyObject *obj) {
 #if PY_MAJOR_VERSION >= 3
     return PyUnicode_AsUTF8(obj);
 #else
@@ -398,7 +398,7 @@ beach:
 #define METHOD_NAME "update_file_info"
 static NautilusOperationResult
 nautilus_python_object_update_file_info (NautilusInfoProvider         *provider,
-                                         NautilusFile                 *file,
+                                         NautilusFileInfo             *file_info,
                                          GClosure                     *update_complete,
                                          NautilusOperationHandle   **handle) {
     NautilusPythonObject *object = (NautilusPythonObject*)provider;
@@ -417,12 +417,12 @@ nautilus_python_object_update_file_info (NautilusInfoP
                                      pygobject_new((GObject*)provider),
                                      py_handle,
                                      pyg_boxed_new(G_TYPE_CLOSURE, update_complete, TRUE, TRUE),
-                                     pygobject_new((GObject*)file));
+                                     pygobject_new((GObject*)file_info));
     }
     else if (PyObject_HasAttrString(object->instance, "update_file_info")) {
         py_ret = PyObject_CallMethod(object->instance,
                                      METHOD_PREFIX METHOD_NAME, "(N)",
-                                     pygobject_new((GObject*)file));
+                                     pygobject_new((GObject*)file_info));
     }
     else {
         goto beach;
@@ -443,7 +443,7 @@ nautilus_python_object_update_file_info (NautilusInfoP
 #endif
 
 beach:
-    free_pygobject_data(file, NULL);
+    free_pygobject_data(file_info, NULL);
     Py_XDECREF(py_ret);
     pyg_gil_state_release(state);
     return ret;

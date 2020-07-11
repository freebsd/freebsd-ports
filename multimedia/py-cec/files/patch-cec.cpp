--- cec.cpp.orig	2019-11-12 05:53:01 UTC
+++ cec.cpp
@@ -612,14 +612,22 @@ PyObject * set_port(PyObject * self, PyObject * args) 
 
 PyObject * can_persist_config(PyObject * self, PyObject * args) {
    if( PyArg_ParseTuple(args, ":can_persist_config") ) {
+#if CEC_LIB_VERSION_MAJOR >= 5
+      RETURN_BOOL(CEC_adapter->CanSaveConfiguration());
+#else
       RETURN_BOOL(CEC_adapter->CanPersistConfiguration());
+#endif
    }
    return NULL;
 }
 
 PyObject * persist_config(PyObject * self, PyObject * args) {
    if( PyArg_ParseTuple(args, ":persist_config") ) {
+#if CEC_LIB_VERSION_MAJOR >= 5
+      if( ! CEC_adapter->CanSaveConfiguration() ) {
+#else
       if( ! CEC_adapter->CanPersistConfiguration() ) {
+#endif
          PyErr_SetString(PyExc_NotImplementedError,
                "Cannot persist configuration");
          return NULL;
@@ -629,7 +637,11 @@ PyObject * persist_config(PyObject * self, PyObject * 
          PyErr_SetString(PyExc_IOError, "Could not get configuration");
          return NULL;
       }
+#if CEC_LIB_VERSION_MAJOR >= 5
+      RETURN_BOOL(CEC_adapter->SetConfiguration(&config));
+#else
       RETURN_BOOL(CEC_adapter->PersistConfiguration(&config));
+#endif
    }
    return NULL;
 }

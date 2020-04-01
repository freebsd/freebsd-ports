--- openvdb/python/pyOpenVDBModule.cc.orig	2019-05-07 20:58:35 UTC
+++ openvdb/python/pyOpenVDBModule.cc
@@ -320,7 +320,11 @@ struct PointIndexConverter
     /// @return nullptr if the given Python object is not convertible to the PointIndex.
     static void* convertible(PyObject* obj)
     {
+#if PY_MAJOR_VERSION >= 3
+	if (!PyLong_Check(obj)) return nullptr; // not a Python integer
+#else
         if (!PyInt_Check(obj)) return nullptr; // not a Python integer
+#endif
         return obj;
     }
 
@@ -337,7 +341,11 @@ struct PointIndexConverter
         // Extract the PointIndex from the python integer
         PointIndexT* index = static_cast<PointIndexT*>(storage);
 
+#if PY_MAJOR_VERSION >= 3
+	*index = static_cast<IntType>(PyLong_AsLong(obj));
+#else
         *index = static_cast<IntType>(PyInt_AsLong(obj));
+#endif
     }
 
     /// Register both the PointIndex-to-integer and the integer-to-PointIndex converters.

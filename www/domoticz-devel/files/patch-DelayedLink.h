--- hardware/plugins/DelayedLink.h.orig	2023-12-24 09:47:32.242841000 +0100
+++ hardware/plugins/DelayedLink.h	2023-12-24 09:50:22.343807000 +0100
@@ -149,7 +149,9 @@
 		DECLARE_PYTHON_SYMBOL(PyObject*, Py_CompileString, const char* COMMA const char* COMMA int);
 		DECLARE_PYTHON_SYMBOL(PyObject*, PyEval_EvalCode, PyObject* COMMA PyObject* COMMA PyObject*);
 		DECLARE_PYTHON_SYMBOL(long, PyType_GetFlags, PyTypeObject*);
+#if PY_VERSION_HEX < 0x03090000
 		DECLARE_PYTHON_SYMBOL(void, _Py_Dealloc, PyObject*);
+#endif
 
 		SharedLibraryProxy() {
 			Py_None = nullptr;
@@ -288,7 +290,9 @@
 					RESOLVE_PYTHON_SYMBOL(Py_CompileString);
 					RESOLVE_PYTHON_SYMBOL(PyEval_EvalCode);
 					RESOLVE_PYTHON_SYMBOL(PyType_GetFlags);
+#if PY_VERSION_HEX < 0x03090000
 					RESOLVE_PYTHON_SYMBOL(_Py_Dealloc);
+#endif
 				}
 			}
 		};
@@ -521,6 +525,9 @@
 #			define _Py_DEC_REFTOTAL
 #		endif
 #	endif
+#	ifndef _Py_Dealloc
+#		define _Py_Dealloc
+#	endif
 #endif
 #if PY_VERSION_HEX >= 0x030800f0
 static inline void py3__Py_INCREF(PyObject* op)
@@ -559,10 +566,12 @@
 		}
 #endif
 	}
+#if PY_VERSION_HEX < 0x03090000
 	else
 	{
 		_Py_Dealloc(op);
 	}
+#endif
 }
 
 #undef Py_DECREF

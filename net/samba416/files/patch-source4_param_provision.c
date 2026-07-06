--- source4/param/provision.c.orig	2022-01-24 10:26:59 UTC
+++ source4/param/provision.c
@@ -101,6 +101,18 @@ static PyObject *PyLdb_FromLdbContext(struct ldb_conte
 	return (PyObject *)ret;
 }
 
+static PyObject *call_wrapper(PyObject *callable, PyObject *kwargs)
+{
+	/*
+	 * Helper for calls with zero non-keyword arguments.
+	 */
+	PyObject *empty = PyTuple_New(0), *result = NULL;
+	SMB_ASSERT(empty);
+	result = PyObject_Call(callable, empty, kwargs);
+	Py_XDECREF(empty);
+	return result;
+}
+
 NTSTATUS provision_bare(TALLOC_CTX *mem_ctx, struct loadparm_context *lp_ctx,
 			struct provision_settings *settings, 
 			struct provision_result *result)
@@ -265,7 +277,7 @@ NTSTATUS provision_bare(TALLOC_CTX *mem_ctx, struct lo
 		goto out;
 	}
 
-	py_result = PyEval_CallObjectWithKeywords(provision_fn, NULL, parameters);
+	py_result = call_wrapper(provision_fn, parameters);
 
 	if (py_result == NULL) {
 		status = NT_STATUS_UNSUCCESSFUL;
@@ -453,7 +465,7 @@ NTSTATUS provision_store_self_join(TALLOC_CTX *mem_ctx
 		goto out;
 	}
 
-	py_result = PyEval_CallObjectWithKeywords(provision_fn, NULL, parameters);
+	py_result = call_wrapper(provision_fn, parameters);
 
 	if (py_result == NULL) {
 		ldb_transaction_cancel(ldb);
@@ -538,7 +550,7 @@ struct ldb_context *provision_get_schema(TALLOC_CTX *m
 		}
 	}
 
-	py_result = PyEval_CallObjectWithKeywords(schema_fn, NULL, parameters);
+	py_result = call_wrapper(schema_fn, parameters);
 
 	Py_DECREF(parameters);
 

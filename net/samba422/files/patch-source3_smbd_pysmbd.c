--- source3/smbd/pysmbd.c.orig	2025-02-20 12:58:50 UTC
+++ source3/smbd/pysmbd.c
@@ -507,6 +507,20 @@ static SMB_ACL_T make_simple_acl(TALLOC_CTX *mem_ctx,
 	return acl;
 }
 
+static SMB_ACL_T make_simple_nfsv4_acl(TALLOC_CTX *mem_ctx,
+					gid_t gid,
+					mode_t chmod_mode)
+{
+	/*
+	 * This function needs to create an NFSv4 ACL. Currently, the only way
+	 * to do so is to use the operating system interface, or to use the
+	 * functions in source3/modules/nfs4_acls.c. These seems ugly and
+	 * hacky. NFSv4 ACL's should be a first class citizen and
+	 * librpc/idl/smb_acl.idl should be modified accordingly.
+	 */
+	return NULL;
+}
+
 /*
   set a simple ACL on a file, as a test
  */
@@ -579,7 +593,85 @@ static PyObject *py_smbd_set_simple_acl(PyObject *self
 	Py_RETURN_NONE;
 }
 
+
 /*
+  set a simple NFSv4 ACL on a file, as a test
+ */
+static PyObject *py_smbd_set_simple_nfsv4_acl(PyObject *self, PyObject *args, PyObject *kwargs)
+{
+	const char * const kwnames[] = {
+		"fname",
+		"mode",
+		"session_info",
+		"gid",
+		"service",
+		NULL
+	};
+	char *fname, *service = NULL;
+	PyObject *py_session = Py_None;
+	struct auth_session_info *session_info = NULL;
+	int ret;
+	int mode, gid = -1;
+	SMB_ACL_T acl;
+	TALLOC_CTX *frame;
+	connection_struct *conn;
+
+	if (!PyArg_ParseTupleAndKeywords(args, kwargs, "siO|iz",
+					 discard_const_p(char *, kwnames),
+					 &fname,
+					 &mode,
+					 &py_session,
+					 &gid,
+					 &service))
+		return NULL;
+
+	if (!py_check_dcerpc_type(py_session,
+				  "samba.dcerpc.auth",
+				  "session_info")) {
+		return NULL;
+	}
+	session_info = pytalloc_get_type(py_session,
+					 struct auth_session_info);
+	if (session_info == NULL) {
+		PyErr_Format(PyExc_TypeError,
+			     "Expected auth_session_info for session_info argument got %s",
+			     pytalloc_get_name(py_session));
+		return NULL;
+	}
+
+	frame = talloc_stackframe();
+
+	acl = make_simple_nfsv4_acl(frame, gid, mode);
+	if (acl == NULL) {
+		TALLOC_FREE(frame);
+		Py_RETURN_NONE;
+	}
+
+	conn = get_conn_tos(service, session_info);
+	if (!conn) {
+		TALLOC_FREE(frame);
+		Py_RETURN_NONE;
+	}
+
+	/*
+	 * SMB_ACL_TYPE_ACCESS -> ACL_TYPE_ACCESS -> Not valid for NFSv4 ACL
+	 */
+	ret = 0;
+
+	/* ret = set_sys_acl_conn(fname, SMB_ACL_TYPE_ACCESS, acl, conn); */
+
+	if (ret != 0) {
+		TALLOC_FREE(frame);
+		errno = ret;
+		return PyErr_SetFromErrno(PyExc_OSError);
+	}
+
+	TALLOC_FREE(frame);
+
+	Py_RETURN_NONE;
+}
+
+/*
   chown a file
  */
 static PyObject *py_smbd_chown(PyObject *self, PyObject *args, PyObject *kwargs)
@@ -767,7 +859,7 @@ static PyObject *py_smbd_unlink(PyObject *self, PyObje
 }
 
 /*
-  check if we have ACL support
+  check if we have POSIX.1e ACL support
  */
 static PyObject *py_smbd_have_posix_acls(PyObject *self,
 		PyObject *Py_UNUSED(ignored))
@@ -779,7 +871,84 @@ static PyObject *py_smbd_have_posix_acls(PyObject *sel
 #endif
 }
 
+static PyObject *py_smbd_has_posix_acls(PyObject *self, PyObject *args, PyObject *kwargs)
+{
+	const char * const kwnames[] = { "path", NULL };
+	char *path = NULL;
+	TALLOC_CTX *frame;
+	struct statfs fs;
+	int ret = false;
+
+	frame = talloc_stackframe();
+
+	if (!PyArg_ParseTupleAndKeywords(args, kwargs, "s|z",
+					 discard_const_p(char *, kwnames), &path)) {
+		TALLOC_FREE(frame);
+		return NULL;
+	}
+
+	if (statfs(path, &fs) != 0) {
+		TALLOC_FREE(frame);
+		return NULL;
+	}
+
+	if (fs.f_flags & MNT_ACLS)
+		ret = true;
+
+	TALLOC_FREE(frame);
+	return PyBool_FromLong(ret);
+}
+
 /*
+  check if we have NFSv4 ACL support
+ */
+static PyObject *py_smbd_have_nfsv4_acls(PyObject *self)
+{
+#ifdef HAVE_LIBSUNACL
+	return PyBool_FromLong(true);
+#else
+	return PyBool_FromLong(false);
+#endif
+}
+
+static PyObject *py_smbd_has_nfsv4_acls(PyObject *self, PyObject *args, PyObject *kwargs)
+{
+	const char * const kwnames[] = { "path", NULL };
+	char *path = NULL;
+	TALLOC_CTX *frame;
+	struct statfs fs;
+	int ret = false;
+
+	frame = talloc_stackframe();
+
+	if (!PyArg_ParseTupleAndKeywords(args, kwargs, "s|z",
+					 discard_const_p(char *, kwnames), &path)) {
+		TALLOC_FREE(frame);
+		return NULL;
+	}
+
+	if (statfs(path, &fs) != 0) {
+		TALLOC_FREE(frame);
+		return NULL;
+	}
+
+	if (fs.f_flags & MNT_NFS4ACLS)
+		ret = true;
+
+	TALLOC_FREE(frame);
+	return PyBool_FromLong(ret);
+}
+
+
+static PyObject *py_smbd_set_nfsv4_defaults(PyObject *self)
+{
+	/*
+	 * It is really be done in source3/param/loadparm.c
+	 */
+	Py_RETURN_NONE;
+}
+
+/*
   set the NT ACL on a file
  */
 static PyObject *py_smbd_set_nt_acl(PyObject *self, PyObject *args, PyObject *kwargs)
@@ -1284,8 +1453,26 @@ static PyMethodDef py_smbd_methods[] = {
 	{ "have_posix_acls",
 		(PyCFunction)py_smbd_have_posix_acls, METH_NOARGS,
 		NULL },
+	{ "has_posix_acls",
+		PY_DISCARD_FUNC_SIG(PyCFunction, py_smbd_has_posix_acls),
+		METH_VARARGS|METH_KEYWORDS,
+		NULL },
+	{ "have_nfsv4_acls",
+		(PyCFunction)py_smbd_have_nfsv4_acls, METH_NOARGS,
+		NULL },
+	{ "has_nfsv4_acls",
+		PY_DISCARD_FUNC_SIG(PyCFunction, py_smbd_has_nfsv4_acls),
+		METH_VARARGS|METH_KEYWORDS,
+		NULL },
+	{ "set_nfsv4_defaults",
+		(PyCFunction)py_smbd_set_nfsv4_defaults, METH_NOARGS,
+		NULL },
 	{ "set_simple_acl",
 		PY_DISCARD_FUNC_SIG(PyCFunction, py_smbd_set_simple_acl),
+		METH_VARARGS|METH_KEYWORDS,
+		NULL },
+	{ "set_simple_nfsv4_acl",
+		PY_DISCARD_FUNC_SIG(PyCFunction, py_smbd_set_simple_nfsv4_acl),
 		METH_VARARGS|METH_KEYWORDS,
 		NULL },
 	{ "set_nt_acl",

--- Modules/errors.c.orig	Wed Nov 15 10:41:35 2000
+++ Modules/errors.c	Wed Nov 15 14:17:15 2000
@@ -17,7 +17,13 @@
 
 /* list of error objects */
 
+#if defined(LDAP_API_VERSION)
+/* OpenLDAPv2 */
+#define NUM_LDAP_ERRORS		LDAP_REFERRAL_LIMIT_EXCEEDED+1
+#else
+/* OpenLDAPv1 */
 #define NUM_LDAP_ERRORS		LDAP_NO_MEMORY+1
+#endif
 static PyObject* 
 errobjects[ NUM_LDAP_ERRORS ];
 
@@ -30,21 +36,26 @@
 		PyErr_SetFromErrno( LDAPexception_class );
 		return NULL;
 	}
-#ifdef LDAP_TYPE_IS_OPAQUE
+#if defined(LDAP_TYPE_IS_OPAQUE) && !defined(LDAP_API_VERSION)
 	else {
 		PyErr_SetString(LDAPexception_class,
 			"unknown error (C API does not expose error)");
 		return NULL;
 	}
-#else
+#else /* defined(LDAP_TYPE_IS_OPAQUE) && !defined(LDAP_API_VERSION) */
 	else {
 		int errnum;
 		PyObject *errobj;
 		PyObject *info;
 		PyObject *str;
 
+#if defined(LDAP_API_VERSION)
+		char *matched, *error;
+		if (ldap_get_option(l, LDAP_OPT_ERROR_NUMBER, &errnum) < 0)
+#else
 		errnum = l->ld_errno;
 		if (errnum<0 || errnum>=NUM_LDAP_ERRORS)
+#endif /* defined(LDAP_API_VERSION) */
 			errobj = LDAPexception_class;	/* unknown error XXX */
 		else
 			errobj = errobjects[errnum];
@@ -61,6 +72,35 @@
 			PyDict_SetItemString( info, "desc", str );
 		Py_XDECREF(str);
 
+#if defined(LDAP_API_VERSION)
+		if (ldap_get_option(l, LDAP_OPT_MATCHED_DN, &matched) >= 0
+			&& matched != NULL) {
+		    if (*matched != '\0') {
+			str = PyString_FromString(matched);
+			if (str)
+			    PyDict_SetItemString( info, "matched", str );
+			Py_XDECREF(str);
+		    }
+		    ldap_memfree(matched);
+		}
+
+		if (errnum == LDAP_REFERRAL) {
+		    str = PyString_FromString(msg);
+		    if (str)
+			PyDict_SetItemString( info, "info", str );
+		    Py_XDECREF(str);
+		} else if (ldap_get_option(l, LDAP_OPT_ERROR_STRING, &error) >= 0
+			&& error != NULL) {
+		    if (error != '\0') {
+			str = PyString_FromString(error);
+			if (str)
+			    PyDict_SetItemString( info, "info", str );
+			Py_XDECREF(str);
+		    }
+		    ldap_memfree(error);
+		}
+
+#else /* defined(LDAP_API_VERSION) */
 		if (l->ld_matched != NULL && *l->ld_matched != '\0') 
 		{
 		   str = PyString_FromString(l->ld_matched);
@@ -76,11 +116,12 @@
 			   PyDict_SetItemString( info, "info", str );
 		   Py_XDECREF(str);
 		}
+#endif /* defined(LDAP_API_VERSION) */
 		PyErr_SetObject( errobj, info );
 		Py_DECREF(info);
 		return NULL;
 	}
-#endif
+#endif  /* defined(LDAP_TYPE_IS_OPAQUE) && !defined(LDAP_API_VERSION) */
 }
 
 
@@ -163,4 +204,19 @@
 	seterrobj(USER_CANCELLED);
 	seterrobj(PARAM_ERROR);
 	seterrobj(NO_MEMORY);
+#if defined(LDAP_API_VERSION)
+	seterrobj(REFERRAL);
+	seterrobj(ADMINLIMIT_EXCEEDED);
+	seterrobj(UNAVAILABLE_CRITICAL_EXTENSION);
+	seterrobj(CONFIDENTIALITY_REQUIRED);
+	seterrobj(SASL_BIND_IN_PROGRESS);
+	seterrobj(AFFECTS_MULTIPLE_DSAS);
+	seterrobj(CONNECT_ERROR);
+	seterrobj(NOT_SUPPORTED);
+	seterrobj(CONTROL_NOT_FOUND);
+	seterrobj(NO_RESULTS_RETURNED);
+	seterrobj(MORE_RESULTS_TO_RETURN);
+	seterrobj(CLIENT_LOOP);
+	seterrobj(REFERRAL_LIMIT_EXCEEDED);
+#endif
 }

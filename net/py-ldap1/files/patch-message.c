--- Modules/message.c.orig	Wed Nov 15 10:41:35 2000
+++ Modules/message.c	Wed Nov 15 16:51:18 2000
@@ -114,6 +114,40 @@
 	 PyList_Append(result, entrytuple);
 	 Py_DECREF(entrytuple);
      }
+#if defined(LDAP_API_VERSION)
+     for(entry = ldap_first_reference(ld,m);
+         entry != NULL;
+	 entry = ldap_next_reference(ld,entry))
+     {
+         char **refs = NULL;
+	 PyObject* entrytuple;
+	 PyObject* reflist = PyList_New(0);
+
+	 if (reflist == NULL)  {
+	     Py_DECREF(result);
+             ldap_msgfree( m );
+	     return NULL;
+	 }
+	 if (ldap_parse_reference(ld, entry, &refs, NULL, 0) != LDAP_SUCCESS) {
+	     Py_DECREF(result);
+             ldap_msgfree( m );
+	     return LDAPerror( ld, "ldap_parse_reference" );
+	 }
+	 if (refs) {
+	     int i;
+	     for (i=0; refs[i] != NULL; i++) {
+		 PyObject *refstr = PyString_FromString(refs[i]);
+		 PyList_Append(reflist, refstr);
+		 Py_DECREF(refstr);
+	     }
+	     ber_memvfree( (void **) refs );
+         }
+	 entrytuple = Py_BuildValue("(sO)", NULL, reflist);
+	 Py_DECREF(reflist);
+	 PyList_Append(result, entrytuple);
+	 Py_DECREF(entrytuple);
+     }
+#endif
      ldap_msgfree( m );
      return result;
 }

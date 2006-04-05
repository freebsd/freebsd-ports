Index: LDAPObject.c
===================================================================
RCS file: /cvsroot/python-ldap/python-ldap/Modules/LDAPObject.c,v
retrieving revision 1.72
diff -u -r1.72 LDAPObject.c
--- Modules/LDAPObject.c	11 Mar 2006 21:05:57 -0000	1.72
+++ Modules/LDAPObject.c	23 Mar 2006 21:48:33 -0000
@@ -971,8 +971,16 @@
     if (pmsg == NULL) {
 	    retval = NULL;
     } else {
-        retval = Py_BuildValue("(OOiO)", result_str, pmsg, res_msgid,
-			       pyctrls ? pyctrls : PyList_New(0));
+	if (pyctrls != NULL) {
+        	retval = Py_BuildValue("(OOiO)", result_str, pmsg, res_msgid,
+				       pyctrls);
+	} else { 
+		PyObject *pNewList = PyList_New(0);
+        	retval = Py_BuildValue("(OOiO)", result_str, pmsg, res_msgid,
+				       pNewList);
+		Py_DECREF(pNewList);
+	}
+
 	if (pmsg != Py_None) {
         Py_DECREF(pmsg);
     }

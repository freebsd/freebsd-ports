--- scribus/plugins/scriptplugin/scriptplugin.cpp.orig	Tue Jan  4 07:45:50 2005
+++ scribus/plugins/scriptplugin/scriptplugin.cpp	Mon Jan 10 21:21:27 2005
@@ -52,6 +52,27 @@
 #include <qtextstream.h>
 #include <cstdlib>
 
+// XXX Implement strndup for FreeBSD.
+#ifdef __FreeBSD__
+#ifdef __cplusplus
+extern "C" {
+#endif
+static char *
+mystrndup(const char *str, int len) {
+    char *ret;
+
+    if ((str == NULL || len < 0)) return(NULL);
+    ret = (char *)malloc(len + 1);
+    if (ret == NULL) return(NULL);
+    memcpy(ret, str, len);
+    ret[len] = '\0';
+    return(ret);
+}
+#ifdef __cplusplus
+}
+#endif
+#endif
+
 // Exceptions; visible from cmdvar.h, set up in initscribus()
 PyObject* ScribusException;
 PyObject* NoDocOpenError;
@@ -499,8 +520,13 @@
 {
 	/* Work around the braindead Python/C API not using 'const' for
 	 * strings it won't change. */
+#ifdef __FreeBSD__
+	char* newNameTemp = mystrndup(newName, strlen(newName));
+	char* oldNameTemp = mystrndup(oldName, strlen(oldName));
+#else
 	char* newNameTemp = strndup(newName, strlen(newName));
 	char* oldNameTemp = strndup(oldName, strlen(oldName));
+#endif
 	assert(newNameTemp != NULL);
 	assert(oldNameTemp != NULL);
 	/* We use PyMapping_GetItemString because unlike PyDict_GetItemString it
@@ -563,7 +589,11 @@
 	 */
 	QCString utfTranslated = translated.utf8();
 	const char* trch = utfTranslated.data();
+#ifdef __FreeBSD__
+	return mystrndup(trch, strlen(trch));
+#else
 	return strndup(trch, strlen(trch));
+#endif
 }
 
 /* Now we're using the more pythonic convention for names:

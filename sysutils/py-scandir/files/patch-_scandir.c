--- _scandir.c.orig	2024-02-16 23:29:35 UTC
+++ _scandir.c
@@ -94,7 +94,7 @@ comment):
 
 // _Py_stat_struct is already defined in fileutils.h on Python 3.5+
 // But not in PyPy
-#if PY_MAJOR_VERSION < 3 || (PY_MAJOR_VERSION == 3 && PY_MINOR_VERSION < 5) || defined(PYPY_VERSION_NUM)
+#if PY_MAJOR_VERSION < 3 || (PY_MAJOR_VERSION == 3 && PY_MINOR_VERSION < 5) || (PY_MAJOR_VERSION == 3 && PY_MINOR_VERSION >= 11) || defined(PYPY_VERSION_NUM)
 #ifdef MS_WINDOWS
 struct _Py_stat_struct {
     unsigned long st_dev;
@@ -660,7 +660,7 @@ _pystat_fromstructstat(STRUCT_STAT *st)
     return v;
 }
 
-char *PyStructSequence_UnnamedField = "unnamed field";
+static char *scandir_unnamed_field = "unnamed field";
 
 PyDoc_STRVAR(stat_result__doc__,
 "stat_result: Result from stat, fstat, or lstat.\n\n\
@@ -681,7 +681,7 @@ static PyStructSequence_Field stat_result_fields[] = {
     {"st_uid",     "user ID of owner"},
     {"st_gid",     "group ID of owner"},
     {"st_size",    "total size, in bytes"},
-    /* The NULL is replaced with PyStructSequence_UnnamedField later. */
+    /* The NULL is replaced with scandir_unnamed_field later. */
     {NULL,         "integer time of last access"},
     {NULL,         "integer time of last modification"},
     {NULL,         "integer time of last change"},
@@ -986,10 +986,12 @@ DirEntry_fetch_stat(DirEntry *self, int follow_symlink
     if (!path)
         return NULL;
 
+    Py_BEGIN_ALLOW_THREADS
     if (follow_symlinks)
         result = win32_stat_w(path, &st);
     else
         result = win32_lstat_w(path, &st);
+    Py_END_ALLOW_THREADS
 
     if (result != 0) {
         return PyErr_SetExcFromWindowsErrWithFilenameObject(PyExc_OSError,
@@ -1014,10 +1016,12 @@ DirEntry_fetch_stat(DirEntry *self, int follow_symlink
 #endif
     path = PyBytes_AS_STRING(bytes);
 
+    Py_BEGIN_ALLOW_THREADS
     if (follow_symlinks)
         result = STAT(path, &st);
     else
         result = LSTAT(path, &st);
+    Py_END_ALLOW_THREADS
     Py_DECREF(bytes);
 
     if (result != 0)
@@ -1813,9 +1817,9 @@ init_scandir(void)
     if (!billion)
         INIT_ERROR;
 
-    stat_result_desc.fields[7].name = PyStructSequence_UnnamedField;
-    stat_result_desc.fields[8].name = PyStructSequence_UnnamedField;
-    stat_result_desc.fields[9].name = PyStructSequence_UnnamedField;
+    stat_result_desc.fields[7].name = scandir_unnamed_field;
+    stat_result_desc.fields[8].name = scandir_unnamed_field;
+    stat_result_desc.fields[9].name = scandir_unnamed_field;
     PyStructSequence_InitType(&StatResultType, &stat_result_desc);
     structseq_new = StatResultType.tp_new;
     StatResultType.tp_new = statresult_new;

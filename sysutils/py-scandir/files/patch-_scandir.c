--- _scandir.c.orig	2018-08-02 16:17:16 UTC
+++ _scandir.c
@@ -660,7 +660,11 @@ _pystat_fromstructstat(STRUCT_STAT *st)
     return v;
 }
 
+#if PY_MAJOR_VERSION >= 3 && PY_MINOR_VERSION >= 9
+const char * const PyStructSequence_UnnamedField = "unnamed field";
+#else
 char *PyStructSequence_UnnamedField = "unnamed field";
+#endif
 
 PyDoc_STRVAR(stat_result__doc__,
 "stat_result: Result from stat, fstat, or lstat.\n\n\

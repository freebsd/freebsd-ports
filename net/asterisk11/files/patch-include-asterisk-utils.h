--- include/asterisk/utils.h.orig	2013-07-02 11:52:13.000000000 +0200
+++ include/asterisk/utils.h	2013-07-02 12:32:18.000000000 +0200
@@ -927,9 +927,6 @@
  * \encode
  */
 #define RAII_VAR(vartype, varname, initval, dtor) \
-    /* Prototype needed due to http://gcc.gnu.org/bugzilla/show_bug.cgi?id=36774 */ \
-    auto void _dtor_ ## varname (vartype * v); \
-    void _dtor_ ## varname (vartype * v) { dtor(*v); } \
-    vartype varname __attribute__((cleanup(_dtor_ ## varname))) = (initval)
+    vartype varname __attribute__((cleanup(dtor ## _cleanup))) = (initval)
 
 #endif /* _ASTERISK_UTILS_H */

--- ./src/suricata-common.h.orig	2012-08-21 02:35:15.000000000 -0400
+++ ./src/suricata-common.h	2012-09-29 08:41:39.000000000 -0400
@@ -131,6 +131,10 @@
 #include <assert.h>
 #define BUG_ON(x) assert(!(x))
 
+#define table_getc(x, y) table_get_c(x, y)
+#define bstr_cmpc(x, y) bstr_cmp_c(x, y)
+#define bstr_tocstr(x) bstr_util_strdup_to_c(x)
+
 /* we need this to stringify the defines which are supplied at compiletime see:
    http://gcc.gnu.org/onlinedocs/gcc-3.4.1/cpp/Stringification.html#Stringification */
 #define xstr(s) str(s)

--- ./src/suricata-common.h.orig	2012-09-05 21:43:08.000000000 -0400
+++ ./src/suricata-common.h	2012-09-05 21:46:28.000000000 -0400
@@ -131,6 +131,8 @@
 #include <assert.h>
 #define BUG_ON(x) assert(!(x))
 
+#define table_getc(x, y) table_get_c(x, y)
+
 /* we need this to stringify the defines which are supplied at compiletime see:
    http://gcc.gnu.org/onlinedocs/gcc-3.4.1/cpp/Stringification.html#Stringification */
 #define xstr(s) str(s)

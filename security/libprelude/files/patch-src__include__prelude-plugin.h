--- src/include/prelude-plugin.h.orig	2012-06-02 00:12:30.000000000 +0900
+++ src/include/prelude-plugin.h	2012-09-11 15:46:33.000000000 +0900
@@ -61,9 +61,9 @@
  */
 #ifdef PRELUDE_APPLICATION_USE_LIBTOOL2
 # define lt_preloaded_symbols lt__PROGRAM__LTX_preloaded_symbols
-#endif
 
 extern const void *lt_preloaded_symbols[];
+#endif
 
 #define PRELUDE_PLUGIN_SET_PRELOADED_SYMBOLS()         \
         prelude_plugin_set_preloaded_symbols(lt_preloaded_symbols)

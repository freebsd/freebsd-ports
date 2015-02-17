--- SAML_wrap.c.orig	2014-11-06 12:22:29 UTC
+++ SAML_wrap.c
@@ -1442,7 +1442,9 @@ SWIG_Perl_SetModule(swig_module_info *mo
   #undef eof
 #endif
 #ifdef bool
-  #undef bool
+  #ifndef __bool_true_false_are_defined
+    #undef bool
+  #endif
 #endif
 #ifdef close
   #undef close

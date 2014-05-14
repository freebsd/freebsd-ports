--- config.m4.orig	2014-05-14 10:14:22.929420181 +0000
+++ config.m4	2014-05-14 10:15:36.967414693 +0000
@@ -4,6 +4,9 @@
 PHP_ARG_ENABLE(simplexml, whether to enable SimpleXML support,
 [  --disable-simplexml     Disable SimpleXML support], yes)
 
+PHP_ARG_WITH(pcre-dir, pcre install prefix,
+[  --with-pcre-dir           SimpleXML: pcre install prefix], no, no)
+
 if test -z "$PHP_LIBXML_DIR"; then
   PHP_ARG_WITH(libxml-dir, libxml2 install dir,
   [  --with-libxml-dir=DIR     SimpleXML: libxml2 install prefix], no, no)
@@ -11,6 +14,30 @@
 
 if test "$PHP_SIMPLEXML" != "no"; then
 
+  dnl This is PECL build, check if bundled PCRE library is used
+  old_CPPFLAGS=$CPPFLAGS
+  CPPFLAGS=$INCLUDES
+  AC_EGREP_CPP(yes,[
+#include <main/php_config.h>
+#if defined(HAVE_BUNDLED_PCRE) && !defined(COMPILE_DL_PCRE)
+yes
+#endif
+  ],[
+    PHP_PCRE_REGEX=yes
+  ],[
+    AC_EGREP_CPP(yes,[
+#include <main/php_config.h>
+#if defined(HAVE_PCRE) && !defined(COMPILE_DL_PCRE)
+yes
+#endif
+    ],[
+      PHP_PCRE_REGEX=pecl
+      PHP_ADD_INCLUDE($PHP_PCRE_DIR/include)
+    ],[
+      PHP_PCRE_REGEX=no
+    ])
+  ])
+
   if test "$PHP_LIBXML" = "no"; then   
     AC_MSG_ERROR([SimpleXML extension requires LIBXML extension, add --enable-libxml])                
   fi

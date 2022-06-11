--- config.m4.orig	2019-08-06 06:54:07 UTC
+++ config.m4
@@ -4,8 +4,39 @@ PHP_ARG_ENABLE([simplexml],
     [Disable SimpleXML support])],
   [yes])
 
+PHP_ARG_ENABLE([pcre-dir],
+  [pcre install prefix],
+  [AS_HELP_STRING([--with-pcre-dir],
+    [SimpleXML: pcre install dir])],
+  [no],
+  [no])
+
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
     AC_MSG_ERROR([SimpleXML extension requires LIBXML extension, add --with-libxml])
   fi

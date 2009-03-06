--- config.m4.orig	2009-03-06 08:25:45.000000000 +0100
+++ config.m4	2009-03-06 08:28:10.000000000 +0100
@@ -19,7 +19,7 @@
     CPPFLAGS=$INCLUDES
     AC_EGREP_CPP(yes,[
 #include <main/php_config.h>
-#if defined(HAVE_BUNDLED_PCRE) && !defined(COMPILE_DL_PCRE)
+#if defined(HAVE_BUNDLED_PCRE)
 yes
 #endif
     ],[
@@ -27,11 +27,12 @@
     ],[
       AC_EGREP_CPP(yes,[
 #include <main/php_config.h>
-#if defined(HAVE_PCRE) && !defined(COMPILE_DL_PCRE)
+#if defined(HAVE_PCRE)
 yes
 #endif
       ],[
         PHP_PCRE_REGEX=pecl
+	PHP_ADD_INCLUDE($PHP_PCRE_DIR/include)
       ],[
         PHP_PCRE_REGEX=no
       ])

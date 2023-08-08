--- config.m4.orig	2023-06-06 15:54:29 UTC
+++ config.m4
@@ -117,6 +117,13 @@ PHP_ARG_WITH([imap-ssl],
   [no],
   [no])
 
+PHP_ARG_WITH([pcre-dir],
+  [pcre install prefix],
+  [AS_HELP_STRING([[--with-pcre-dir]],
+    [IMAP: pcre install prefix])],
+  [no],
+  [no])
+
 if test "$PHP_IMAP" != "no"; then
     PHP_SUBST(IMAP_SHARED_LIBADD)
     PHP_NEW_EXTENSION(imap, php_imap.c, $ext_shared,, -DZEND_ENABLE_STATIC_TSRMLS_CACHE=1)
@@ -131,6 +138,30 @@ if test "$PHP_IMAP" != "no"; then
       el[]IMAP_INC_CHK(/c-client)
       fi
     done
+
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
 
     dnl Check for c-client version 2004
     AC_EGREP_HEADER(mail_fetch_overview_sequence, $IMAP_INC_DIR/mail.h, [

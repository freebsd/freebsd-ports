--- config.m4.orig	2010-02-07 14:06:54.000000000 +0100
+++ config.m4	2010-03-08 11:56:24.000000000 +0100
@@ -103,6 +103,8 @@
 PHP_ARG_WITH(imap-ssl,for IMAP SSL support,
 [  --with-imap-ssl[=DIR]     IMAP: Include SSL support. DIR is the OpenSSL install prefix], no, no)
 
+PHP_ARG_WITH(pcre-dir, pcre install prefix,
+[  --with-pcre-dir           IMAP: pcre install prefix], no, no)
 
 if test "$PHP_IMAP" != "no"; then  
     PHP_SUBST(IMAP_SHARED_LIBADD)
@@ -119,6 +121,30 @@
       fi
     done
 
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
     dnl Check for c-client version 2004
     AC_EGREP_HEADER(mail_fetch_overview_sequence, $IMAP_INC_DIR/mail.h, [
       AC_DEFINE(HAVE_IMAP2004,1,[ ])

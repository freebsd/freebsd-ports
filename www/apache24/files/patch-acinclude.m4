--- acinclude.m4.orig	2014-01-05 08:37:21 UTC
+++ acinclude.m4
@@ -267,9 +267,10 @@ DISTCLEAN_TARGETS = modules.mk
 static =
 shared = $libname
 EOF
+            dnl https://issues.apache.org/bugzilla/show_bug.cgi?id=53882
+            DSO_MODULES="$DSO_MODULES mpm_$1"
             # add default MPM to LoadModule list
             if test $1 = $default_mpm; then
-                DSO_MODULES="$DSO_MODULES mpm_$1"
                 ENABLED_DSO_MODULES="${ENABLED_DSO_MODULES},mpm_$1"
             fi
         fi
@@ -576,7 +577,8 @@ AC_DEFUN(APACHE_CHECK_OPENSSL,[
       liberrors=""
       AC_CHECK_HEADERS([openssl/engine.h])
       AC_CHECK_FUNCS([SSLeay_version SSL_CTX_new], [], [liberrors="yes"])
-      AC_CHECK_FUNCS([ENGINE_init ENGINE_load_builtin_engines])
+      dnl PR 196139, https://issues.apache.org/bugzilla/show_bug.cgi?id=57375
+      AC_CHECK_FUNCS([ENGINE_init ENGINE_load_builtin_engines SSL_CTX_use_certificate_chain RAND_egd])
       if test "x$liberrors" != "x"; then
         AC_MSG_WARN([OpenSSL libraries are unusable])
       fi

--- ./acinclude.m4.orig	2012-03-26 19:03:34.000000000 -0400
+++ ./acinclude.m4	2012-12-30 21:23:20.000000000 -0500
@@ -158,6 +158,14 @@
     , 
     [enable_transarc_paths="no"])
 
+dnl Deprecated crypto
+AC_ARG_ENABLE([kauth],
+    [AS_HELP_STRING([--disable-kauth],
+        [do not install the deprecated kauth server and utilities (defaults to
+         enabled)])],
+    ,
+    [enable_kauth="yes"])
+
 dnl Optimization and debugging flags.
 AC_ARG_ENABLE([strip-binaries],
     [AS_HELP_STRING([--disable-strip-binaries],
@@ -1315,6 +1323,13 @@
 fi
 AC_SUBST(BUILD_LOGIN)
 
+if test "$enable_kauth" = yes; then
+	INSTALL_KAUTH="yes"
+else
+	INSTALL_KAUTH="no"
+fi
+AC_SUBST(INSTALL_KAUTH)
+
 AC_CHECK_FUNCS(snprintf strlcat strlcpy flock getrlimit strnlen tsearch)
 AC_CHECK_FUNCS(setprogname getprogname sigaction mkstemp vsnprintf strerror strcasestr)
 AC_CHECK_FUNCS(setvbuf vsyslog getcwd)

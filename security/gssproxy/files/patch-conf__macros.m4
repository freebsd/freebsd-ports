--- conf_macros.m4.orig	2026-07-21 10:43:49 UTC
+++ conf_macros.m4
@@ -248,7 +248,7 @@ AC_DEFUN([WITH_GPSTATE_PATH],
     gpstatedir="${localstatedir}/lib/gssproxy"
     if test x"$with_gpstate_path" != x; then
         config_gpstatepath=$with_gpstate_path
-        gpstatepath=$with_gpstate_path
+        gpstatedir=$with_gpstate_path
     fi
     AC_SUBST(gpstatedir)
     AC_DEFINE_UNQUOTED(GPSTATE_PATH, "$config_gpstatepath", [Where to store ccache files for gssproxy])

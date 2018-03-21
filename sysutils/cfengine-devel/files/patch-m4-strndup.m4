--- /dev/null	2014-07-29 08:00:54.000000000 -0700
+++ m4/strndup.m4	2014-07-29 08:01:42.499328796 -0700
@@ -0,0 +1,51 @@
+# strndup.m4 serial 21
+dnl Copyright (C) 2002-2003, 2005-2013 Free Software Foundation, Inc.
+dnl This file is free software; the Free Software Foundation
+dnl gives unlimited permission to copy and/or distribute it,
+dnl with or without modifications, as long as this notice is preserved.
+
+AC_DEFUN([cf3_FUNC_STRNDUP],
+[
+  AC_REQUIRE([AC_CANONICAL_HOST]) dnl for cross-compiles
+  AC_CHECK_DECLS([strndup])
+  AC_REPLACE_FUNCS([strndup])
+  if test $ac_cv_have_decl_strndup = no; then
+    HAVE_DECL_STRNDUP=0
+  fi
+
+  if test $ac_cv_func_strndup = yes; then
+    HAVE_STRNDUP=1
+    # AIX 5.3 has a function that tries to copy the entire range specified
+    # by n, instead of just the length of src.
+    AC_CACHE_CHECK([for working strndup], [cf3_cv_func_strndup_works],
+      [AC_RUN_IFELSE([
+         AC_LANG_PROGRAM([[#include <string.h>
+                           #include <stdlib.h>]], [[
+#if !HAVE_DECL_STRNDUP
+  extern
+  #ifdef __cplusplus
+  "C"
+  #endif
+  char *strndup (const char *, size_t);
+#endif
+  char *s;
+  // Will crash if strndup tries to traverse all 2GB.
+  s = strndup ("string", 2000000000);
+  return 0;]])],
+         [cf3_cv_func_strndup_works=yes],
+         [cf3_cv_func_strndup_works=no],
+         [
+changequote(,)dnl
+          case $host_os in
+            aix | aix[3-6]*) cf3_cv_func_strndup_works="guessing no";;
+            *)               cf3_cv_func_strndup_works="guessing yes";;
+          esac
+changequote([,])dnl
+         ])])
+    case $cf3_cv_func_strndup_works in
+      *no) AC_LIBOBJ([strndup]) ;;
+    esac
+  else
+    HAVE_STRNDUP=0
+  fi
+])

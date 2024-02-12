--- src/external/nsupdate.m4.orig	2024-01-12 12:05:40 UTC
+++ src/external/nsupdate.m4
@@ -4,13 +4,13 @@ if test -x "$NSUPDATE"; then
   AC_DEFINE_UNQUOTED([NSUPDATE_PATH], ["$NSUPDATE"], [The path to nsupdate])
   AC_MSG_RESULT(yes)
 
-  AC_MSG_CHECKING(for nsupdate 'realm' support')
-  if AC_RUN_LOG([echo realm |$NSUPDATE >&2]); then
-    AC_MSG_RESULT([yes])
-  else
-    AC_MSG_RESULT([no])
-    AC_MSG_ERROR([nsupdate does not support 'realm'])
-  fi
+  #AC_MSG_CHECKING(for nsupdate 'realm' support')
+  #if AC_RUN_LOG([echo realm |$NSUPDATE >&2]); then
+  #  AC_MSG_RESULT([yes])
+  #else
+  #  AC_MSG_RESULT([no])
+  #  AC_MSG_ERROR([nsupdate does not support 'realm'])
+  #fi
 
 else
   AC_MSG_RESULT([no])

--- m4/ax_lib_readline.m4.orig	2013-01-01 17:47:31 UTC
+++ m4/ax_lib_readline.m4
@@ -65,7 +65,7 @@ AC_DEFUN([AX_LIB_READLINE], [
   AC_CACHE_CHECK([for a readline compatible library],
                  ax_cv_lib_readline, [
     ORIG_LIBS="$LIBS"
-    for readline_lib in readline edit editline; do
+    for readline_lib in readline editline; do
       for termcap_lib in "" termcap curses ncurses; do
         if test -z "$termcap_lib"; then
           TRY_LIB="-l$readline_lib"

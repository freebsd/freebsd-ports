--- config/pspell.m4.orig	Thu Jun 20 21:03:56 2002
+++ config/pspell.m4	Wed Oct  2 22:10:21 2002
@@ -12,7 +12,7 @@
         fi
       ])
 
-    AC_ARG_WITH(pspell-includes, [  --with-pspell-include   where the pspell.h is located],
+    AC_ARG_WITH(pspell-include, [  --with-pspell-include   where the pspell.h is located],
       pspell_use_include="$withval",
       pspell_use_include=NONE)
 
@@ -22,7 +22,7 @@
       AC_FIND_FILE(pspell/pspell.h,$pspell_includes,pspell_use_include)
     fi
 
-    AC_ARG_WITH(pspell-libs, [  --with-pspell-lib       where the libpspell.a is located],
+    AC_ARG_WITH(pspell-lib, [  --with-pspell-lib       where the libpspell.a is located],
       pspell_use_lib="$withval",
       pspell_use_lib=NONE)
 

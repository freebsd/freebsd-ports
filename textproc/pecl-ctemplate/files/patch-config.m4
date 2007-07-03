--- config.m4.orig	Tue Jul  3 20:56:50 2007
+++ config.m4	Tue Jul  3 20:56:57 2007
@@ -50,5 +50,5 @@
   PHP_ADD_LIBRARY(pthread)
   PHP_ADD_LIBRARY(stdc++)
   PHP_NEW_EXTENSION(cTemplate, cTemplate.cpp, $ext_shared)
-  CPPFLAGS="$CPPFLAGS -Werror -Wall -g"
+  dnl CPPFLAGS="$CPPFLAGS -Werror -Wall -g"
 fi

Hack for lack of strdupa() in BSD libc

--- action.c.orig	2014-05-10 04:54:13 UTC
+++ action.c
@@ -44,6 +44,12 @@
 #include "action.h"
 #include "error.h"
 
+#ifndef strdupa
+#include <string.h>  // required for str*()
+#include <stdlib.h>  // required for alloca
+#define strdupa(foo) (strncpy( alloca( strlen(foo) + 1 ), foo, strlen( foo ) + 1 ))
+#endif
+
 /*
  * code to parse actions
  */

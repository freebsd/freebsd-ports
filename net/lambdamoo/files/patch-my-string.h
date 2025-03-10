--- my-string.h.orig	2024-10-18 08:41:29 UTC
+++ my-string.h
@@ -72,6 +72,8 @@ extern const char *sys_errlist[];
 #if NDECL_BZERO && !defined(bzero)
 #  if BZERO_IN_STDLIB_H
 #    include "my-stdlib.h"
+#  elif BZERO_IN_STRINGS_H
+#    include <strings.h>
 #  else
 extern void bzero(char *, int);
 #  endif

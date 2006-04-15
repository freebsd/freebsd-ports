--- lib/regex_internal.h.orig	Tue Feb 28 01:36:13 2006
+++ lib/regex_internal.h	Tue Feb 28 01:36:38 2006
@@ -410,8 +410,6 @@
 #define re_string_skip_bytes(pstr,idx) ((pstr)->cur_idx += (idx))
 #define re_string_set_index(pstr,idx) ((pstr)->cur_idx = (idx))
 
-#include <alloca.h>
-
 #ifndef _LIBC
 # if HAVE_ALLOCA
 /* The OS usually guarantees only one guard page at the bottom of the stack,

--- lib/regex_internal.h.orig	Thu May 25 22:03:24 2006
+++ lib/regex_internal.h	Sat Oct 28 10:04:21 2006
@@ -455,8 +455,6 @@
 #define re_string_skip_bytes(pstr,idx) ((pstr)->cur_idx += (idx))
 #define re_string_set_index(pstr,idx) ((pstr)->cur_idx = (idx))
 
-#include <alloca.h>
-
 #ifndef _LIBC
 # if HAVE_ALLOCA
 /* The OS usually guarantees only one guard page at the bottom of the stack,

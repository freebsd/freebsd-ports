diff -urNbB src/include/rl_completion.h.orig src/include/rl_completion.h
--- src/include/rl_completion.h.orig	Sat Dec 16 01:01:06 2006
+++ src/include/rl_completion.h	Sat Dec 16 02:08:02 2006
@@ -6,6 +6,7 @@
 #define SHELLFM_COMPLETION
 
 #include <readline/readline.h>
+#include <time.h>
 #include "strarray.h"
 
 /* a tree composed of this structure will define the completion logic */

--- src/readline.cpp.orig
+++ src/readline.cpp
@@ -23,6 +23,7 @@
 #endif
 
 #include <cstdio>
+#include <cstdlib>
 #ifdef WITH_READLINE
 #  include <readline/readline.h>
 #  include <readline/history.h>

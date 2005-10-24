
$FreeBSD$

--- plugins/check_swap.c.orig
+++ plugins/check_swap.c
@@ -15,6 +15,9 @@
 #include "utils.h"
 
 #define PROGNAME "check_swap"
+#define HAVE_SWAP 1
+#define SWAP_COMMAND "/usr/sbin/swapinfo -k"
+#define SWAP_FORMAT "%*s %d %*d %d"
 
 int process_arguments(int argc, char **argv);
 int call_getopt(int argc, char **argv);

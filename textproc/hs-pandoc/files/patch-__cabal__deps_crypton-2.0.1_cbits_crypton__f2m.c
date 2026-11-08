--- _cabal_deps/crypton-2.0.1/cbits/crypton_f2m.c.orig	2001-09-09 01:46:40 UTC
+++ _cabal_deps/crypton-2.0.1/cbits/crypton_f2m.c
@@ -24,5 +24,6 @@
 #include <stdint.h>
 #include <stdlib.h>
 #include <string.h>
+#include <sys/types.h>
 #include <crypton_cpu.h>
 #include <crypton_f2m.h>

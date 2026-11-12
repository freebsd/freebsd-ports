--- _cabal_deps/crypton-2.2.6/cbits/crypton_f2m.c.orig	2001-09-09 01:46:40 UTC
+++ _cabal_deps/crypton-2.2.6/cbits/crypton_f2m.c
@@ -24,6 +24,7 @@
 #include <stdint.h>
 #include <stdlib.h>
 #include <string.h>
+#include <sys/types.h>
 #include <crypton_cpu.h>
 #include "crypton_armv8_target.h"
 #include <crypton_bzero.h>

--- authenticate/vauthenticate.cc.orig	Mon Feb  2 14:53:58 2004
+++ authenticate/vauthenticate.cc	Mon Feb  2 14:54:10 2004
@@ -16,6 +16,7 @@
 
 #include <config.h>
 #include <errno.h>
+#include <stdlib.h>
 #include <unistd.h>
 #include "authvlib.h"
 #include "fdbuf/fdbuf.h"

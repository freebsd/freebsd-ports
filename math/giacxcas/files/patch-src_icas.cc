--- src/icas.cc.orig	2022-04-11 07:52:40 UTC
+++ src/icas.cc
@@ -47,6 +47,9 @@ using namespace std;
 //#include <unistd.h> // For reading arguments from file
 #include <fcntl.h>
 #include <cstdlib>
+#if defined(__FreeBSD__)
+#include <sys/wait.h>
+#endif
 #include "gen.h"
 #include "index.h"
 #include "sym2poly.h"

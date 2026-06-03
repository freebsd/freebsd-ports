--- lib/src/random.c.orig	2026-04-24 04:41:02 UTC
+++ lib/src/random.c
@@ -23,6 +23,7 @@
 #include <time.h>
 #include <fcntl.h>
 #include <errno.h>
+#include <unistd.h> // for read()
 
 #ifdef HAVE_MPI
 # include "gretl_mpi.h"

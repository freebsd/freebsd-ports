--- src/plugins/mpi/cray_shasta/mpi_cray_shasta.c.orig	2020-04-02 16:02:44 UTC
+++ src/plugins/mpi/cray_shasta/mpi_cray_shasta.c
@@ -39,6 +39,7 @@
 #include <sys/stat.h>
 #include <sys/types.h>
 #include <unistd.h>
+#include <limits.h>
 
 #include "slurm/slurm_errno.h"
 

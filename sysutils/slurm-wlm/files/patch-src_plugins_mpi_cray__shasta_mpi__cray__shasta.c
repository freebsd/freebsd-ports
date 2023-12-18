--- src/plugins/mpi/cray_shasta/mpi_cray_shasta.c.orig	2023-03-28 20:19:41 UTC
+++ src/plugins/mpi/cray_shasta/mpi_cray_shasta.c
@@ -46,6 +46,7 @@
 #include <sys/stat.h>
 #include <sys/types.h>
 #include <unistd.h>
+#include <limits.h>
 
 #include "slurm/slurm_errno.h"
 #include "src/common/slurm_xlator.h"

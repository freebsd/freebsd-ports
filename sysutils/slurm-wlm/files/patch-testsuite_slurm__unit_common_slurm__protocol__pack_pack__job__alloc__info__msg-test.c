--- testsuite/slurm_unit/common/slurm_protocol_pack/pack_job_alloc_info_msg-test.c.orig	2026-03-10 17:13:46 UTC
+++ testsuite/slurm_unit/common/slurm_protocol_pack/pack_job_alloc_info_msg-test.c
@@ -1,4 +1,5 @@
 #include <check.h>
+#include <signal.h>
 #include <stdio.h>
 #include <stdlib.h>
 

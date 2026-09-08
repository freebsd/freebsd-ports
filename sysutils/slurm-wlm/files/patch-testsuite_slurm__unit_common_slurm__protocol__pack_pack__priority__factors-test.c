--- testsuite/slurm_unit/common/slurm_protocol_pack/pack_priority_factors-test.c.orig	2026-08-28 20:13:59 UTC
+++ testsuite/slurm_unit/common/slurm_protocol_pack/pack_priority_factors-test.c
@@ -1,4 +1,5 @@
 #include <check.h>
+#include <signal.h>
 #include <stdio.h>
 #include <stdlib.h>
 

-- Fix division by zero (SIGFPE) when running with a single MPI process.
-- With size=1, groupsize = 1/2 = 0 causes an integer divide-by-zero in the
-- next line. Use max(1, ...) to guard against that.
-- https://github.com/dftbplus/mpifx/issues/35

--- test/test_comm_split.f90.orig	2026-05-13 15:13:45 UTC
+++ test/test_comm_split.f90
@@ -7,7 +7,7 @@ program test_comm_split
 
   call mpifx_init()
   call allproc%init()
-  groupsize = allproc%size / 2
+  groupsize = max(1, allproc%size / 2)
   mygroup = allproc%rank / groupsize
   call allproc%split(mygroup, allproc%rank, groupproc)
   write(*, "(3(A,1X,I0,1X))") "GLOBAL ID:", allproc%rank, "SUBGROUP", &

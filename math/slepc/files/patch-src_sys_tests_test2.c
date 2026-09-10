-- Filter out the -blas_num_threads option line emitted by PETSc when linked
-- with BLAS implementations such as blis, which otherwise makes the test
-- output diff fail in the FreeBSD package build environment.

--- src/sys/tests/test2.c.orig	2026-09-09 11:37:39 UTC
+++ src/sys/tests/test2.c
@@ -44,6 +44,6 @@ int main(int argc,char **argv)
 
    test:
       args: -help
-      filter: sed -e "s/\(Development Git.*\)/version/" | sed -e "s/\(Release Version.*\)/version/" | sed -e "s/\(linked from.*\)/linked from PATH/"
+      filter: sed -e "s/\(Development Git.*\)/version/" | sed -e "s/\(Release Version.*\)/version/" | sed -e "s/\(linked from.*\)/linked from PATH/" | sed -e '/-blas_num_threads/d'
 
 TEST*/

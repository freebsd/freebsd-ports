--- testsuite/panic-tests.sh.orig	2022-01-01 23:00:07 UTC
+++ testsuite/panic-tests.sh
@@ -18,6 +18,8 @@ print_ver_ sed
 . "${srcdir=.}/testsuite/init.sh"; path_prepend_ ./sed
 print_ver_ sed
 
+test $(id -u) != 0 || exit 77 # these tests pass unexpectedly if run as root
+
 #
 # failure to create temp file
 #

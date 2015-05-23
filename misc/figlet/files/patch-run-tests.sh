--- run-tests.sh.orig	2012-06-01 05:51:10.000000000 -0700
+++ run-tests.sh	2012-12-04 09:28:49.000000000 -0800
@@ -7 +7 @@ TESTDIR=tests
-OUTPUT=`mktemp`
+OUTPUT=`mktemp -t tmp.XXXXXXXXXX` # Per the Fedora release 8 (Werewolf) man page
@@ -70 +70 @@ run_test 020 "specify font directory" \
-  "X=`mktemp -d`;cp fonts/script.flf \$X/foo.flf;$cmd -d\$X -ffoo;rm -Rf \$X"
+  "X=`mktemp -d -t tmp.XXXXXXXXXX`;cp fonts/script.flf \$X/foo.flf;$cmd -d\$X -ffoo;rm -Rf \$X"

diff -ruN frontpage.orig/version5.0/set_default_perms.sh frontpage/version5.0/set_default_perms.sh
--- frontpage.orig/version5.0/set_default_perms.sh	Thu Jan  9 12:19:35 2003
+++ frontpage/version5.0/set_default_perms.sh	Tue Feb  4 18:38:21 2003
@@ -36,10 +36,9 @@
 chown bin $FPDIR/frontpage.cnf || die chown frontpage.cnf
 chgrp bin $FPDIR/frontpage.cnf || die chgrp frontpage.cnf
 chmod 664 $FPDIR/frontpage.cnf || die chmod frontpage.cnf
-chown bin $FPDIR/*.sh $FPDIR/*.TXT $FPDIR/*.htm || die chown top level files
-chgrp bin $FPDIR/*.sh $FPDIR/*.TXT $FPDIR/*.htm || die chgrp top level files
-chmod 555 $FPDIR/*.sh                           || die chmod top level files
-chmod 444             $FPDIR/*.TXT $FPDIR/*.htm || die chmod top level files
+chown bin $FPDIR/*.sh || die chown top level files
+chgrp bin $FPDIR/*.sh || die chgrp top level files
+chmod 555 $FPDIR/*.sh || die chmod top level files
 
 # Handle all of the non apache-fp directory trees
 for dir in bin nls admin exes help ; do
@@ -79,9 +78,6 @@
 
 # The apache-fp fpexe stub needs to be suid root
 chmod 4755 $FPDIR/apache-fp/_vti_bin/fpexe || die set fpexe to be suid
-
-# Set httpd
-chmod 555  $FPDIR/apache-fp/httpd || die make httpd executable
 
 # The apache-fp directory should not be writable to protect the stub program.
 chmod 555  $FPDIR/apache-fp/_vti_bin || die restrict the apache-fp directory

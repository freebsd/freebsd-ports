--- frontpage/version5.0/set_default_perms.sh.orig	Fri Apr 20 09:00:58 2001
+++ frontpage/version5.0/set_default_perms.sh	Wed May  2 19:20:58 2001
@@ -81,7 +81,7 @@
 chmod 4755 $FPDIR/apache-fp/_vti_bin/fpexe || die set fpexe to be suid
 
 # Set httpd
-chmod 555  $FPDIR/apache-fp/httpd || die make httpd executable
+#chmod 555  $FPDIR/apache-fp/httpd || die make httpd executable
 
 # The apache-fp directory should not be writable to protect the stub program.
 chmod 555  $FPDIR/apache-fp/_vti_bin || die restrict the apache-fp directory

--- ca-bundle.pl.orig	2010-02-05 10:08:58.000000000 -0500
+++ ca-bundle.pl	2010-02-05 10:13:35.000000000 -0500
@@ -1,32 +1,20 @@
 ##
-##  ca-bundle.pl -- Regenerate ca-bundle.crt from the Mozilla certdata.txt
+##  ca-bundle.pl -- Regenerate ca-root-nss.crt from the Mozilla certdata.txt
 ##
 
 #   configuration
-my $cvsroot  = ':pserver:anonymous@cvs-mirror.mozilla.org:/cvsroot';
-my $certdata = 'mozilla/security/nss/lib/ckfw/builtins/certdata.txt';
-
-my $date = `date`;
-$date =~ s/\n$//s;
 print <<EOH;
 ##
-##  ca-bundle.crt -- Bundle of CA Root Certificates
+##  ca-root-nss.crt -- Bundle of CA Root Certificates
 ##
 ##  This is a bundle of X.509 certificates of public Certificate
 ##  Authorities (CA). These were automatically extracted from Mozilla's
-##  root CA list (the file `certdata.txt'). It contains the certificates
-##  in both plain text and PEM format and therefore can be directly used
-##  with an Apache/mod_ssl webserver for SSL client authentication. Just
-##  configure this file as the SSLCACertificateFile.
-##
-##  (SKIPME)
+##  root CA list (the file `certdata.txt').
 ##
-##  Last Modified: $date
+##  Extracted from nss-%%VERSION_NSS%%
 EOH
-open(IN, "cvs -d $cvsroot co -p $certdata|")
-    || die "could not check out certdata.txt";
 my $incert = 0;
-while (<IN>) {
+while (<STDIN>) {
     if (/^CKA_VALUE MULTILINE_OCTAL/) {
         $incert = 1;
         open(OUT, "|openssl x509 -text -inform DER -fingerprint")

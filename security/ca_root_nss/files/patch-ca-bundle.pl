
$FreeBSD$

--- ca-bundle.pl.orig
+++ ca-bundle.pl
@@ -3,30 +3,18 @@
 ##
 
 #   configuration
-my $cvsroot  = ':pserver:anonymous@cvs-mirror.mozilla.org:/cvsroot';
-my $certdata = 'mozilla/security/nss/lib/ckfw/builtins/certdata.txt';
-
-my $date = `date`;
-$date =~ s/\n$//s;
 print <<EOH;
 ##
 ##  ca-bundle.crt -- Bundle of CA Root Certificates
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

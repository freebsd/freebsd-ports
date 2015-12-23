--- pulledpork.pl.orig	2015-12-16 18:01:13 UTC
+++ pulledpork.pl
@@ -61,8 +61,8 @@ if ($oSystem =~ /freebsd/i) {
  	   exit(1);
         }
     #Check for the other location for the cert file
-    } elsif ( -e "/usr/local/etc/ssl/cert.pem" ) {
-    	$CAFile = "/usr/local/etc/ssl/cert.pem";
+    } elsif ( -e "/usr/local/share/certs/ca-root-nss.crt" ) {
+    	$CAFile = "/usr/local/share/certs/ca-root-nss.crt";
         if ( -r $CAFile) {
            $ua->ssl_opts( SSL_ca_file => $CAFile );
         } else {	
@@ -72,7 +72,7 @@ if ($oSystem =~ /freebsd/i) {
  	   exit(1);
         }
     } else {
-           carp "ERROR: cert file does not exist (/etc/ssl/cert.pem or /usr/local/etc/ssl/cert.pem) Ensure that the ca_root_nss port/pkg is installed, or use -w to skip SSL verification\n";
+           carp "ERROR: cert file does not exist (/etc/ssl/cert.pem or /usr/local/share/certs/ca-root-nss.crt) Ensure that the ca_root_nss port/pkg is installed, or use -w to skip SSL verification\n";
            syslogit( 'err|local0', "FATAL: cert file does not exist. Ensure that the ca_root_nss port/pkg is installed, or use -w to skip SSL verification\n")
            if $Syslogging;
            exit(1);

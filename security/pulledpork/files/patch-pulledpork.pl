--- pulledpork.pl.orig	2017-12-07 15:13:06 UTC
+++ pulledpork.pl
@@ -90,9 +90,24 @@ if ($oSystem =~ /freebsd/i) {
             exit(1);
         }
     }
+    elsif (-e "/usr/local/share/certs/ca-root-nss.crt") {
+        $CAFile = "/usr/local/share/certs/ca-root-nss.crt";
+        if (-r $CAFile) {
+            $ua->ssl_opts(SSL_ca_file => $CAFile);
+        }
+        else {
+            carp "ERROR: $CAFile is not readable by "
+                . (getpwuid($<))[0] . "\n";
+            syslogit('err|local0',
+                "FATAL: ERROR: $CAFile is not readable by "
+                    . (getpwuid($<))[0] . "\n")
+                if $Syslogging;
+            exit(1);
+        }
+    }
     else {
         carp
-            "ERROR: cert file does not exist (/etc/ssl/cert.pem or /usr/local/etc/ssl/cert.pem) Ensure that the ca_root_nss port/pkg is installed, or use -w to skip SSL verification\n";
+            "ERROR: cert file does not exist (/etc/ssl/cert.pem, /usr/local/etc/ssl/cert.pem or /usr/local/share/certs/ca-root-nss.crt) Ensure that the ca_root_nss port/pkg is installed, or use -w to skip SSL verification\n";
         syslogit('err|local0',
             "FATAL: cert file does not exist. Ensure that the ca_root_nss port/pkg is installed, or use -w to skip SSL verification\n"
         ) if $Syslogging;

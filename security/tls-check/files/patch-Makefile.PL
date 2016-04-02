--- Makefile.PL.orig	2016-04-02 19:57:34 UTC
+++ Makefile.PL
@@ -5,7 +5,6 @@ WriteMakefile
   'VERSION_FROM' => 'lib/Security/TLSCheck.pm',
   'NAME' => 'Security::TLSCheck',
   'EXE_FILES' => [
-                   'bin/.DS_Store',
                    'bin/check_ciphers_single_domains.pl',
                    'bin/csv-result-to-summary.pl',
                    'bin/tls-check-parallel.pl',

--- inst/required.pl.orig	Sat May 22 14:08:58 2004
+++ inst/required.pl	Sat May 22 14:28:35 2004
@@ -67,6 +67,10 @@
 our %REQ;
 our %RESULTS;
 
+# check to see whether we should ask questions or not
+our $QUIET;
+$QUIET = 1 if $ARGV[0] and $ARGV[0] eq 'QUIET';
+
 # collect data - configuration requirements data goes into %REQ, raw
 # binary pass/fail goes into %RESULTS.
 
@@ -125,12 +129,12 @@
     # confirm or deny
     if ($REQ{PG_CONFIG}) {
         print "Found PostgreSQL's pg_config at '$REQ{PG_CONFIG}'.\n";
-        unless (ask_yesno("Is this correct? [yes] ", 1)) {
+        unless ($QUIET or ask_yesno("Is this correct? [yes] ", 1)) {
             ask_confirm("Enter path to pg_config", \$REQ{PG_CONFIG});
         }
     } else {
         print "Failed to find pg_config.\n";
-        if (ask_yesno("Do you want to provide a path to pg_config? [no] ",
+        if (!$QUIET and ask_yesno("Do you want to provide a path to pg_config? [no] ",
                       0)) {
             $REQ{PG_CONFIG} = 'NONE';
             ask_confirm("Enter path to pg_config", \$REQ{PG_CONFIG});
@@ -192,13 +196,13 @@
     # confirm or deny
     if ($REQ{APACHE_EXE}) {
         print "Found Apache server binary at '$REQ{APACHE_EXE}'.\n";
-        unless (ask_yesno("Is this correct? [yes] ", 1)) {
+        unless ($QUIET or ask_yesno("Is this correct? [yes] ", 1)) {
             ask_confirm("Enter path to Apache server binary", 
                         \$REQ{APACHE_EXE});
         }
     } else {
         print "Failed to find Apache server binary.\n";
-        if (ask_yesno("Do you want to provide a path to the Apache server " .
+        if (!$QUIET and ask_yesno("Do you want to provide a path to the Apache server " .
                       "binary? [no] ",
                       0)) {
             $REQ{APACHE_EXE} = 'NONE';

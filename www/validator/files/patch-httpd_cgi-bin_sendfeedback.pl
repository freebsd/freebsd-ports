--- httpd/cgi-bin/sendfeedback.pl.orig	2012-03-12 15:03:14 UTC
+++ httpd/cgi-bin/sendfeedback.pl
@@ -23,7 +23,7 @@ use constant FALSE => 0;
 # environments, such as mod_perl.  So let's do globals, eg. read config here.
 BEGIN {
 
-    my $base = $ENV{W3C_VALIDATOR_HOME} || '/usr/local/validator';
+    my $base = $ENV{W3C_VALIDATOR_HOME} || '%%WWWDIR%%';
 
     # Launder data for -T; -AutoLaunder doesn't catch this one.
     if ($base =~ /^(.*)$/) {
@@ -35,7 +35,7 @@ BEGIN {
     eval {
         my %config_opts = (
             -ConfigFile =>
-                ($ENV{W3C_VALIDATOR_CFG} || '/etc/w3c/validator.conf'),
+                ($ENV{W3C_VALIDATOR_CFG} || '%%WWWDIR%%/htdocs/config/validator.conf'),
             -MergeDuplicateOptions => TRUE,
             -MergeDuplicateBlocks  => TRUE,
             -SplitPolicy           => 'equalsign',

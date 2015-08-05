--- Makefile.PL.orig	2010-04-24 12:37:38 UTC
+++ Makefile.PL
@@ -210,7 +210,7 @@ sub find_krb5config_cmd {
    my $r = undef;
    unless ($expl_path) {
       #my $whichcmd =  find_which_command() || die 'cannot locate which command';
-      $r = `which krb5-config 2>/dev/null`;
+      $r = '%%KRB5CONF%%';
 
       chomp $r;
       unless ( $r ) {

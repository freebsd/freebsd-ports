--- check_perl_modules.pl	2003/11/28 18:16:39
+++ check_perl_modules.pl	2003/12/08 22:37:28
@@ -155,6 +162,8 @@
 sub install_module {
     my ($module, $default) = @_;
 
+    return if $ENV{'PERL_EXTUTILS_AUTOINSTALL'} =~ /--skip|--default/;
+
     unless ($ENV{'FTP_PASSIVE'} eq 1) {
 	$ENV{'FTP_PASSIVE'} = 1;
 	print "Setting FTP Passive mode\n";
@@ -171,7 +180,7 @@
     print "Install module $module ? [$default]";
     my $answer = <STDIN>; chomp $answer;
     $answer ||= $default;
-    next unless ($answer =~ /^y$/i);
+    return unless ($answer =~ /^y$/i);
   CPAN::Shell->conf('inactivity_timeout', 4);
     CPAN::Shell->install($module);
 }

--- Makefile.PL.orig	2007-03-31 16:16:20 UTC
+++ Makefile.PL
@@ -33,7 +33,7 @@ for (my $i = 0 ; $i < scalar(@ARGV) ; $i++){
 # preliminary checks
 #------------------------------------------------------------------------
 # Mandatory perl modules
-foreach my $module qw(Data::Dumper Time::HiRes Locale::Maketext) {
+foreach my $module (qw(Data::Dumper Time::HiRes Locale::Maketext)) {
   print "Checking whether $module perl module is available... ";
   eval "use $module";
   if ($@) {

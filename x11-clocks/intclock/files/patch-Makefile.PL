--- ./Makefile.PL.orig	2014-08-28 18:50:07.282934874 +0100
+++ ./Makefile.PL	2014-08-28 18:50:28.962268980 +0100
@@ -33,7 +33,7 @@
 # preliminary checks
 #------------------------------------------------------------------------
 # Mandatory perl modules
-foreach my $module qw(Data::Dumper Time::HiRes Locale::Maketext) {
+foreach my $module (qw(Data::Dumper Time::HiRes Locale::Maketext)) {
   print "Checking whether $module perl module is available... ";
   eval "use $module";
   if ($@) {

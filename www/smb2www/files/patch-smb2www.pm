--- cgi-bin/smb2www.pm.orig	Thu May 25 11:07:02 2000
+++ cgi-bin/smb2www.pm	Tue Jul 18 12:30:44 2000
@@ -371,7 +371,7 @@
 sub GetSMBShr {
   my $share = $_[0];
   my @ret = ();
-  my $lookup = "$cfg{bindir}/smbclient -L \"$share\" -d0";
+  my $lookup = "$cfg{bindir}/smbclient -N -L \"$share\" -d0";
   my @out = `$lookup`;
   my $line = shift @out;
   while ( (not $line =~ /^\s+Sharename/) and ($#out >= -1) ) {
@@ -406,13 +406,14 @@
 sub GetSMBHosts {
   my ($workgroup,$host) = @_;
   my @ret = ();
-  my $lookup = "$cfg{bindir}/smbclient -L \"$host\" -W \"$workgroup\" -d0";
+  my $lookup = "$cfg{bindir}/smbclient -N -L \"$host\" -W \"$workgroup\" -d0";
   my @out = `$lookup`;
   my $line = shift @out;
 
-  while ((not $line =~ /^This machine has a browse list/) and ($#out >= -1) ) {
+  while ((not $line =~ /^\s+Server\s+Comment/) and ($#out >= -1) ) {
     $line = shift @out;
   }
+  shift @out;
   if ($#out >= -1) {
     $line = shift @out;
     $line = shift @out;
@@ -437,16 +438,14 @@
 
 sub GetSMBGroups {
   my @ret = ();
-  my $lookup = "$cfg{bindir}/smbclient -L \"$cfg{masterbrowser}\" -d0";
+  my $lookup = "$cfg{bindir}/smbclient -N -L \"$cfg{masterbrowser}\" -d0";
   my @out = `$lookup`;
   my $line = shift @out;
 
-  while ((not $line =~ /^This machine has a workgroup list/) and ($#out >= 0) ) {
+  while ((not $line =~ /^\s+Workgroup\s+Master/) and ($#out >= 0) ) {
     $line = shift @out;
   }
   if ($#out >= -1) {
-    $line = shift @out;
-    $line = shift @out;
     $line = shift @out;
     $line = shift @out;
     while ((not $line =~ /^$/) and ($#out >= -1) ) {

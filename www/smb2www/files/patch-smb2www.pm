--- cgi-bin/smb2www.pm.orig	Wed Jul 25 14:22:50 2001
+++ cgi-bin/smb2www.pm	Wed Jul 25 15:49:02 2001
@@ -26,6 +26,7 @@
 package smb2www;
 use Exporter ();
 
+use POSIX ":sys_wait_h";
 use MIME::Base64;
 use Time::Local; # for lmtime
 use strict;
@@ -289,6 +290,7 @@
   if ( $target eq "") { $target = "-" };
   $file =~ s/^(.*)\/([^\/]*)$/$1$2/ ;
   if ( $user ne "" ) { $user="-U$user"; }
+  else { $user = "-Uguest"; }
   if ( $pass ne "") { 
     if ( $user eq "" ) {
       $user = "-Uguest";
@@ -296,9 +298,14 @@
   } else { 
     $pass = "-N";
   }
-  my @args = ("$cfg{bindir}/smbclient", "//$host/$share", "$pass", "$user",  "-d
-  0", "-c", "get \"$file\" $target");
-  return system (@args);
+  my @args = ("$cfg{bindir}/smbclient", "//$host/$share", "$pass", "$user",  "-d0", "-c", "get $file $target");
+  my $pid=fork();
+  if (!$pid) {
+    exec (@args); 
+    return 1;
+  }
+  waitpid(-1, &WNOHANG);
+  return 0;
 }
 
 # Makes a TAR of //$host/$share/$dir, using $user and $pass, to $target.
@@ -317,8 +324,14 @@
   } else { 
     $pass = "-N";
   }
-  my @args = ("$cfg{bindir}/smbclient", "//$host/$share", "$pass", "$user", "-d0 ", "-D", "$dir", "-Tc", "$target");
-  return system (@args);
+  my @args = ("$cfg{bindir}/smbclient", "//$host/$share", "$pass", "$user", "-d0", "-D", "$dir", "-Tc", "$target");
+  my $pid=fork();
+  if (!$pid) {
+    exec (@args);
+    return 1;
+  }
+  waitpid(-1, &WNOHANG);
+  return 0;
 }
 
 # Return an array with sorted dir and filelisting
@@ -371,7 +384,7 @@
 sub GetSMBShr {
   my $share = $_[0];
   my @ret = ();
-  my $lookup = "$cfg{bindir}/smbclient -L \"$share\" -d0";
+  my $lookup = "$cfg{bindir}/smbclient -N -L \"$share\" -d0";
   my @out = `$lookup`;
   my $line = shift @out;
   while ( (not $line =~ /^\s+Sharename/) and ($#out >= -1) ) {
@@ -406,18 +419,16 @@
 sub GetSMBHosts {
   my ($workgroup,$host) = @_;
   my @ret = ();
-  my $lookup = "$cfg{bindir}/smbclient -L \"$host\" -W \"$workgroup\" -d0";
+  my $lookup = "$cfg{bindir}/smbclient -N -L \"$host\" -W \"$workgroup\" -d0";
   my @out = `$lookup`;
   my $line = shift @out;
 
-  while ((not $line =~ /^This machine has a browse list/) and ($#out >= -1) ) {
+  while ((not $line =~ /^\tServer\s+Comment$/) and ($#out >= -1) ) {
     $line = shift @out;
   }
+  shift @out;
+  $line = shift @out;
   if ($#out >= -1) {
-    $line = shift @out;
-    $line = shift @out;
-    $line = shift @out;
-    $line = shift @out;
     while ((not $line =~ /^$/) and ($#out >= -1)) {
       if ( $line =~ /^\t([\S ]*\S) {5,}(\S[\S ]*|\S|)$/ ) {
         my $rec = {};
@@ -437,16 +448,14 @@
 
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

--- ../MailScanner-install-4.34.8.orig/lib/MailScanner/SweepViruses.pm	Fri Oct 22 10:23:15 2004
+++ lib/MailScanner/SweepViruses.pm	Fri Oct 22 10:23:34 2004
@@ -2,7 +2,7 @@
 #   MailScanner - SMTP E-Mail Virus Scanner
 #   Copyright (C) 2002  Julian Field
 #
-#   $Id: SweepViruses.pm,v 1.49.2.85 2004/09/28 20:18:51 jkf Exp $
+#   $Id: SweepViruses.pm,v 1.49.2.87 2004/10/21 19:40:25 jkf Exp $
 #
 #   This program is free software; you can redistribute it and/or modify
 #   it under the terms of the GNU General Public License as published by
@@ -41,7 +41,7 @@
 use vars qw($VERSION $ScannerPID);
 
 ### The package version, both in 1.23 style *and* usable by MakeMaker:
-$VERSION = substr q$Revision: 1.49.2.85 $, 10;
+$VERSION = substr q$Revision: 1.49.2.87 $, 10;
 
 # Locking definitions for flock() which is used to lock the Lock file
 my($LOCK_SH) = 1;
@@ -426,6 +426,12 @@
   MailScanner::Log::DieLog("ClamAV Perl module not found, did you install it?")
     unless eval 'require Mail::ClamAV';
 
+  my $ver = $Mail::ClamAV::VERSION + 0.0;
+  MailScanner::Log::DieLog("ClamAV Perl module must be at least version 0.12" .
+                           " and you only have version %.2f, and ClamAV must" .
+                           " be at least version 0.80", $ver)
+    unless $ver >= 0.12;
+
   $Clam = new Mail::ClamAV(Mail::ClamAV::retdbdir())
     or MailScanner::Log::DieLog("ClamAV Module ERROR:: Could not load " .
        "databases from %s", Mail::ClamAV::retdbdir());
@@ -984,11 +990,17 @@
     while($filename = $child->read()) {
       next unless -f "$dirname/$childname/$filename"; # Only check files
       # JKF Patch suggested by Rick Cooper to support unrar and OLE2 files
-      #$results = $Clam->scan("$dirname/$childname/$filename", Mail::ClamAV::CL_ARCHIVE());
+      #$results = $Clam->scan("$dirname/$childname/$filename",
+      #                       Mail::ClamAV::CL_SCAN_ARCHIVE());
       if (MailScanner::Config::Value('allowpasszips')) { # || $haverar) {
-        $results = $Clam->scan("$dirname/$childname/$filename", Mail::ClamAV::CL_ARCHIVE() | Mail::ClamAV::CL_OLE2());
+        $results = $Clam->scan("$dirname/$childname/$filename",
+                               Mail::ClamAV::CL_SCAN_ARCHIVE() |
+                               Mail::ClamAV::CL_SCAN_OLE2());
       } else {
-        $results = $Clam->scan("$dirname/$childname/$filename", Mail::ClamAV::CL_ARCHIVE() | Mail::ClamAV::CL_ENCRYPTED() | Mail::ClamAV::CL_OLE2());
+        $results = $Clam->scan("$dirname/$childname/$filename",
+                               Mail::ClamAV::CL_SCAN_ARCHIVE() |
+                               Mail::ClamAV::CL_SCAN_BLOCKENCRYPTED() |
+                               Mail::ClamAV::CL_SCAN_OLE2());
       }
 
       unless ($results) {

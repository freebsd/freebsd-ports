--- lib/Filesys/DiskSpace.pm.old	Sun Sep  5 18:41:22 1999
+++ lib/Filesys/DiskSpace.pm	Fri Jun 17 13:20:44 2005
@@ -44,7 +44,7 @@
 sub df ($) {
   my $dir = shift;
 
-  my ($fmt, $res, $type, $flags, $osvers, $w);
+  my ($fmt, $res, $type, $typestr, $flags, $osvers, $w);
 
   # struct fields for statfs or statvfs....
   my ($bsize, $frsize, $blocks, $bfree, $bavail, $files, $ffree, $favail);
@@ -53,7 +53,8 @@
   Carp::croak "Error: $dir is not a directory" unless -d $dir;
 
   # try with statvfs..
-  eval {  # will work for Solaris 2.*, OSF1 v3.2, OSF1 v4.0 and HP-UX 10.*.
+  ($^O ne 'freebsd' &&
+   eval {  # will work for Solaris 2.*, OSF1 v3.2, OSF1 v4.0 and HP-UX 10.*.
     {
       package main;
       require "sys/syscall.ph";
@@ -78,7 +79,7 @@
     $bsize = $frsize;
     # $blocks -= $bfree - $bavail;
     $res == 0 && defined $fs_type{$type};
-  }
+  })
   # try with statfs..
   || eval { # will work for SunOS 4, Linux 2.0.* and 2.2.*
     {
@@ -90,11 +91,37 @@
     # statfs...
 
     if ($^O eq 'freebsd') {
-      # only tested with FreeBSD 3.0. Should also work with 4.0.
-      my ($f1, $f2);
-      ($f1, $bsize, $f2, $blocks, $bfree, $bavail, $files, $ffree) =
-	unpack "L8", $fmt;
-      $type = 0; # read it from 'f_type' field ?
+      $type = 0;
+      {
+        package main;
+        require "sys/param.ph";
+        require "sys/mount.ph";
+      }
+      my $STATFS_VERSION;
+      if (defined(&main::STATFS_VERSION)) {
+        $STATFS_VERSION = &main::STATFS_VERSION;
+      }
+      if (defined($STATFS_VERSION)) {
+        my ($version, $f1);
+        my $crap =
+           "Q4" .   # f_syncwrites, f_asyncwrites, f_syncreads, f_asyncreads
+           "Q10" .  # f_spare[10]
+           "Lll2" . # f_namemax, f_owner, f_fsid
+           "c80";    # MFSNAMELEN
+        my $MFSNAMELEN = &main::MFSNAMELEN;
+        ($version, $f1, $flags, $bsize, $frsize, $blocks,
+         $bfree, $bavail, $files, $ffree, $typestr) =
+          unpack "L2Q5qQqx[$crap]Z$MFSNAMELEN", $fmt;
+        if ($STATFS_VERSION != 0x20030518) {
+          warn "Unknown STATFS_VERSION ($STATFS_VERSION) results may be bad.\n";
+        }
+      }
+      else {
+        # only tested with FreeBSD 3.0. Should also work with 4.0.
+        my ($f1, $f2);
+        ($f1, $bsize, $f2, $blocks, $bfree, $bavail, $files, $ffree) =
+         unpack "L8", $fmt;
+      }
     }
     else {
       ($type, $bsize, $blocks, $bfree, $bavail, $files, $ffree) =
@@ -108,7 +135,7 @@
     # files:  total file nodes in file system
     # ffree:  free file nodes in fs
 
-    $res == 0 && defined $fs_type{$type};
+    $res == 0 && (defined $typestr || defined $fs_type{$type});
   }
   || eval {
     {
@@ -170,7 +197,7 @@
   }
 
   warn "Warning : type $fs_type{$type} untested.. results may be incorrect\n"
-    unless $type != 2560  && defined $fs_type{$type};
+    unless defined($typestr) || ($type != 2560  && defined $fs_type{$type});
 
   if ($DEBUG) {
     warn "Fs type : [$type] $fs_type{$type}\n" .
@@ -185,7 +212,8 @@
     }
   }
 
-  ($type, $fs_type{$type}, ($blocks - $bavail) * $bsize / 1024,
+  ($type, (defined($typestr) ? $typestr : $fs_type{$type}),
+   ($blocks - $bavail) * $bsize / 1024,
    $bavail * $bsize / 1024, $files - $ffree, $ffree);
 }
 

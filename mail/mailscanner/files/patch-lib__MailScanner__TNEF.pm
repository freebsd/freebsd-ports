--- ./lib/MailScanner/TNEF.pm.orig	2013-06-17 09:29:16.000000000 -0400
+++ ./lib/MailScanner/TNEF.pm	2014-02-21 04:03:15.000000000 -0500
@@ -229,18 +229,25 @@
 
   # Create the subdir to unpack it into
   #my $unpackdir = "tnef.$$";
-  my ($tmpfh, $unpackdir) = tempfile("tnefXXXXXX", TMPDIR => $dir, UNLINK => 0);
-  # This line shouldn't be here any more! $dir =~ s,^.*/,,;
-  $unpackdir = $message->MakeNameSafe($unpackdir, $dir);
-  unless (mkdir "$dir/$unpackdir", 0777) {
+  my $unpackdir = tempdir("tnefXXXXXX", DIR => $dir);
+  unless (-d $unpackdir) {
     MailScanner::Log::WarnLog("Trying to unpack %s in message %s, could not create subdirectory %s, failed to unpack TNEF message", $tnefname, $message->{id},
-                              "$dir/$unpackdir");
+                              "$unpackdir");
     return 0;
   }
-  chmod 0700, "$dir/$unpackdir";
+  # Convert Incoming Work Permissions to an octal value and add search.
+  my $perms = oct(sprintf("%s", MailScanner::Config::Value('workperms')))
+    | 0111;
+  chmod $perms, $unpackdir;
+  # Try to set Incoming Work User and Group.
+  my $uname = MailScanner::Config::Value('workuser');
+  my $gname = MailScanner::Config::Value('workgroup');
+  my $uid = $uname?getpwnam($uname):-1;
+  my $gid = $gname?getgrnam($gname):-1;
+  chown $uid, $gid, $unpackdir;
 
   my $cmd = MailScanner::Config::Value('tnefexpander') .
-            " -f $dir/$tnefname -C $dir/$unpackdir --overwrite";
+            " -f $dir/$tnefname -C $unpackdir --overwrite";
 
   my($kid);
   my($TimedOut, $PipeReturn, $pid);
@@ -311,15 +318,15 @@
 
     unless (MailScanner::Config::Value('replacetnef',$message) =~ /[12]/) {
       # Just need to move all the unpacked files into the main attachments dir
-      my $dirh = new DirHandle "$dir/$unpackdir";
+      my $dirh = new DirHandle "$$unpackdir";
       return 0 unless defined $dirh;
       while (defined(my $unpacked = $dirh->read)) {
-        next unless -f "$dir/$unpackdir/$unpacked";
+        next unless -f "$$unpackdir/$unpacked";
         # Add a 't' to the safename to mark it as a tnef member.
         my $safe = $message->MakeNameSafe('t'.$unpacked, $dir);
         # This will cause big problems as $safe has a type, and shouldn't!
         $message->{file2parent}{$safe} = $tnefname;
-        my $name1 = "$dir/$unpackdir/$unpacked";
+        my $name1 = "$unpackdir/$unpacked";
         $name1 =~ /(.*)/;
         $name1 = $1;
         my $name2 = "$dir/$safe";
@@ -333,19 +340,21 @@
         $safe =~ s#^(.*/)([^/])([^/]+)$#$1$3#; # I assert $2 will equal 't'.
         $message->{file2parent}{$safe} = $tnefname;
       }
-      rmdir "$dir/$unpackdir"; # Directory should be empty now
+      # The following may result in a warning from a virus scanner that
+      # tries to lstat the directory, but it was empty so it can be ignored.
+      rmdir "$$unpackdir"; # Directory should be empty now
       return 1;
     }
     #print STDERR "In TNEF External Decoder\n";
 
-    my $dirh = new DirHandle "$dir/$unpackdir";
+    my $dirh = new DirHandle "$unpackdir";
     return 0 unless defined $dirh;
     my($type, $encoding);
     $message->{entity}->make_multipart;
     my($safename, @replacements, $unpacked);
     while (defined($unpacked = $dirh->read)) {
-      #print STDERR "Directory entry is \"$unpacked\" in \"$dir/$unpackdir\"\n";
-      next unless -f "$dir/$unpackdir/$unpacked";
+      #print STDERR "Directory entry is \"$unpacked\" in \"$unpackdir\"\n";
+      next unless -f "$unpackdir/$unpacked";
       # Add a 't' to the safename to mark it as a tnef member.
       $safename = $message->MakeNameSafe('t'.$unpacked, $dir);
       if (/^msg[\d-]+\.txt$/) {
@@ -353,15 +362,15 @@
       } else {
         ($type, $encoding) = ("application/octet-stream", "base64");
       }
-      #print STDERR "Renaming '$dir/$unpackdir/$unpacked' to '$dir/$safename'\n";
-      my $oldname = "$dir/$unpackdir/$unpacked";
+      #print STDERR "Renaming '$unpackdir/$unpacked' to '$dir/$safename'\n";
+      my $oldname = "$unpackdir/$unpacked";
       my $newname = "$dir/$safename";
       $oldname =~ /^(.*)$/;
       $oldname = $1;
       $newname =~ /^(.*)$/;
       $newname = $1;
       rename $oldname, $newname;
-      #rename "$dir/$unpackdir/$unpacked", "$dir/$safename";
+      #rename "$unpackdir/$unpacked", "$dir/$safename";
       # JKF 20090421 CHMOD, then CHOWN and CHGRP it if necessary.
       chmod $perms, $newname;
       #chmod $perms, "$dir/$safename";
@@ -381,7 +390,9 @@
     $message->{bodymodified} = 1;
     $message->{foundtnefattachments} = 1;
     undef $dirh;
-    rmdir "$dir/$unpackdir"; # Directory should be empty now
+    # The following may result in a warning from a virus scanner that
+    # tries to lstat the directory, but it was empty so it can be ignored.
+    rmdir "$unpackdir"; # Directory should be empty now
     #$message->{entity}->dump_skeleton();
 
     MailScanner::Log::InfoLog("Message %s added TNEF contents %s",

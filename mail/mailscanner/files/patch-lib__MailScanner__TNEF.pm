--- ./lib/MailScanner/TNEF.pm.orig	2011-08-20 08:32:02.000000000 -0400
+++ ./lib/MailScanner/TNEF.pm	2012-03-15 11:28:31.000000000 -0400
@@ -229,15 +229,14 @@
 
   # Create the subdir to unpack it into
   #my $unpackdir = "tnef.$$";
-  my ($tmpfh, $unpackdir) = tempfile("tnefXXXXXX", TMPDIR => $dir, UNLINK => 0);
-  $dir =~ s,^.*/,,;
+  my $unpackdir = tempdir("tnefXXXXXX");
   $unpackdir = $message->MakeNameSafe($unpackdir, $dir);
   unless (mkdir "$dir/$unpackdir", 0777) {
     MailScanner::Log::WarnLog("Trying to unpack %s in message %s, could not create subdirectory %s, failed to unpack TNEF message", $tnefname, $message->{id},
                               "$dir/$unpackdir");
     return 0;
   }
-  chmod 0700, "$dir/$unpackdir";
+  chmod 0770, "$dir/$unpackdir";
 
   my $cmd = MailScanner::Config::Value('tnefexpander') .
             " -f $dir/$tnefname -C $dir/$unpackdir --overwrite";

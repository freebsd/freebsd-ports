--- Session/Lock/File.pm.orig	Sat Sep  2 00:21:17 2000
+++ Session/Lock/File.pm	Thu Dec  6 17:37:40 2001
@@ -36,8 +36,9 @@
         
         my $LockDirectory = $session->{args}->{LockDirectory} || 
             $Apache::Session::Lock::File::LockDirectory;
+        my $LockFile = $LockDirectory."/Apache-Session-".$session->{data}->{_session_id}.".lock";
             
-        open($fh, "+>".$LockDirectory."/Apache-Session-".$session->{data}->{_session_id}.".lock") || die $!;
+        open($fh, "+> $LockFile") || die "$LockFile: $!";
 
         $self->{fh} = $fh;
         $self->{opened} = 1;
@@ -58,8 +59,9 @@
         
         my $LockDirectory = $session->{args}->{LockDirectory} || 
             $Apache::Session::Lock::File::LockDirectory;
+        my $LockFile = $LockDirectory."/Apache-Session-".$session->{data}->{_session_id}.".lock";
             
-        open($fh, "+>".$LockDirectory."/Apache-Session-".$session->{data}->{_session_id}.".lock") || die $!;
+        open($fh, "+> $LockFile") || die "$LockFile: $!";
 
         $self->{fh} = $fh;
         $self->{opened} = 1;

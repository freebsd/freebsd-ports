--- lib/File/RsyncP.pm.orig	Thu Jul 24 04:33:37 2003
+++ lib/File/RsyncP.pm	Mon Jan 12 10:31:36 2004
@@ -48,7 +48,7 @@
 use Getopt::Long;
 use Data::Dumper;
 
-our $VERSION = '0.44';
+use vars qw($VERSION); $VERSION = '0.44';
 
 use constant S_IFMT       => 0170000;	# type of file
 use constant S_IFDIR      => 0040000; 	# directory
@@ -267,7 +267,7 @@
     close(RSYNC);
     $rs->{fh} = *FH;
     $rs->{rsyncPID} = $pid;
-    $rs->{pidHandler}($rs->{rsyncPID}, $rs->{childPID})
+    $rs->{pidHandler}->($rs->{rsyncPID}, $rs->{childPID})
 			if ( defined($rs->{pidHandler}) );
     #
     # Write our version and get the remote version
@@ -391,7 +391,7 @@
 	$rs->{childFh}  = *RH;
 	$rs->{childPID} = $pid;
 	$rs->log("Child PID is $pid") if ( $rs->{logLevel} >= 2 );
-	$rs->{pidHandler}($rs->{rsyncPID}, $rs->{childPID})
+	$rs->{pidHandler}->($rs->{rsyncPID}, $rs->{childPID})
 			    if ( defined($rs->{pidHandler}) );
 	setsockopt($rs->{fh}, SOL_SOCKET, SO_SNDBUF, 8 * 65536);
 	setsockopt($rs->{childFh}, SOL_SOCKET, SO_RCVBUF, 8 * 65536);
@@ -1088,7 +1088,7 @@
 
     foreach my $str ( @logStr ) {
 	next if ( $str eq "" );
-	$rs->{logHandler}($str);
+	$rs->{logHandler}->($str);
     }
 }
 

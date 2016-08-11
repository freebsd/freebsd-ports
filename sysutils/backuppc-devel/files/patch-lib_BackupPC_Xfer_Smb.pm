--- lib/BackupPC/Xfer/Smb.pm.orig	2013-12-01 20:58:20 UTC
+++ lib/BackupPC/Xfer/Smb.pm
@@ -216,7 +216,7 @@ sub readOutput
         # This section is highly dependent on the version of smbclient.
         # If you upgrade Samba, make sure that these regexp are still valid.
         #
-        if ( /^\s*(-?\d+) \(\s*\d+[.,]\d kb\/s\) (.*)$/ ) {
+        if ( /^\s*(-?\d+) \(\s*\d+[.,]\d kb\/s\) (.*)$/ || /^tar:(\d+)\s+\+\+\+ (.*)$/ ) {
             my $sambaFileSize = $1;
             my $pcFileName    = $2;
             (my $fileName = $pcFileName) =~ s/\\/\//g;
@@ -229,7 +229,9 @@ sub readOutput
             $t->{byteCnt} += $2;
             $t->{fileCnt}++;
             $t->{XferLOG}->write(\"$_\n") if ( $t->{logLevel} >= 1 );
-        } elsif ( /^\s*tar: dumped \d+ files/ ) {
+        } elsif ( /^\s*tar: dumped \d+ files/
+                    || /Total bytes received: \d+/i
+                    || /tar_process done, err = 0/ ) {
             $t->{xferOK} = 1;
             $t->{XferLOG}->write(\"$_\n") if ( $t->{logLevel} >= 0 );
         } elsif ( /^\s*tar: restored \d+ files/ ) {
@@ -269,6 +271,10 @@ sub readOutput
         } elsif ( /^\s*directory \\/i ) {
             $t->{XferLOG}->write(\"$_\n") if ( $t->{logLevel} >= 2 );
         } elsif ( /smb: \\>/
+                || /^tar:\d+\s/
+                || /^  NTLMSSP_/
+                || /^GENSEC backend /
+                || /^doing parameter /
                 || /^\s*added interface/i
                 || /^\s*tarmode is now/i
                 || /^\s*Total bytes written/i

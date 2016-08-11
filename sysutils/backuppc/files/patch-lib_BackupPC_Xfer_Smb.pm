--- lib/BackupPC/Xfer/Smb.pm.orig	2016-06-04 10:42:02 UTC
+++ lib/BackupPC/Xfer/Smb.pm
@@ -217,7 +217,7 @@ sub readOutput
         # This section is highly dependent on the version of smbclient.
         # If you upgrade Samba, make sure that these regexp are still valid.
         #
-        if ( /^\s*(-?\d+) \(\s*\d+[.,]\d kb\/s\) (.*)$/ ) {
+        if ( /^\s*(-?\d+) \(\s*\d+[.,]\d kb\/s\) (.*)$/ || /^tar:(\d+)\s+\+\+\+ (.*)$/ ) {
             my $sambaFileSize = $1;
             my $pcFileName    = $2;
             (my $fileName = $pcFileName) =~ s/\\/\//g;
@@ -230,7 +230,9 @@ sub readOutput
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
@@ -270,6 +272,10 @@ sub readOutput
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

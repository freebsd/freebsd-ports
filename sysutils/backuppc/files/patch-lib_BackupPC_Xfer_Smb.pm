--- lib/BackupPC/Xfer/Smb.pm.orig	2017-02-06 08:40:41 UTC
+++ lib/BackupPC/Xfer/Smb.pm
@@ -242,7 +242,8 @@ sub readOutput
             $t->{xferOK} = 1;
             $t->{byteCnt} = $1;
             $t->{XferLOG}->write(\"$_\n") if ( $t->{logLevel} >= 0 );
-        } elsif ( /^\s*tar: restored \d+ files/ ) {
+        } elsif ( /^\s*tar: restored \d+ files/
+                    || /^\s*tar:\d+\s*tar_process done, err = 0/ ) {
             $t->{xferOK} = 1;
             $t->{XferLOG}->write(\"$_\n") if ( $t->{logLevel} >= 0 );
         } elsif ( /^\s*read_socket_with_timeout: timeout read. /i ) {

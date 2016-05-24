--- lib/BackupPC/CGI/Browse.pm.orig	2016-05-14 07:28:52 UTC
+++ lib/BackupPC/CGI/Browse.pm
@@ -65,7 +65,7 @@ sub action
     #
     # default to the newest backup
     #
-    if ( !defined($In{num}) && defined(@Backups) && @Backups > 0 ) {
+    if ( !defined($In{num}) && @Backups > 0 ) {
         $i = @Backups - 1;
         $num = $Backups[$i]{num};
     }

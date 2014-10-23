--- ./update.pl.orig	2014-09-03 13:36:33.000000000 +0400
+++ ./update.pl	2014-09-03 13:56:16.000000000 +0400
@@ -222,7 +222,7 @@
 if ( $ConfigPath ne "" && -r $ConfigPath ) {
     (my $confDir = $ConfigPath) =~ s{/[^/]+$}{};
     die("BackupPC::Lib->new failed\n")
-            if ( !($bpc = BackupPC::Lib->new(".", ".", $confDir, 1)) );
+            if ( !($bpc = BackupPC::Lib->new(".", $opts{"install-dir"}, $confDir, 1)) );
     %Conf = $bpc->Conf();
     %OrigConf = %Conf;
     if ( !$opts{fhs} ) {
@@ -494,239 +494,21 @@
 
 print <<EOF;
 
-Ok, we're about to:
-
-  - install the binaries, lib and docs in $Conf{InstallDir},
-  - create the data directory $Conf{TopDir},
-  - create/update the config.pl file $Conf{ConfDir}/config.pl,
-  - optionally install the cgi-bin interface.
+Ok, we're about to create/update the config.pl file $Conf{ConfDir}/config.pl.
 
 EOF
 
 exit unless prompt("--> Do you want to continue?", "y") =~ /y/i;
 
 #
-# Create install directories
-#
-foreach my $dir ( qw(bin share/doc/BackupPC
-		     lib/BackupPC/CGI
-		     lib/BackupPC/Config
-		     lib/BackupPC/Lang
-		     lib/BackupPC/Storage
-		     lib/BackupPC/Xfer
-		     lib/BackupPC/Zip
-                     lib/Net/FTP
-		 ) ) {
-    next if ( -d "$DestDir$Conf{InstallDir}/$dir" );
-    mkpath("$DestDir$Conf{InstallDir}/$dir", 0, 0755);
-    if ( !-d "$DestDir$Conf{InstallDir}/$dir"
-            || !my_chown($Uid, $Gid, "$DestDir$Conf{InstallDir}/$dir") ) {
-        die("Failed to create or chown $DestDir$Conf{InstallDir}/$dir\n");
-    } else {
-        print("Created $DestDir$Conf{InstallDir}/$dir\n");
-    }
-}
-
-#
-# Create CGI image directory
-#
-foreach my $dir ( ($Conf{CgiImageDir}) ) {
-    next if ( $dir eq "" || -d "$DestDir$dir" );
-    mkpath("$DestDir$dir", 0, 0755);
-    if ( !-d "$DestDir$dir" || !my_chown($Uid, $Gid, "$DestDir$dir") ) {
-        die("Failed to create or chown $DestDir$dir");
-    } else {
-        print("Created $DestDir$dir\n");
-    }
-}
-
-#
-# Create other directories
-#
-foreach my $dir ( (
-            "$Conf{TopDir}",
-            "$Conf{TopDir}/pool",
-            "$Conf{TopDir}/cpool",
-            "$Conf{TopDir}/pc",
-            "$Conf{ConfDir}",
-            "$Conf{LogDir}",
-            "$Conf{RunDir}",
-        ) ) {
-    mkpath("$DestDir$dir", 0, 0750) if ( !-d "$DestDir$dir" );
-    if ( !-d "$DestDir$dir"
-            || !my_chown($Uid, $Gid, "$DestDir$dir") ) {
-        die("Failed to create or chown $DestDir$dir\n");
-    } else {
-        print("Created $DestDir$dir\n");
-    }
-}
-
-printf("Installing binaries in $DestDir$Conf{InstallDir}/bin\n");
-foreach my $prog ( qw(
-        bin/BackupPC
-        bin/BackupPC_Admin_SCGI
-        bin/BackupPC_archive
-        bin/BackupPC_archiveHost
-        bin/BackupPC_archiveStart
-        bin/BackupPC_attribPrint
-        bin/BackupPC_backupDelete
-        bin/BackupPC_backupDuplicate
-        bin/BackupPC_dump
-        bin/BackupPC_fixupBackupSummary
-        bin/BackupPC_fsck
-        bin/BackupPC_ls
-        bin/BackupPC_nightly
-        bin/BackupPC_poolCntPrint
-        bin/BackupPC_refCountUpdate
-        bin/BackupPC_restore
-        bin/BackupPC_rrdUpdate
-        bin/BackupPC_sendEmail
-        bin/BackupPC_serverMesg
-        bin/BackupPC_tarCreate
-        bin/BackupPC_tarExtract
-        bin/BackupPC_zcat
-        bin/BackupPC_zipCreate
-    ) ) {
-    InstallFile($prog, "$DestDir$Conf{InstallDir}/$prog", 0555);
-}
-
-#
-# remove old pre-v4 programs
-#
-foreach my $prog ( qw(
-        bin/BackupPC_link
-        bin/BackupPC_tarPCCopy
-        bin/BackupPC_trashClean
-        bin/BackupPC_compressPool
-    ) ) {
-    unlink("$DestDir$Conf{InstallDir}/$prog");
-}
-
-printf("Installing library in $DestDir$Conf{InstallDir}/lib\n");
-foreach my $lib ( qw(
-        lib/BackupPC/Config/Meta.pm
-        lib/BackupPC/DirOps.pm
-        lib/BackupPC/Lib.pm
-        lib/BackupPC/Storage.pm
-        lib/BackupPC/View.pm
-        lib/BackupPC/Xfer/Archive.pm
-        lib/BackupPC/Xfer/Ftp.pm
-        lib/BackupPC/Xfer/Protocol.pm
-        lib/BackupPC/Xfer/Rsync.pm
-        lib/BackupPC/Xfer/Smb.pm
-        lib/BackupPC/Xfer/Tar.pm
-        lib/BackupPC/Xfer.pm
-        lib/BackupPC/Zip/FileMember.pm
-        lib/Net/FTP/AutoReconnect.pm
-        lib/Net/FTP/RetrHandle.pm
-        lib/BackupPC/CGI/AdminOptions.pm
-        lib/BackupPC/CGI/Archive.pm
-        lib/BackupPC/CGI/ArchiveInfo.pm
-        lib/BackupPC/CGI/Browse.pm
-        lib/BackupPC/CGI/DirHistory.pm
-        lib/BackupPC/CGI/EditConfig.pm
-        lib/BackupPC/CGI/EmailSummary.pm
-        lib/BackupPC/CGI/GeneralInfo.pm
-        lib/BackupPC/CGI/HostInfo.pm
-        lib/BackupPC/CGI/Lib.pm
-        lib/BackupPC/CGI/LOGlist.pm
-        lib/BackupPC/CGI/Queue.pm
-        lib/BackupPC/CGI/ReloadServer.pm
-        lib/BackupPC/CGI/Restore.pm
-        lib/BackupPC/CGI/RestoreFile.pm
-        lib/BackupPC/CGI/RestoreInfo.pm
-        lib/BackupPC/CGI/RSS.pm
-        lib/BackupPC/CGI/StartServer.pm
-        lib/BackupPC/CGI/StartStopBackup.pm
-        lib/BackupPC/CGI/StopServer.pm
-        lib/BackupPC/CGI/Summary.pm
-        lib/BackupPC/CGI/View.pm
-        lib/BackupPC/Lang/cz.pm
-        lib/BackupPC/Lang/de.pm
-        lib/BackupPC/Lang/en.pm
-        lib/BackupPC/Lang/es.pm
-        lib/BackupPC/Lang/fr.pm
-        lib/BackupPC/Lang/it.pm
-        lib/BackupPC/Lang/ja.pm
-        lib/BackupPC/Lang/nl.pm
-        lib/BackupPC/Lang/pl.pm
-        lib/BackupPC/Lang/pt_br.pm
-        lib/BackupPC/Lang/ru.pm
-        lib/BackupPC/Lang/uk.pm
-        lib/BackupPC/Lang/zh_CN.pm
-        lib/BackupPC/Storage/Text.pm
-    ) ) {
-    InstallFile($lib, "$DestDir$Conf{InstallDir}/$lib", 0444);
-}
-
-#
-# remove old pre-v4 libraries
-#
-foreach my $lib ( qw(
-        lib/BackupPC/Attrib.pm
-        lib/BackupPC/Config.pm
-        lib/BackupPC/FileZIO.pm
-        lib/BackupPC/PoolWrite.pm
-        lib/BackupPC/Xfer/RsyncDigest.pm
-        lib/BackupPC/Xfer/RsyncFileIO.pm
-    ) ) {
-    unlink("$DestDir$Conf{InstallDir}/$lib");
-}
-
-#
 # clean pid and sock files from old location (they are now in $Conf{RunDir}, and they
 # get re-created each time BackupPC starts, so it's ok if RunDir eq LogDir).
 #
 unlink("$DestDir$Conf{LogDir}/BackupPC.pid")  if ( -f "$DestDir$Conf{LogDir}/BackupPC.pid" );
 unlink("$DestDir$Conf{LogDir}/BackupPC.sock") if ( -e "$DestDir$Conf{LogDir}/BackupPC.sock" );
 
-if ( $Conf{CgiImageDir} ne "" ) {
-    printf("Installing images in $DestDir$Conf{CgiImageDir}\n");
-    foreach my $img ( <images/*> ) {
-	(my $destImg = $img) =~ s{^images/}{};
-	InstallFile($img, "$DestDir$Conf{CgiImageDir}/$destImg", 0444, 1);
-    }
-
-    #
-    # Install new CSS file, making a backup copy if necessary
-    #
-    my $cssBackup = "$DestDir$Conf{CgiImageDir}/BackupPC_stnd.css.pre-4.0.0alpha3";
-    if ( -f "$DestDir$Conf{CgiImageDir}/BackupPC_stnd.css" && !-f $cssBackup ) {
-	rename("$DestDir$Conf{CgiImageDir}/BackupPC_stnd.css", $cssBackup);
-    }
-    InstallFile("conf/BackupPC_stnd.css",
-	        "$DestDir$Conf{CgiImageDir}/BackupPC_stnd.css", 0444, 0);
-    InstallFile("conf/BackupPC_stnd_orig.css",
-	        "$DestDir$Conf{CgiImageDir}/BackupPC_stnd_orig.css", 0444, 0);
-    InstallFile("conf/sorttable.js",
-                "$DestDir$Conf{CgiImageDir}/sorttable.js", 0444, 0);
-}
-
-printf("Making init.d scripts\n");
-foreach my $init ( qw(gentoo-backuppc gentoo-backuppc.conf linux-backuppc
-		      solaris-backuppc debian-backuppc freebsd-backuppc
-                      freebsd-backuppc2 suse-backuppc slackware-backuppc ) ) {
-    InstallFile("init.d/src/$init", "init.d/$init", 0444);
-}
-
-printf("Making Apache configuration file for suid-perl\n");
-InstallFile("httpd/src/BackupPC.conf", "httpd/BackupPC.conf", 0644);
-
-printf("Installing docs in $DestDir$Conf{InstallDir}/share/doc/BackupPC\n");
-foreach my $doc ( qw(BackupPC.pod BackupPC.html) ) {
-    InstallFile("doc/$doc", "$DestDir$Conf{InstallDir}/share/doc/BackupPC/$doc", 0444);
-    #
-    # clean up files from old directory
-    #
-    unlink("$DestDir$Conf{InstallDir}/doc/$doc") if ( -f "$DestDir$Conf{InstallDir}/doc/$doc" );
-}
-#
-# clean up old directory (ok if it quietly fails if there are other files in that directory)
-#
-rmdir("$DestDir$Conf{InstallDir}/doc") if ( -d "$DestDir$Conf{InstallDir}/doc" );
-
 printf("Installing config.pl and hosts in $DestDir$Conf{ConfDir}\n");
-InstallFile("conf/hosts", "$DestDir$Conf{ConfDir}/hosts", 0644)
+InstallFile("$DestDir$Conf{ConfDir}/hosts.sample", "$DestDir$Conf{ConfDir}/hosts", 0644)
                     if ( !-f "$DestDir$Conf{ConfDir}/hosts" );
 
 #
@@ -735,7 +517,7 @@
 # parameters and deleting ones that are no longer needed.
 #
 my $dest = "$DestDir$Conf{ConfDir}/config.pl";
-my ($distConf, $distVars) = ConfigParse("conf/config.pl");
+my ($distConf, $distVars) = ConfigParse("$DestDir$Conf{ConfDir}/config.pl.sample");
 my ($oldConf, $oldVars);
 my ($newConf, $newVars) = ($distConf, $distVars);
 if ( -f $dest ) {
@@ -974,13 +756,6 @@
     die("can't chown $Uid, $Gid $dest\n") unless my_chown($Uid, $Gid, $dest);
 }
 
-if ( $Conf{CgiDir} ne "" ) {
-    printf("Installing cgi script BackupPC_Admin in $DestDir$Conf{CgiDir}\n");
-    mkpath("$DestDir$Conf{CgiDir}", 0, 0755);
-    InstallFile("cgi-bin/BackupPC_Admin", "$DestDir$Conf{CgiDir}/BackupPC_Admin",
-                04554);
-}
-
 print <<EOF;
 
 Ok, it looks like we are finished.  There are several more things you

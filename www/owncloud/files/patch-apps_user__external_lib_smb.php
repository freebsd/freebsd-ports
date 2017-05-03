--- apps/user_external/lib/smb.php.orig	2017-05-03 00:52:45 UTC
+++ apps/user_external/lib/smb.php
@@ -18,7 +18,7 @@
 class OC_User_SMB extends \OCA\user_external\Base{
 	private $host;
 
-	const SMBCLIENT = 'smbclient -L';
+	const SMBCLIENT = '%%PREFIX%%/bin/smbclient -L';
 	const LOGINERROR = 'NT_STATUS_LOGON_FAILURE';
 
 	/**

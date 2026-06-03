--- regress/test-exec.sh.orig	2015-04-03 18:20:32.256126000 UTC
+++ regress/test-exec.sh	2015-04-03 18:20:41.599903000 -0500
@@ -618,6 +618,7 @@ cat << EOF > $OBJ/sshd_config
 	LogLevel		DEBUG3
 	AcceptEnv		_XXX_TEST_*
 	AcceptEnv		_XXX_TEST
+	PermitRootLogin		yes
 	Subsystem	sftp	$SFTPSERVER
 	SshdSessionPath		$SSHD_SESSION
 	SshdAuthPath		$SSHD_AUTH

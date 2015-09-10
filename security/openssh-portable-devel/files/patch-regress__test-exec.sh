--- regress/test-exec.sh.orig	2015-04-03 18:20:32.256126000 -0500
+++ regress/test-exec.sh	2015-04-03 18:20:41.599903000 -0500
@@ -408,6 +408,7 @@ cat << EOF > $OBJ/sshd_config
 	LogLevel		DEBUG3
 	AcceptEnv		_XXX_TEST_*
 	AcceptEnv		_XXX_TEST
+	PermitRootLogin		yes
 	Subsystem	sftp	$SFTPSERVER
 EOF
 

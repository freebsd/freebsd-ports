--- regress/test-exec.sh.orig	Fri Jun 25 05:46:09 2004
+++ regress/test-exec.sh	Tue Aug 17 05:27:49 2004
@@ -178,6 +178,8 @@
 	AcceptEnv		_XXX_TEST_*
 	AcceptEnv		_XXX_TEST
 	Subsystem	sftp	$SFTPSERVER
+	PermitRootLogin		yes
+	UsePrivilegeSeparation	no
 EOF
 
 if [ ! -z "$TEST_SSH_SSHD_CONFOPTS" ]; then

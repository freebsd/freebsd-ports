--- regress/test-exec.sh.orig	Fri Sep 12 07:32:17 2003
+++ regress/test-exec.sh	Tue Sep 16 19:56:13 2003
@@ -163,6 +163,8 @@
 	AuthorizedKeysFile	$OBJ/authorized_keys_%u
 	LogLevel		QUIET
 	StrictModes		no
+	PermitRootLogin		yes
+	UsePrivilegeSeparation	no
 EOF
 
 # server config for proxy connects

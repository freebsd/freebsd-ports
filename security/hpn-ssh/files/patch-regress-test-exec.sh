--- regress/test-exec.sh.orig	Wed May  1 05:17:35 2002
+++ regress/test-exec.sh	Tue Apr  1 06:03:11 2003
@@ -130,6 +130,8 @@
 	PidFile			$PIDFILE
 	AuthorizedKeysFile	$OBJ/authorized_keys_%u
 	LogLevel		QUIET
+	PermitRootLogin		yes
+	UsePrivilegeSeparation	no
 EOF
 
 # server config for proxy connects

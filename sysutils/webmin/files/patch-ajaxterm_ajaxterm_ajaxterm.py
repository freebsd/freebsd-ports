
$FreeBSD$

--- ajaxterm/ajaxterm/ajaxterm.py.orig
+++ ajaxterm/ajaxterm/ajaxterm.py
@@ -394,7 +394,7 @@
 			if self.cmd:
 				cmd=['/bin/sh','-c',self.cmd]
 			elif os.getuid()==0:
-				cmd=['/bin/login']
+				cmd=['/usr/bin/login']
 			else:
 				sys.stdout.write("Login: ")
 				login=sys.stdin.readline().strip()

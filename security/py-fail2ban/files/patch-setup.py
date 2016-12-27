--- setup.py.orig	2016-12-09 14:36:08 UTC
+++ setup.py
@@ -149,27 +149,14 @@ setup(
 		'bin/fail2ban-client',
 		'bin/fail2ban-server',
 		'bin/fail2ban-regex',
-		'bin/fail2ban-testcases',
 		# 'bin/fail2ban-python', -- link (binary), will be installed via install_scripts_f2b wrapper
 	],
 	packages = [
 		'fail2ban',
 		'fail2ban.client',
 		'fail2ban.server',
-		'fail2ban.tests',
-		'fail2ban.tests.action_d',
 	],
 	package_data = {
-		'fail2ban.tests':
-			[ join(w[0], f).replace("fail2ban/tests/", "", 1)
-				for w in os.walk('fail2ban/tests/files')
-				for f in w[2]] +
-			[ join(w[0], f).replace("fail2ban/tests/", "", 1)
-				for w in os.walk('fail2ban/tests/config')
-				for f in w[2]] +
-			[ join(w[0], f).replace("fail2ban/tests/", "", 1)
-				for w in os.walk('fail2ban/tests/action_d')
-				for f in w[2]]
 	},
 	data_files = [
 		('/etc/fail2ban',

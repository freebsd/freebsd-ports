--- setup.py.orig	2015-08-01 01:32:13 UTC
+++ setup.py
@@ -104,26 +104,13 @@ setup(
 		'bin/fail2ban-client',
 		'bin/fail2ban-server',
 		'bin/fail2ban-regex',
-		'bin/fail2ban-testcases',
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
@@ -147,10 +134,6 @@ setup(
 		),
 		('/var/lib/fail2ban',
 			''
-		),
-		('/usr/share/doc/fail2ban',
-			['README.md', 'README.Solaris', 'DEVELOP', 'FILTERS',
-			 'doc/run-rootless.txt']
 		)
 	] + data_files_extra,
 	**setup_extra

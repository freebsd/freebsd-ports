--- setup.py.orig	2014-11-08 10:14:31.000000000 +0100
+++ setup.py	2014-11-08 10:17:37.000000000 +0100
@@ -96,26 +96,13 @@
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
@@ -136,10 +123,6 @@
 		),
 		('/var/lib/fail2ban',
 			''
-		),
-		('/usr/share/doc/fail2ban',
-			['README.md', 'README.Solaris', 'DEVELOP', 'FILTERS',
-			 'doc/run-rootless.txt']
 		)
 	],
 	**setup_extra

--- setup.py.orig	2023-01-13 16:45:59 UTC
+++ setup.py
@@ -22,5 +22,5 @@ setup(
     download_url='https://github.com/dmranck/ticketutil/tarball/1.8.0',
     keywords=['jira', 'bugzilla', 'rt', 'redmine', 'servicenow', 'ticket', 'rest'],
     install_requires=['gssapi>=1.2.0', 'requests>=2.6.0', 'requests-kerberos>=0.8.0'],
-    data_files=[('.', ['HISTORY.rst'])]
+    data_files=[('', ['HISTORY.rst'])]
 )

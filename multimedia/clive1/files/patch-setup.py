--- setup.py	2008-01-25 04:37:50.000000000 +0100
+++ setup.py.port	2008-02-03 11:40:03.000000000 +0100
@@ -59,7 +59,10 @@
 
 manpage = 'man/clive.1'
 manpage_gz = manpage + '.gz'
-data_files = [ ('man/man1', [manpage_gz]) ]
+if not os.environ.has_key('NO_INSTALL_MANPAGES'):
+	data_files = [ ('man/man1', [manpage_gz]) ]
+else:
+	data_files = []
 
 setup_args = dict(
 	name = 'clive',

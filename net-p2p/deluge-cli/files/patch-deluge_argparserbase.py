Vendor fix for https://dev.deluge-torrent.org/ticket/3278

===================================================================
--- deluge/argparserbase.py	(revision d417c4b0f9fd0702ebf986546ab884d2a9517e4e)
+++ deluge/argparserbase.py	(revision 1b4ac88ce72515bcf36684b942e3998900f13cea)
@@ -326,5 +326,5 @@
             # Write pid file before chuid
             if options.pidfile:
-                with open(options.pidfile, 'wb') as _file:
+                with open(options.pidfile, 'w') as _file:
                     _file.write('%d\n' % os.getpid())

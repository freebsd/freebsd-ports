--- Build.PL.orig	2012-08-16 11:52:10.613393871 -0400
+++ Build.PL	2012-08-16 11:53:17.923511254 -0400
@@ -247,12 +247,12 @@
     ],
     script_files => ['bin/publican'],
     install_path => {
-        'datadir'    => '/usr/share/publican',
-        'generated'  => '/usr/share/publican/sitetemplate',
-        'web'        => '/usr/share/publican/sitetemplate',
-        'templates'  => '/usr/share/publican/templates',
-        'etc'        => '/etc',
-        'completion' => '/etc/bash_completion.d',
+        'datadir'    => '%%DATADIR%%',
+        'generated'  => '%%DATADIR%%/sitetemplate',
+        'web'        => '%%DATADIR%%/sitetemplate',
+        'templates'  => '%%DATADIR%%/templates',
+        'etc'        => '%%PREFIX%%/etc',
+        'completion' => '%%PREFIX%%/etc/bash_completion.d',
     },
     data_files => {
         'datadir/default.db'    => 'datadir/default.db',

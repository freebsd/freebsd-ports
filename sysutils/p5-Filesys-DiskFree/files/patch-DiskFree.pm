--- DiskFree.pm.old	Sat Oct 24 00:30:01 1998
+++ DiskFree.pm	Fri Mar 24 12:58:45 2006
@@ -39,7 +39,11 @@
 	'inodes' => "df -i",
 	'format' => 'bsdish',
     },
-
+    'freebsd' => {
+	'blocks' => "df -Pi",
+	'inodes' => "df -Pi",
+	'format' => 'bsdish',
+    },
     'irix' => {
     	'blocks' => "df",
 	'inodes' => "df -i",

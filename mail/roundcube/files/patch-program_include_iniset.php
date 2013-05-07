--- program/include/iniset.php.orig	2013-04-15 22:42:21.000000000 +0200
+++ program/include/iniset.php	2013-05-07 12:40:34.000000000 +0200
@@ -28,7 +28,6 @@
     // Some users are not using Installer, so we'll check some
     // critical PHP settings here. Only these, which doesn't provide
     // an error/warning in the logs later. See (#1486307).
-    'suhosin.session.encrypt' => 0,
     'session.auto_start'      => 0,
     'file_uploads'            => 1,
 );

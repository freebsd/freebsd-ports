
$FreeBSD$

--- Makefile.PL.orig
+++ Makefile.PL
@@ -28,7 +28,6 @@
 		    'File::Temp' => 0,
 		    'File::Spec::Functions' => 0,
 		   },
-    'EXE_FILES' => [qw( perldoc )],
 
     ( $EUMM_VERSION > 6.31 ? (
         'LICENSE' => 'perl',

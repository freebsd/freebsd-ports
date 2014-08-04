--- lib/MT.pm.orig	2013-12-02 02:40:30.000000000 +0900
+++ lib/MT.pm	2014-04-16 15:18:36.000000000 +0900
@@ -39,8 +39,8 @@
         )
         = (
         'Movable Type',   'MT',
-        '5.2.9',              '5.2.9-ru',
-        '9', 'http://movable-type.ru/'
+        '5.2.10',              '5.2.10-ru',
+        '10', 'http://movable-type.ru/'
         );
 
   # To allow MT to run straight from svn, if no build process (pre-processing)
@@ -56,7 +56,7 @@
     }
 
     if ( $RELEASE_NUMBER eq '__RELEASE' . '_NUMBER__' ) {
-        $RELEASE_NUMBER = 9;
+        $RELEASE_NUMBER = 10;
     }
 
     $DebugMode = 0;
@@ -124,7 +124,7 @@
 }
 
 sub build_id {
-    my $build_id = '5.2.9-ru';
+    my $build_id = '5.2.10-ru';
     $build_id = '' if $build_id eq '__BUILD_' . 'ID__';
     return $build_id;
 }


$FreeBSD$

--- Makefile.PL.orig
+++ Makefile.PL
@@ -33,8 +33,6 @@
             'warnings'                  => '0',
            },
 
-    'EXE_FILES' => [qw( perldoc )],
-
 	'META_MERGE' => {
 		no_index => {
 			directory => 'corpus',

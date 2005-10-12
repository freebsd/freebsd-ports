--- Makefile.PL.orig	Mon Oct 10 07:16:30 2005
+++ Makefile.PL	Mon Oct 10 07:18:38 2005
@@ -63,7 +63,8 @@
 }
 
 WriteMakefile
-  ('DISTNAME' => 'WebService-Validator-HTML-W3C',
+  ('NAME' => 'WebService::Validator::HTML::W3C',
+   'DISTNAME' => 'WebService-Validator-HTML-W3C',
    'VERSION' => '0.03',
    'PL_FILES' => {},
    'PREREQ_PM' => {
@@ -72,4 +73,8 @@
         'Test::More' => '0',
 
           },
+   'MAN3PODS' => {
+        'lib/WebService/Validator/HTML/W3C/Error.pm' => 'blib/man3/WebService::Validator::HTML::W3C::Error.3',
+        'lib/WebService/Validator/HTML/W3C.pm' => 'blib/man3/WebService::Validator::HTML::W3C.3',
+    },
   );

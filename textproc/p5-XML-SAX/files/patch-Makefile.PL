Used in conjuntion with a REINPLACE_CMD in post-patch

--- Makefile.PL.orig	2012-05-27 20:36:08.188491094 +0100
+++ Makefile.PL	2012-05-27 20:37:51.088491081 +0100
@@ -28,10 +28,7 @@
     else {
         my $dir = File::Basename::dirname($INC{'XML/SAX.pm'});
         if (-e File::Spec->catfile($dir, 'SAX', 'ParserDetails.ini')) {
-            $write_ini_ok =
-                ExtUtils::MakeMaker::prompt(
-                    "Do you want XML::SAX to alter ParserDetails.ini?", "Y"
-                ) =~ /^y/i;
+            $write_ini_ok = %%WRITE_INI_OK%%;
         }
         else {
             $write_ini_ok = 1;

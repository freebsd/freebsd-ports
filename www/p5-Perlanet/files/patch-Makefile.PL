--- Makefile.PL.orig	2023-05-22 08:51:28 UTC
+++ Makefile.PL
@@ -6,7 +6,6 @@ WriteMakefile
   'NAME' => 'Perlanet',
   'VERSION_FROM' => 'lib/Perlanet.pm',
   'PREREQ_PM' => {
-                   'Alien::TidyHTML5' => 0,
                    'DateTime' => 0,
                    'DateTime::Duration' => 0,
                    'DateTime::Format::Strptime' => 0,


$FreeBSD$

--- Makefile.PL.orig
+++ Makefile.PL
@@ -44,10 +44,6 @@
                       -default => 1,
                       recommends( 'Date::Manip' => 0 ),
                     ],
-                    'Speed Tests' => [
-                      -default => 0,
-                      recommends( 'Benchmark::Timer' => '0.7100' ),
-                    ],
                   );
 
 include           ('ExtUtils/AutoInstall.pm');

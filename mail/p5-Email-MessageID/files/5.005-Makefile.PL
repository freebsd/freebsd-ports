--- Makefile.PL.orig	Mon Dec 27 20:43:11 2004
+++ Makefile.PL	Mon Dec 27 20:43:41 2004
@@ -6,8 +6,7 @@
                NAME          => 'Email::MessageID',
                PREREQ_PM     => {
                                  'Email::Address' => '1.80',
-                                 'Sys::Hostname' => '1.11',
-                                 'Test::More' => '0.47',
+                                 'Sys::Hostname' => 0,
                                 },
                VERSION_FROM  => 'lib/Email/MessageID.pm',
               );

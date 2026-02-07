--- Makefile.PL.orig	2010-07-28 05:19:39.000000000 +0400
+++ Makefile.PL	2010-07-28 05:21:00.000000000 +0400
@@ -23,18 +23,9 @@
                        'EXE_FILES' => [],
                        'VERSION' => '1.001000',
                        'PREREQ_PM' => {
-                                        'SQL::Translator' => '0.11002',
-                                        'parent' => '0',
-                                        'FindBin' => '0',
-                                        'Carp' => '0',
                                         'Catalyst::Model::DBIC::Schema' => '0.29',
-                                        'Test::More' => '0.88',
-                                        'Catalyst::View::JSON' => '0',
                                         'Catalyst::Runtime' => '5.80000',
-                                        'JSON' => '0',
                                         'DBIx::Class' => '0.08108',
-                                        'Test::Deep' => '0',
-                                        'Catalyst::Test' => '0'
                                       },
                        'LICENSE' => 'perl'
                      );

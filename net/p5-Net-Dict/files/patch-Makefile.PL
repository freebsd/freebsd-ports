--- Makefile.PL.orig	2016-03-01 12:44:17 UTC
+++ Makefile.PL
@@ -21,7 +21,6 @@ if ($mm_ver =~ /_/) { # dev version
                      'Carp'		      => 0,
                      'AppConfig::Std' => 0,
                     },
-    EXE_FILES	=> [qw(dict tkdict)],
     AUTHOR		=> 'Neil Bowers <neil@bowers.com>',
     ABSTRACT_FROM	=> 'lib/Net/Dict.pod',
     META_MERGE => {

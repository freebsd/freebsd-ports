--- ./Build.PL.orig	Sat Dec 10 03:09:32 2005
+++ ./Build.PL	Sun Jan 15 14:21:58 2006
@@ -6,6 +6,7 @@
     module_name        => 'Text::RecordParser',
     dist_author        => 'Ken Youens-Clark <kclark@cpan.org>',
     dist_version_from  => 'lib/Text/RecordParser.pm',
+    script_files       => [ 'bin/tablify', 'bin/tabmerge' ],
     add_to_cleanup     => [ '$(DISTNAME)-$(VERSION).tar.gz' ],
     create_makefile_pl => 'passthrough',
     create_readme      => 1,
@@ -17,8 +18,6 @@
         'version'              => 0,
     },
     build_requires     => {
-        'Test::More'           => 0,
-        'Test::Exception'      => 0,
     },
     recommends         => {
         'Readonly::XS'         => 0,

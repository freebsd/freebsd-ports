--- Makefile.PL.orig	2014-03-11 16:59:58.443768044 +0100
+++ Makefile.PL	2014-03-11 17:00:36.554952157 +0100
@@ -32,11 +32,6 @@
 use Config;
 use ExtUtils::MakeMaker;
 
-#   determine source directory
-my ($srcdir) = map { my $d = $_; $d =~ s/\/libuuid\.la$//; $d }
-               grep { -f $_ } ("../libuuid.la", glob("../*/libuuid.la"))
-    or die "no source directory found (where libuuid.la is located)";
-
 #   determine extra build options
 my $compat = 0;
 @ARGV = grep { $_ =~ m/^COMPAT=(\d+)$/i ? ($compat = $1, 0) : 1 } @ARGV;
@@ -47,9 +42,9 @@
     VERSION_FROM      => 'uuid.pm',
     ABSTRACT_FROM     => 'uuid.pod',
     PREREQ_PM         => {},
-    LIBS              => [ "-L$srcdir/.libs -L$srcdir -luuid" ],
+    LIBS              => [ "-L%%LOCALBASE%%/lib -luuid" ],
     DEFINE            => '',
-    INC               => "-I. -I$srcdir",
+    INC               => "-I. -I%%LOCALBASE%%/include/ossp",
     PM                => { 'uuid.pm'   => '$(INST_LIBDIR)/uuid.pm',
                            'uuid.pod'  => '$(INST_LIBDIR)/uuid.pod',
                            ($compat ? ('uuid_compat.pm'  => '$(INST_LIBDIR)/../Data/UUID.pm')  : ()),

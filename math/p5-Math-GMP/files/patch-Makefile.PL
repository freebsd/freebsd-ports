--- Makefile.PL.orig	Wed Nov 27 10:18:38 2002
+++ Makefile.PL	Wed Nov 27 10:50:17 2002
@@ -6,6 +6,8 @@
 my $tar = (grep { -x "$_/tar" } @paths)[0] . "/tar";
 my $gzip = (grep { -x "$_/gzip" } @paths)[0] . "/gzip";
 
+# FreeBSD has GMP in the base system or ports
+if ("" ne "" ) {
 my $cmd = "$gzip -dc gmp-2.0.2.tar.gz | $tar xf -";
 system $cmd unless -d 'gmp-2.0.2';
 die "tar extraction of gmp-2.0.2.tar.gz failed" unless -d 'gmp-2.0.2';
@@ -13,11 +15,12 @@
 chdir 'gmp-2.0.2';
 system "./configure --prefix=../gmp && make && make install";
 chdir '..';
+}
 
 WriteMakefile(
     'NAME'	=> 'Math::GMP',
     'VERSION_FROM' => 'GMP.pm', # finds $VERSION
     'LIBS'	=> ['-Lgmp/lib -lgmp'],   # e.g., '-lm' 
     'DEFINE'	=> '',     # e.g., '-DHAVE_SOMETHING' 
-    'INC'	=> '-I$(PREFIX)',     # e.g., '-I/usr/include/other' 
+    'INC'	=> '-I'.$ENV{"GMP"}.'/include',     # e.g., '-I/usr/include/other' 
 );

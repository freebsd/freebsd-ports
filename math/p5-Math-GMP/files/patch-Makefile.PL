--- Makefile.PL	Sat Sep 18 22:48:14 1999
+++ Makefile.PL.new	Wed Jan  3 11:14:11 2001
@@ -6,6 +6,8 @@
 my $tar = (grep { -x "$_/tar" } @paths)[0] . "/tar";
 my $gzip = (grep { -x "$_/gzip" } @paths)[0] . "/gzip";
 
+# FreeBSD has GMP in the base system
+if ("" ne "" ) {
 my $cmd = "$gzip -dc gmp-2.0.2.tar.gz | $tar xf -";
 system $cmd unless -d 'gmp-2.0.2';
 die "tar extraction of gmp-2.0.2.tar.gz failed" unless -d 'gmp-2.0.2';
@@ -13,6 +15,7 @@
 chdir 'gmp-2.0.2';
 system "./configure --prefix=../gmp && make && make install";
 chdir '..';
+}
 
 WriteMakefile(
     'NAME'	=> 'Math::GMP',

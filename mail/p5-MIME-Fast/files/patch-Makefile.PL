--- Makefile.PL.orig	Thu Oct 16 13:01:46 2003
+++ Makefile.PL	Wed Dec  8 17:56:57 2004
@@ -6,6 +6,7 @@
 
 # my $libs = `pkg-config --libs gmime-2.0`;
 my $libs = `gmime-config --libs`;
+$libs =~ s/\-lgthread\-\d\.\d//;
 my $vers = `gmime-config --version`;
 
 if ($libs eq '') {
@@ -78,5 +79,5 @@
 	},
     'clean'             => { FILES => "gmime-version.h" },
     #    'INC'		=> `pkg-config --cflags gmime-2.0` # e.g., '-I/usr/include/other'
-    'INC'		=> "-I. -Icinclude " . `gmime-config --cflags`,
+    'INC'		=> "-I. -Icinclude -I$ENV{PREFIX}/include " . `gmime-config --cflags`,
 );

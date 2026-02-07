--- Makefile.PL.orig	2021-08-07 09:25:46 UTC
+++ Makefile.PL
@@ -9,8 +9,8 @@ my $config; # store various configurations to check
 
 # use the pkg-config wrapper for FreeType
 if( which('freetype-config') ) {
-    chomp($config->{ft_config}{LIBS} = `freetype-config --libs`);
-    chomp($config->{ft_config}{INC}  = `freetype-config --cflags`);
+    chomp($config->{ft_config}{LIBS} = `pkg-config freetype2 --libs`);
+    chomp($config->{ft_config}{INC}  = `pkg-config freetype2 --cflags`);
 }
 
 # default configuration

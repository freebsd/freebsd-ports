--- Makefile.PL.orig	Wed Apr 18 22:00:41 2007
+++ Makefile.PL	Wed Apr 18 22:01:40 2007
@@ -1380,7 +1380,10 @@
     my $string = $self->MM::install;
     my $add = "";
     if ($USE_APXS) {
-        $add = "apxs_install";
+      # XXX The FreeBSD port for mod_perl takes care of installing libperl.so
+      # itself via the pkg-install script.
+      #
+      #  $add = "apxs_install";
     }
     elsif ($win32_auto and 
            ($win32_args{INSTALL_DLL} or $win32_args{INSTALL_LIB})) {

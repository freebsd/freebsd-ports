--- Makefile.PL.orig	Thu Feb 15 12:39:35 2001
+++ Makefile.PL	Thu Feb 15 12:41:28 2001
@@ -1300,7 +1300,11 @@
     my $string = $self->MM::install;
     my $add = "";
     if($USE_APXS) {
-	$add = "apxs_install";
+# XXX The FreeBSD port for mod_perl takes care of installing libperl.so
+# itself via the pkg-install script.
+#
+#	$add = "apxs_install";
+	print "Disabling apxs_install target; deferred to pkg-install\n";
     }
     elsif ($win32_auto and $win32_args{INSTALL_DLL}) {
       $add = 'amp_install';

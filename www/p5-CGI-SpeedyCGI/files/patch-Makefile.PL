--- Makefile.PL.orig	Sat Mar  1 09:16:07 2003
+++ Makefile.PL	Sat Mar  1 09:17:19 2003
@@ -6,26 +6,26 @@
     import SpeedyMake qw(%write_makefile_common);
 }
 
-print <<END;
-
-Optional mod_speedycgi support.
-
-Mod_speedycgi increases performance under Apache by avoiding the fork/exec
-overhead associated with each request under normal SpeedyCGI.  However, it
-requires a working copy of "apxs" in your path, Apache with mod_so
-support, and additional Apache configuration.
-
-END
-print "Compile mod_speedycgi (default no)? ";
+#print <<END;
+#
+#Optional mod_speedycgi support.
+#
+#Mod_speedycgi increases performance under Apache by avoiding the fork/exec
+#overhead associated with each request under normal SpeedyCGI.  However, it
+#requires a working copy of "apxs" in your path, Apache with mod_so
+#support, and additional Apache configuration.
+#
+#END
+#print "Compile mod_speedycgi (default no)? ";
 
 my @dirs = qw(src speedy_backend speedy);
 my $macro = $write_makefile_common{macro};
-if (<STDIN> =~ /y/i) {
-    die "ERROR: Could not find a working copy of 'apxs' in your path.\n"
-	unless $macro->{APACHE_APXS_WORKS};
-    print "Compiling for Apache version $macro->{APACHE_VERSION}\n";
-    push(@dirs, $macro->{MOD_SPEEDYCGI_DIR});
-}
+#if (<STDIN> =~ /y/i) {
+#    die "ERROR: Could not find a working copy of 'apxs' in your path.\n"
+#	unless $macro->{APACHE_APXS_WORKS};
+#    print "Compiling for Apache version $macro->{APACHE_VERSION}\n";
+#    push(@dirs, $macro->{MOD_SPEEDYCGI_DIR});
+#}
 
 WriteMakefile(
     NAME		=> 'CGI::SpeedyCGI',
@@ -47,12 +47,12 @@
 sub postamble {
     my $extra = SpeedyMake->optdefs_cmds('src');
     my $test_install_extra;
-    if (my $mod_dir = $macro->{MOD_SPEEDYCGI_DIR}) {
-	$extra .=
-	    "\ninstall ::\n\tcd $mod_dir && \$(MAKE) install\n";
-	$test_install_extra =
-	    "\t\@cd $mod_dir && \$(MAKE) test_install \$(PASTHRU)\n";
-    }
+#    if (my $mod_dir = $macro->{MOD_SPEEDYCGI_DIR}) {
+#	$extra .=
+#	    "\ninstall ::\n\tcd $mod_dir && \$(MAKE) install\n";
+#	$test_install_extra =
+#	    "\t\@cd $mod_dir && \$(MAKE) test_install \$(PASTHRU)\n";
+#    }
 
 '
 test_install:

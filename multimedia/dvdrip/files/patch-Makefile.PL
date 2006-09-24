--- Makefile.PL.orig	Sat Sep 23 14:08:26 2006
+++ Makefile.PL	Sat Sep 23 14:14:33 2006
@@ -14,7 +14,7 @@
 	'Event'                 => 1.06,
         'Gtk2::Ex::FormFactory' => 0.65,
         'Event::ExecFlow'       => 0.62,
-        'Event::RPC'            => 0.89,
+#       'Event::RPC'            => 0.89,
         'AnyEvent'              => 1.02,
 );
 
@@ -66,8 +66,8 @@
         next unless $module_dist_file;
         
         #-- now check if this module is already installed
-        my $out = qx[ perl -M$module -e1 2>&1 >/dev/null && echo PERL_MODULE_OK 2>&1 ];
-        next if $out =~ /PERL_MODULE_OK/;
+	my $out = qx[ perl -M$module -e1 2>&1 >/dev/null && echo PERL_MODULE_OK 2>&1 ];
+	# next if $out =~ /PERL_MODULE_OK/;
         
         #-- Ok, module is missing and will be installed during
         #-- dvd::rip install
@@ -104,19 +104,19 @@
 
     if ( @modules ) {
         @modules = sort @modules;
-        print "\n";
-        print "Note:\n";
-        print "-----\n";
-        print "The following modules are required for dvd::rip but not found on your\n";
-        print "system. They're shipped with dvd::rip for your convenience and will be\n";
-        print "installed automatically when you run 'make install':\n\n";
-        print "  @modules\n";
-        print "\n";
-        print "You can ignore the 'prerequisite not found' warnings beyond for them.\n\n";
-        print "If you don't like this and want to install these modules manually\n";
-        print "just set SKIP_UNPACK_REQUIRED_MODULES before executing Makefile.PL,\n";
-        print "e.g. this way:\n\n";
-        print "  SKIP_UNPACK_REQUIRED_MODULES=1 perl Makefile.PL\n\n";
+#        print "\n";
+#        print "Note:\n";
+#        print "-----\n";
+#        print "The following modules are required for dvd::rip but not found on your\n";
+#        print "system. They're shipped with dvd::rip for your convenience and will be\n";
+#        print "installed automatically when you run 'make install':\n\n";
+#        print "  @modules\n";
+#        print "\n";
+#        print "You can ignore the 'prerequisite not found' warnings beyond for them.\n\n";
+#        print "If you don't like this and want to install these modules manually\n";
+#        print "just set SKIP_UNPACK_REQUIRED_MODULES before executing Makefile.PL,\n";
+#        print "e.g. this way:\n\n";
+#        print "  SKIP_UNPACK_REQUIRED_MODULES=1 perl Makefile.PL\n\n";
     }
 
     return join(" ", @files);

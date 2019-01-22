--- Makefile.PL.orig	2018-01-12 02:11:18 UTC
+++ Makefile.PL
@@ -333,7 +333,8 @@ my $orig = \&ExtUtils::MM_Unix::c_o;
 	foreach (@rv) {
 		# add c++0x flag only for cpp files
 		# otherwise XS perl handshake fails
-		s/\$\*\.c(pp|xx)\s*(?=\n|\r|\Z)/-xc++ -std=c++0x \$\*\.c$1/g
+		s/\$\*\.c\s*(?=\n|\r|\Z)/\$\*\.c$1 -o \$\*.o/g;
+		s/\$\*\.c(pp|xx)\s*(?=\n|\r|\Z)/-xc++ -std=c++0x \$\*\.c$1 -o \$\*\.o/g;
 	}
 	return @rv;
 };
@@ -719,7 +720,7 @@ sub libsass_plugin_glob
 	# special case (does not compile with perl inc path)
 	# readdir and friends were not available from headers
 	push @ret, 'plugins/glob/vendor/FS$(OBJ_EXT):';
-	push @ret, "\t" . '$(CCCMD) $(CCCDLFLAGS) $(PASTHRU_DEFINE) $(DEFINE) -xc++ -std=c++0x $*.cpp';
+	push @ret, "\t" . '$(CCCMD) $(CCCDLFLAGS) $(PASTHRU_DEFINE) $(DEFINE) -xc++ -std=c++0x $*.cpp -o $*.o';
 	# create the target for the makefile
 	push @ret, '$(GLOB_LIB): $(LIBSASS_LIB) $(GLOB_OBJ)';
 	# make sure the plugin path exists for output

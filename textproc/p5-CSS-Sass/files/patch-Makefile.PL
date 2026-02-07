--- Makefile.PL.orig	2019-05-19 16:09:14 UTC
+++ Makefile.PL
@@ -374,8 +374,8 @@ my $orig = \&ExtUtils::MM_Unix::c_o;
 		# sometimes g++, thus we need to force the
 		# compiler to compile in the specific language
 		# fixes https://github.com/sass/perl-libsass/issues/38
-		s/\$\*\.c\s*(?=\n|\r|\Z)/-xc \$\*\.c/g;
-		s/\$\*\.c(pp|xx)\s*(?=\n|\r|\Z)/-xc++ \$\*\.c$1/g;
+		s/\$\*\.c\s*(?=\n|\r|\Z)/-xc \$\*\.c -o \$\*.o/g;
+		s/\$\*\.c(pp|xx)\s*(?=\n|\r|\Z)/-xc++ \$\*\.c$1 -o \$\*.o/g;
 		# add c++0x flag only for cpp files
 		# otherwise XS perl handshake fails
 		s/\$\*\.c(pp|xx)\s*(?=\n|\r|\Z)/-std=c++0x \$\*\.c$1/g
@@ -750,7 +750,7 @@ sub libsass_plugin_glob
 	# special case (does not compile with perl inc path)
 	# readdir and friends were not available from headers
 	push @ret, 'plugins/glob/vendor/FS$(OBJ_EXT):';
-	push @ret, "\t" . '$(CCCMD) $(CCCDLFLAGS) $(PASTHRU_DEFINE) $(DEFINE) -xc++ -std=c++0x $*.cpp';
+	push @ret, "\t" . '$(CCCMD) $(CCCDLFLAGS) $(PASTHRU_DEFINE) $(DEFINE) -xc++ -std=c++0x $*.cpp -o $*.o';
 	# create the target for the makefile
 	push @ret, '$(GLOB_LIB): $(LIBSASS_LIB) $(GLOB_OBJ)';
 	# make sure the plugin path exists for output

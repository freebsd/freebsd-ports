--- Makefile.PL.orig	2019-04-10 22:57:22 UTC
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
@@ -607,7 +607,7 @@ my $reported = 0;
 sub compile_lib {
 	my ($mm, $name) = @_;
 	my @args = (
-		'$(LD) $(OPTIMIZE) -lstdc++ -shared', "-o ${name}",
+		'$(LD) $(OPTIMIZE) -shared', "-o ${name}",
 	);
 	# need special path on windows and MSVC (cl)
 	if ($^O eq 'MSWin32' && $Config{cc} =~ /^cl/) {
@@ -644,10 +644,10 @@ sub libsass_sassc
 	else {
 		# create the sassc executable by linking against sassc and libsass
 		push @ret, "\t" . '$(LD) -o $(SASSC_EXE) $(LDFLAGS) $(SASSC_OBJ) $(LIBS)'
-		         . ' ' . ($static ? '$(LIBSASS_OBJ)' : '-L$(INST_BIN) -lsass -lstdc++')
-		         . ' $(OPTIMIZE) -lstdc++ -std=c++0x ' . join(" ", @libs)
+		         . ' ' . ($static ? '$(LIBSASS_OBJ)' : '-L$(INST_ARCHLIB) -lsass')
+		         . ' $(OPTIMIZE) -std=c++0x ' . join(" ", @libs)
 		         . ($^O eq "linux" ? ' -ldl' : '')
-		         . ' -Wl,-rpath,$(INST_BIN)';
+		         . ' -Wl,-rpath,$(INST_ARCHLIB)';
 	}
 	# add target to virtual "pure_all"
 	push @cleanups, '$(SASSC_OBJ)';
@@ -662,7 +662,7 @@ sub libsass_lib
 	# register our source and object files
 	my @ret = 'LIBSASS_OBJ = ' . join(" ", @SOURCES);
 	# location of the created object
-	push @ret, 'LIBSASS_LIB = $(INST_BIN)/libsass.$(SO)';
+	push @ret, 'LIBSASS_LIB = $(INST_ARCHLIB)/libsass.$(SO)';
 	# create the target for the makefile
 	push @ret, '$(LIBSASS_LIB): $(LIBSASS_OBJ)';
 	# create the libsass shared library by linking against all objects
@@ -686,7 +686,7 @@ sub libsass_plugin_math
 	push @ret, "\t" . '$(MKPATH) $(INST_ARCHAUTODIR)/plugins/math';
 	# create the libsass shared library by linking against all objects
 	push @ret, "\t" . compile_lib($_[0], '$(MATH_LIB)') . ' $(MATH_OBJ)'
-		     . ' ' . ($static ? '$(LIBSASS_OBJ)' : '-L$(INST_BIN) -lsass -lstdc++');
+		     . ' ' . ($static ? '$(LIBSASS_OBJ)' : '-L$(INST_ARCHLIB) -lsass');
 	# add target to virtual "pure_all"
 	push @cleanups, '$(MATH_OBJ)';
 	push @cleanups, '$(MATH_LIB)';
@@ -706,7 +706,7 @@ sub libsass_plugin_img_size
 	push @ret, "\t" . '$(MKPATH) $(INST_ARCHAUTODIR)/plugins/img-size';
 	# create the libsass shared library by linking against all objects
 	push @ret, "\t" . compile_lib($_[0], '$(IMG_SIZE_LIB)') . ' $(IMG_SIZE_OBJ)'
-		     . ' ' . ($static ? '$(LIBSASS_OBJ)' : '-L$(INST_BIN) -lsass -lstdc++');
+		     . ' ' . ($static ? '$(LIBSASS_OBJ)' : '-L$(INST_ARCHLIB) -lsass');
 	# add target to virtual "pure_all"
 	push @cleanups, '$(IMG_SIZE_OBJ)';
 	push @cleanups, '$(IMG_SIZE_LIB)';
@@ -731,7 +731,7 @@ sub libsass_plugin_digest
 	push @ret, "\t" . '$(MKPATH) $(INST_ARCHAUTODIR)/plugins/digest';
 	# create the libsass shared library by linking against all objects
 	push @ret, "\t" . compile_lib($_[0], '$(DIGEST_LIB)') . ' $(DIGEST_OBJ)'
-	         . ' ' . ($static ? '$(LIBSASS_OBJ)' : '-L$(INST_BIN) -lsass -lstdc++');
+	         . ' ' . ($static ? '$(LIBSASS_OBJ)' : '-L$(INST_ARCHLIB) -lsass');
 	# add target to virtual "pure_all"
 	push @cleanups, '$(DIGEST_OBJ)';
 	push @cleanups, '$(DIGEST_LIB)';
@@ -749,14 +749,14 @@ sub libsass_plugin_glob
 	# special case (does not compile with perl inc path)
 	# readdir and friends were not available from headers
 	push @ret, 'plugins/glob/vendor/FS$(OBJ_EXT):';
-	push @ret, "\t" . '$(CCCMD) $(CCCDLFLAGS) $(PASTHRU_DEFINE) $(DEFINE) -xc++ -std=c++0x $*.cpp';
+	push @ret, "\t" . '$(CCCMD) $(CCCDLFLAGS) $(PASTHRU_DEFINE) $(DEFINE) -xc++ -std=c++0x $*.cpp -o $*.o';
 	# create the target for the makefile
 	push @ret, '$(GLOB_LIB): $(LIBSASS_LIB) $(GLOB_OBJ)';
 	# make sure the plugin path exists for output
 	push @ret, "\t" . '$(MKPATH) $(INST_ARCHAUTODIR)/plugins/glob';
 	# create the libsass shared library by linking against all objects
 	push @ret, "\t" . compile_lib($_[0], '$(GLOB_LIB)') . ' $(GLOB_OBJ)'
-	         . ' ' . ($static ? '$(LIBSASS_OBJ)' : '-L$(INST_BIN) -lsass -lstdc++');
+	         . ' ' . ($static ? '$(LIBSASS_OBJ)' : '-L$(INST_ARCHLIB) -lsass');
 	# add target to virtual "pure_all"
 	push @cleanups, '$(GLOB_OBJ)';
 	push @cleanups, '$(GLOB_LIB)';

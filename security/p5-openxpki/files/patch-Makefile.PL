--- Makefile.PL.orig	2023-06-21 23:40:24 UTC
+++ Makefile.PL
@@ -9,59 +9,11 @@ my $vergen = '../../tools/vergen';
 
 ###########################################################################
 # determine OpenSSL version
-## first we have to find a working OpenSSL
 
-# OPENSSL_LIB
-# OPENSSL_INC
-# OPENSSL_PREFIX set
-# /usr/local/ssl
-# /usr/local
-# /usr
-# /
-# ...
+my $openssl_inc_dir = "OPENSSLINC";
+my $openssl_lib_dir = "OPENSSLLIB";
+my $openssl_binary =  "OPENSSLBINARY";
 
-my $openssl_inc_dir = '';
-my $openssl_lib_dir = '';
-my $openssl_binary  = '';
-
-my @paths = qw( /usr/local/ssl
-                /opt/local/ssl
-                /usr/local
-                /opt/local
-                /usr
-                /opt
-              );
-
-unshift @paths, $ENV{OPENSSL_PREFIX}
-    if (exists $ENV{OPENSSL_PREFIX} and $ENV{OPENSSL_PREFIX} ne '');
-
-my $tmp_ver;
-
-foreach my $path (@paths) {
-    my $tmp_inc = File::Spec->catfile($path, 'include');
-    $tmp_ver = File::Spec->catfile($tmp_inc, 'openssl', 'opensslv.h');
-    my $tmp_lib = File::Spec->catfile($path, 'lib');
-    my $tmp_bin = File::Spec->catfile($path, 'bin', 'openssl');
-
-    if (-d $tmp_inc &&
-        -d $tmp_lib &&
-        -r $tmp_ver &&
-        -r $tmp_bin && -x $tmp_bin) {
-        $openssl_inc_dir = $tmp_inc;
-        $openssl_lib_dir = $tmp_lib;
-        $openssl_binary  = $tmp_bin;
-        last;
-    }
-}
-
-# accept settings from OPENSSL_INC and OPENSSL_LIB if BOTH exist
-if (exists $ENV{OPENSSL_INC} && $ENV{OPENSSL_INC} != "" &&
-    exists $ENV{OPENSSL_LIB} && $ENV{OPENSSL_LIB} != ""
-) {
-    $openssl_inc_dir = $ENV{OPENSSL_INC};
-    $openssl_lib_dir = $ENV{OPENSSL_LIB};
-}
-
 die "Could not find usable OpenSSL installation. Stopped"
     unless defined $openssl_inc_dir;
 
@@ -72,60 +24,10 @@ print STDERR "OpenSSL library: $openssl_lib_dir\n";
 print STDERR "OpenSSL headers: $openssl_inc_dir\n";
 print STDERR "OpenSSL binary:  $openssl_binary\n";
 
-# ask the binary for it's version
-# openssl version should produce output like this:
-# OpenSSL 0.9.7l 28 Sep 2006
-# OpenSSL 1.0.0a 1 Jun 2010
-my $openssl_version_string = `$openssl_binary version`;
-my ($openssl_version_major, $openssl_version_minor, $openssl_version_fix, $openssl_version_patch, $openssl_version_flavour);
-if ($openssl_version_string =~ m/\s*OpenSSL\s+(\d+)\.(\d+)\.(\d+)([a-zA-Z]+)/i) {
-    # OpenSSL 0.9
-    $openssl_version_flavour = 'OpenSSL';
-    $openssl_version_major = $1;
-    $openssl_version_minor = $2;
-    $openssl_version_fix   = $3;
-    $openssl_version_patch = $4;
-    print "$openssl_version_flavour version: major=$openssl_version_major, minor=$openssl_version_minor, fix=$openssl_version_fix, patch=$openssl_version_patch\n";
-
-} elsif ($openssl_version_string =~ m/\s*(OpenSSL|LibreSSL)\s+(\d+)\.(\d+)\.(\d+)\s+/) {
-    # OpenSSL 1.0
-    $openssl_version_flavour = $1;
-    $openssl_version_major = $2;
-    $openssl_version_minor = $3;
-    $openssl_version_fix   = $4;
-    print "OpenSSL version: major=$openssl_version_major, minor=$openssl_version_minor, fix=$openssl_version_fix\n";
-} else {
-    print "Problem: malformed openssl version string!\n";
-    print STDERR "Consider setting OPENSSL_PREFIX correctly.\n\n";
-    exit 1;
-}
-
-# Warn on old openssl - should work but lacks support for some features
-if ($openssl_version_major == 0 &&
-    $openssl_version_minor == 9 &&
-    $openssl_version_fix   == 8
-) {
-    print STDERR "Warning: openssl 0.9.8 found - this will work but lacks some features, e.g. server side key generation!";
-
-} elsif ( $openssl_version_flavour =~ m/LibreSSL/i ) {
-    print STDERR "Warning: LibreSSL found, support for LibreSSL is experimental!";
-
-} elsif (not
-    ($openssl_version_flavour =~ m/OpenSSL/i &&
-     $openssl_version_major == 1 &&
-     (($openssl_version_minor == 0) || ($openssl_version_minor == 1) ))
-) {
-    print STDERR "\n";
-    print STDERR "ERROR: OpenSSL 0.9.8, 1.0 or 1.1 is required.\n";
-    print STDERR "Consider setting OPENSSL_PREFIX correctly.\n\n";
-    exit 1;
-}
-
 # make OpenSSL binary location available to tests
 open my $fh, ">", File::Spec->catfile("t", "cfg.binary.openssl");
 print $fh $openssl_binary;
 close $fh;
-
 
 ###########################################################################
 # determine OpenXPKI version

--- Makefile.PL.orig	2016-04-07 09:30:16 UTC
+++ Makefile.PL
@@ -267,49 +267,6 @@ else {
   print STDERR "Logger is not installed. Continue anyway.\n";
 }
 
-# check if we should add -shared
-# not all platforms support this feature
-my %flags = ();
-
-open $fh, '>test.c' or die "Cannot open test.c. Stopped";
-print $fh "int main() {}\n";
-close $fh;
-use Config;
-my $cc = $Config{'cc'};
-
-my $cc_supports_shared = 1;
-if (open $fh, "$cc -shared -o test test.c 2>&1 |") {
-    while (my $line = <$fh>) {
-        if ($line =~ m{ unrecognized .* option .* -shared }xms) {
-	    $cc_supports_shared = 0;
-        }
-    }
-    close $fh;
-    if ($CHILD_ERROR) {
-        $cc_supports_shared = 0;
-    }
-
-    if (! $cc_supports_shared)
-    {
-        print STDERR "C compiler does not support -shared.\n";
-    }
-    else {
-        if ($^O ne 'darwin') {
-            print STDERR "C compiler supports -share. Adding it to LDDLFLAGS.\n";
-            $flags{'LDDLFLAGS'} = '-shared';
-        }
-        else {
-            print STDERR "C compiler claims to support -share. But we are on Mac OS X, experience shows that it still does not work with -share, so we won't add it to LDDLFLAGS ...\n";
-        }
-    }
-}
-else {
-    print STDERR "Could not run C compiler. Continue anyway.\n";
-}
-
-unlink('test.c');
-unlink('test');
-
 # See lib/ExtUtils/MakeMaker.pm for details of how to influence
 # the contents of the Makefile that is written.
 WriteMakefile(
@@ -317,7 +274,6 @@ WriteMakefile(
     'VERSION'   => $openxpki_version,
     'LIBS'      => ["-L$openssl_lib_dir -lcrypto"],
     'INC'       => "-I. -I$openssl_inc_dir",
-    'CCFLAGS'   => '-O2 -g '.$Config{ccflags},
     'PREREQ_PM' => {
 #    'Class::Accessor::Fast'  => '0.31', # Constituent of module Class::Accessor
 #					 # which is a prerequisite of Class::Accessor::Chained, see below
@@ -420,5 +376,4 @@ WriteMakefile(
                               't/cfg.binary.openssl']},
     'XSPROTOARG' => '-noprototypes',
     'EXE_FILES' => [ 'bin/openxpkictl','bin/openxpkicmd', 'bin/openxpkiadm', 'bin/openxpkicli'],    
-    %flags,
 );

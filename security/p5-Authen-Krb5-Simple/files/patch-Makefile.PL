--- Makefile.PL.orig	2012-01-08 23:11:50.000000000 +0900
+++ Makefile.PL	2015-01-04 05:07:53.000000000 +0900
@@ -8,56 +8,26 @@
 #
 ###############################################################################
 #
-use lib 'inc';
-use Devel::CheckLib;
 use ExtUtils::MakeMaker;
 
-my ($krb5_inc, $krb5_lib);
-
-# Places we might find Kerberos5 libs.
-#
-my @krb_lib_dirs =  qw(
-    /usr/lib64
-    /usr/lib
-    /usr/local/lib64
-    /usr/local/lib
-    /usr/lib64/krb5
-    /usr/lib/krb5
-    /usr/local/lib64/krb5
-    /usr/local/lib/krb5
-    /usr/lib64/krb
-    /usr/lib/krb
-    /usr/local/lib64/krb
-    /usr/local/lib/krb
-    /opt/krb5/lib64
-    /opt/krb5/lib
-    /opt/krb/lib64
-    /opt/krb/lib
-    /usr/heimdal/lib64
-    /usr/heimdal/lib
-    /usr/local/heimdal/lib64
-    /usr/local/heimdal/lib
-    /opt/heimdal/lib64
-    /opt/heimdal/lib
-);
+my $CONF = $ENV{"GSSAPIBASEDIR"} . "/bin/krb5-config";
+my $DEFS;
+my $KRB5_INCS;
+my $KRB5_LIBS;
 
-# If the ENV vars are specified, use them.
-#
-if(exists($ENV{KRB5_INCLUDE})) {
-    $krb5_inc = "-I$ENV{KRB5_INCLUDE}";
-}
-if(exists($ENV{KRB5_LIB})) {
-    $krb5_lib = "-L$ENV{KRB5_LIB}";
-    unshift(@krb_lib_dirs, $ENV{KRB5_LIB});
+if (-f $CONF) {
+	$KRB5_LIBS = `$CONF --libs krb5`;
+	$KRB5_INCS = `$CONF --cflags krb5`;
+	chomp($KRB5_LIBS);
+	chomp($KRB5_INCS);
+} else {
+	$KRB5_LIBS = $ENV{'GSSAPILDFLAGS'} . " " . $ENV{'GSSAPILIBS'};
+	$KRB5_INCS = $ENV{'GSSAPICPPFLAGS'};
 }
 
-# See if the needed libs are available.  Take a shot at several "possible"
-# locations for these libs.
-#
-check_lib_or_exit(
-    lib     => [qw( krb5 )],
-    libpath => \@krb_lib_dirs
-) unless($ENV{skip_lib_check});
+if (defined($ENV{'HAVE_HEIMDAL'})) {
+	$DEFS = "-DHAVE_HEIMDAL";
+}
 
 # Write out the Makefile
 #
@@ -73,9 +43,9 @@
             AUTHOR     => 'Damien S. Stuart <dstuart@dstuart.org>')
         : ()
     ),
-    'LIBS'      => ["$krb5_lib -lkrb5"],
-    'DEFINE'    => '',
-    'INC'       => $krb5_inc,
+    'LIBS'      => [$KRB5_LIBS],
+    'DEFINE'    => $DEFS,
+    'INC'       => $KRB5_INCS,
 );
 
 

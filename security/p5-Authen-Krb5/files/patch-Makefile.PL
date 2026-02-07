--- Makefile.PL.orig	2008-03-16 23:59:50.000000000 +0900
+++ Makefile.PL	2015-01-04 06:44:41.000000000 +0900
@@ -1,39 +1,33 @@
 use ExtUtils::MakeMaker;
 
-##### CHANGE THESE ACCORDING TO YOUR CONFIGURATION #####
-
-# location of Kerberos 5 libraries
-my $KRB5_LIBDIR = '/usr/lib';
+my $CONF = $ENV{"GSSAPIBASEDIR"} . "/bin/krb5-config";
+my $DEFS;
+my $KRB5_INCS;
+my $KRB5_LIBS;
 
-# any extra libraries?
-# add -lresolv here if you get errors like the following (usually on linux):
-#  undefined symbol: __res_search
-my $KRB5_EXTRALIBS = '-lresolv';
+if (-f $CONF) {
+	$KRB5_LIBS = `$CONF --libs krb5`;
+	$KRB5_INCS = `$CONF --cflags krb5`;
+	chomp($KRB5_LIBS);
+	chomp($KRB5_INCS);
+} else {
+	$KRB5_LIBS = $ENV{'GSSAPILDFLAGS'} . " " . $ENV{'GSSAPILIBS'};
+	$KRB5_INCS = $ENV{'GSSAPICPPFLAGS'};
+}
 
-# location of Kerberos 5 includes
-my $KRB5_INCDIR = '/usr/include';
+if (defined($ENV{'HAVE_HEIMDAL'})) {
+	$DEFS = "-DHAVE_HEIMDAL";
+}
 
-# any extra include flags?
-my $KRB5_EXTRAINCS = '';
+print "KRB5_LIBS: $KRB5_LIBS\n";
+print "KRB5_INCS: $KRB5_INCS\n";
 
 ##### DO NOT CHANGE ANYTHING BELOW HERE #####
 
-# check for libk5crypto -- only in krb5-1.1 and above
-print "Checking for libk5crypto...";
-my $cryptolib;
-if ( -r "${KRB5_LIBDIR}/libk5crypto.a" || -r "${KRB5_LIBDIR}/libk5crypto.so" ) {
-	print "yes\n";
-	$cryptolib = '-lk5crypto';
-}
-else {
-	print "no.  I'll use libcrypto instead.\n";
-	$cryptolib = '-lcrypto';
-}
-
 WriteMakefile(
     'NAME'	=> 'Authen::Krb5',
     'VERSION_FROM' => 'Krb5.pm',
-    'LIBS'	=> ["-L${KRB5_LIBDIR} -lkrb5 ${cryptolib} -lcom_err $KRB5_EXTRALIBS"],
-    'DEFINE'	=> '',
-    'INC'	=> "-I${KRB5_INCDIR} $KRB5_EXTRAINCS"
+    'LIBS'	=> [$KRB5_LIBS],
+    'DEFINE'	=> $DEFS,
+    'INC'	=> $KRB5_INCS
 );

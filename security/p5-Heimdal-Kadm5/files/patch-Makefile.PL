--- Makefile.PL.orig	2010-02-05 06:33:46.000000000 +0900
+++ Makefile.PL	2015-01-04 04:37:19.000000000 +0900
@@ -1,23 +1,23 @@
 use ExtUtils::MakeMaker;
 # $Id$
 
-my $find_krb5_config;
-
-my $lflags= '-L/pkg/heimdal/default/lib -lkrb5 -lroken -lasn1 -ldes -lkadm5clnt';
-my $cflags= '-I/usr/heimdal/default/include' ;
-
-my @args = ("krb5-config", "--version");
-$find_krb5_config = system(@args);
+my $CONF = $ENV{"GSSAPIBASEDIR"} . "/bin/krb5-config";
+my $DEF;
+my $KRB5_INCS;
+my $KRB5_LIBS;
 
-if ($find_krb5_config eq 0) {
-    $lflags = `krb5-config --libs kadm-client`;
-    $cflags = `krb5-config --cflags kadm-client`;
-    chomp $lflags;
-    chomp $cflags;
+if (-f $CONF) {
+	$KRB5_LIBS = `$CONF --libs kadm-client`;
+	$KRB5_INCS = `$CONF --cflags kadm-client`;
+	chomp($KRB5_LIBS);
+	chomp($KRB5_INCS);
+} else {
+	$KRB5_LIBS = $ENV{'GSSAPILDFLAGS'} . " " . $ENV{'GSSAPILIBS'};
+	$KRB5_INCS = $ENV{'GSSAPICPPFLAGS'};
 }
 
-printf "cflags: $cflags\n";
-printf "lflags: $lflags\n";
+printf "KRB5_INCS = $KRB5_INCS\n";
+printf "KRB5_LIBS = $KRB5_LIBS\n";
 
 WriteMakefile(
     'NAME'		=> 'Heimdal::Kadm5',
@@ -26,7 +26,7 @@
     ($] >= 5.005 ?
       (ABSTRACT_FROM => 'Kadm5.pm',
        AUTHOR     => 'Leif Johansson <leifj@it.su.se>') : ()),
-    'LIBS'      => [ $lflags ],
-    'INC'       => $cflags ,
+    'LIBS'      => [ $KRB5_LIBS ],
+    'INC'       => $KRB5_INCS ,
     'DEFINE'		=> '',
 );

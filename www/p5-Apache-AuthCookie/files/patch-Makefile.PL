--- Makefile.PL	Sat Apr 15 10:15:32 2000
+++ Makefile.PL.new	Mon Jan  1 02:51:49 2001
@@ -4,14 +4,20 @@
 
 my $default = $ENV{'APACHE'} || '/usr/lib/httpd/httpd';
 $|=1;
+if ("" ne "") {
 print("\nFor testing purposes, please give the full path to an httpd\n",
       "with mod_perl and at least the following hooks enabled: PERL_AUTHEN,\n",
       "PERL_AUTHZ, PERL_STACKED_HANDLERS, PERL_METHOD_HANDLERS.\n",
       "The path defaults to \$ENV{APACHE}, if present.\n",
      );
-
+}
 my %conf;
+$conf{httpd} = "/usr/local/sbin/apache"; $conf{httpd} = $ENV{'APACHE'} if ($ENV{'APACHE'} ne "");
+$conf{user} = "nobody"; $conf{user} = $ENV{'TESTUSER'} if ($ENV{'TESTUSER'} ne "");
+$conf{group} = "nobody"; $conf{group} = $ENV{'TESTGRP'} if ($ENV{'TESTGRP'} ne "");
+$conf{port} = 8228; $conf{port} = $ENV{'TESTPORT'} if ($ENV{'TESTPORT'} ne "");
 
+if ("" ne "") {
 do {
   print "\n [$default]: ";
   chomp ($conf{httpd} = <STDIN>);
@@ -32,7 +38,7 @@
 print "Port to run tests under [$default]: ";
 chomp ($conf{port} = <STDIN>);
 $conf{port} ||= $default;
-
+}
 
 open LOC, ">t/httpd.loc" or die "can't write t/httpd.loc: $!";
 print LOC map {"$_=$conf{$_}\n"} keys %conf;

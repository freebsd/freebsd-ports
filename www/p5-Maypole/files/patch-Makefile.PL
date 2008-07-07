--- ./Makefile.PL.orig	Thu Jul 20 13:50:25 2006
+++ ./Makefile.PL	Tue Apr  3 13:12:31 2007
@@ -27,7 +27,6 @@
         HTTP::Headers                    => 1.59,
         Template                         => 0,
         Template::Plugin::Class          => 0,
-        Test::MockModule                 => 0,
         Digest::MD5			 => 0,
 	File::MMagic::XS		 => 0.08,
 	Class::DBI::Plugin::Type	 => 0,
@@ -56,7 +55,7 @@
     eval { require DBD::SQLite } or do {
         print "Error loading DBD::SQLite, trying DBD::SQLite2\n";
         eval {require DBD::SQLite2} ? $driver = 'SQLite2'
-            : die "DBD::SQLite2 is not installed";
+            : do { warn "DBD::SQLite2 is not installed"; exit ; }
     };
     require DBI;
     my $dbh = DBI->connect("dbi:$driver:dbname=t/beerdb.db");

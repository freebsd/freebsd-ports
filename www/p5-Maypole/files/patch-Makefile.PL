--- Makefile.PL.orig	Fri Jul 22 15:06:47 2005
+++ Makefile.PL	Fri Jul 22 15:08:01 2005
@@ -24,7 +24,6 @@
         HTTP::Headers                    => 1.59,
         Template                         => 0,
         Template::Plugin::Class          => 0,
-        Test::MockModule                 => 0,
 	Digest::MD5			 => 0,
     },    # e.g., Module::Name => 1.1
     (
@@ -51,7 +50,7 @@
     eval { require DBD::SQLite } or do {
         print "Error loading DBD::SQLite, trying DBD::SQLite2\n";
         eval {require DBD::SQLite2} ? $driver = 'SQLite2'
-            : die "DBD::SQLite2 is not installed";
+            : do { warn "DBD::SQLite2 is not installed"; exit ; }
     };
     require DBI;
     my $dbh = DBI->connect("dbi:$driver:dbname=t/beerdb.db");

--- Makefile.PL.orig	Fri Dec 24 04:50:50 2004
+++ Makefile.PL	Sun Dec 26 12:50:10 2004
@@ -24,7 +24,6 @@
         HTTP::Headers                    => 1.59,
         Template                         => 0,
         Template::Plugin::Class          => 0,
-        Test::MockModule                 => 0,
     },    # e.g., Module::Name => 1.1
     (
         $] >= 5.005
@@ -50,7 +49,7 @@
     eval { require DBD::SQLite } or do {
         print "Error loading DBD::SQLite, trying DBD::SQLite2\n";
         eval {require DBD::SQLite2} ? $driver = 'SQLite2'
-            : die "DBD::SQLite2 is not installed";
+            : do { warn "DBD::SQLite2 is not installed"; exit ; }
     };
     require DBI;
     my $dbh = DBI->connect("dbi:$driver:dbname=t/beerdb.db");

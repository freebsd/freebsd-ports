--- Makefile.PL.orig	Mon Nov  8 22:07:59 2004
+++ Makefile.PL	Mon Nov  8 22:08:46 2004
@@ -38,7 +38,10 @@
 if ( !-e "t/beerdb.db" ) {
     print "Making SQLite DB\n";
     eval { require DBD::SQLite };
-    die "No, wait, we don't have SQLite installed. Never mind\n" if $@;
+    if ($@) {
+        warn "No, wait, we don't have SQLite installed. Never mind\n";
+        exit;
+    }
     require DBI;
     my $dbh = DBI->connect("dbi:SQLite:dbname=t/beerdb.db");
 

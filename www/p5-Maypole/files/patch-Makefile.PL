--- Makefile.PL.orig	Fri Apr 16 19:16:55 2004
+++ Makefile.PL	Sat Apr 17 22:15:01 2004
@@ -27,7 +27,10 @@
 if (!-e "t/beerdb.db") {
     print "Making SQLite DB\n";
     eval { require DBD::SQLite };
-    die "No, wait, we don't have SQLite installed. Never mind\n" if $@;
+    if ($@) {
+        warn "No, wait, we don't have SQLite installed. Never mind\n";
+        exit;
+    }
     require DBI;
     my $dbh = DBI->connect("dbi:SQLite:dbname=t/beerdb.db");
 

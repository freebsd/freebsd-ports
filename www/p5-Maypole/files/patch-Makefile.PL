--- Makefile.PL.orig	Thu Mar 25 13:33:42 2004
+++ Makefile.PL	Thu Apr  8 18:13:57 2004
@@ -20,14 +20,17 @@
         Template => 0,
     }, # e.g., Module::Name => 1.1
     ($] >= 5.005 ?     ## Add these new keywords supported since 5.005
-      (ABSTRACT_FROM  => 'lib/Apache/MVC.pm', # retrieve abstract from module
+      (ABSTRACT_FROM  => 'lib/Maypole.pm', # retrieve abstract from module
        AUTHOR         => 'Simon Cozens <simon@simon-cozens.org>') : ()),
 );
 
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
 

--- Classifier/Bayes.pm.orig	Wed Dec 15 19:48:24 2004
+++ Classifier/Bayes.pm	Mon Dec 20 23:27:16 2004
@@ -218,7 +218,7 @@
     # $dbname can be used within it and it resolves to the full path
     # to the database named in the database parameter above.
 
-    $self->config_( 'dbconnect', 'dbi:SQLite:dbname=$dbname' );
+    $self->config_( 'dbconnect', 'dbi:SQLite2:dbname=$dbname' );
     $self->config_( 'dbuser', '' ); $self->config_( 'dbauth', '' );
 
     # SQLite 1.05+ have some problems we are resolving.  This lets us

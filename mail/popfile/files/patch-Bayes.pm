--- Classifier/Bayes.pm.dist	Fri Sep  3 07:16:08 2004
+++ Classifier/Bayes.pm	Sun Oct 24 03:41:07 2004
@@ -211,7 +211,7 @@
     # it resolves to the full path to the database named in the
     # database parameter above.
 
-    $self->config_( 'dbconnect', 'dbi:SQLite:dbname=$dbname' );
+    $self->config_( 'dbconnect', 'dbi:SQLite2:dbname=$dbname' );
     $self->config_( 'dbuser', '' ); $self->config_( 'dbauth', '' );
 
     # No default unclassified weight is the number of times more sure POPFile

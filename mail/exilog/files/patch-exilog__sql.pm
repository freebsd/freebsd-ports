--- exilog_sql.pm.orig	2005-08-24 14:22:29 UTC
+++ exilog_sql.pm
@@ -208,7 +208,7 @@ sub _pgsql_sql_queue_add {
 sub _pgsql_sql_optimize {
   my $where = shift || "nothing";
 
-  my $sql = "OPTIMIZE TABLE ".$where;
+  my $sql = "VACUUM ANALYZE  ".$where;
   my $sh = $dbh->prepare($sql);
   $sh->execute;
   $sh->finish;

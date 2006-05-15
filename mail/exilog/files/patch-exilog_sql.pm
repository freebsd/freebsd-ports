--- /usr/local/www/exilog/exilog_sql.pm	Tue Feb 21 16:23:56 2006
+++ exilog_sql.pm	Wed Aug 24 09:22:29 2005
@@ -208,7 +208,7 @@
 sub _pgsql_sql_optimize {
   my $where = shift || "nothing";
 
-  my $sql = "OPTIMIZE TABLE ".$where;
+  my $sql = "VACUUM ANALYZE  ".$where;
   my $sh = $dbh->prepare($sql);
   $sh->execute;
   $sh->finish;

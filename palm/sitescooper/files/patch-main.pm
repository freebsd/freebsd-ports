--- lib/Sitescooper/Main.pm.orig        Thu Aug  7 15:52:30 2003
+++ lib/Sitescooper/Main.pm     Thu Aug  7 15:52:50 2003
@@ -2309,8 +2309,8 @@
   print OUT qq{
  
 [scoop]
-db_name=$pdbtitle
-db_file=$sitename
+doc_name=$pdbtitle
+doc_file=$sitename
 home_url=plucker:/$convfilename
 home_maxdepth=9

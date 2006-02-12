--- inst/upgrade/lib/bric_upgrade.pm.orig	Tue Dec 20 07:37:14 2005
+++ inst/upgrade/lib/bric_upgrade.pm	Thu Feb  9 02:17:16 2006
@@ -288,6 +288,7 @@ sub test_table($) {
   exit if test_column $table_name, $column_name, $min_size;
   exit if test_column $table_name, $column_name, undef, $not_null;
   exit if test_column $table_name, $column_name, $min_size, $not_null;
+  exit if test_column $table_name, $column_name, $min_size, $not_null, $type;
 
 This function returns true if the specified column exists in specified table
 in the Bricolage database, and false if it does not. Use C<test_column()> in

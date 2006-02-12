--- inst/upgrade/1.8.9/add_element_member_fks.pl.orig	Tue Nov  1 05:31:35 2005
+++ inst/upgrade/1.8.9/add_element_member_fks.pl	Thu Feb  9 02:17:16 2006
@@ -7,7 +7,7 @@ use lib catdir $FindBin::Bin, updir, 'li
 use bric_upgrade qw(:all);
 
 exit unless test_table 'element_member';
-exit if test_constraint 'element_member', 'fk_member__at_member';
+exit if test_foreign_key 'element_member', 'fk_member__at_member';
 
 do_sql
     q{ DELETE FROM element_member

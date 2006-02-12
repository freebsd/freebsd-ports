--- inst/upgrade/1.9.1/rename_element_table.pl.orig	Tue Dec 20 07:37:14 2005
+++ inst/upgrade/1.9.1/rename_element_table.pl	Thu Feb  9 02:17:16 2006
@@ -123,7 +123,7 @@ do_sql
     q{ALTER TABLE element_type__site ALTER COLUMN id
       SET DEFAULT NEXTVAL('seq_element_type__site')},
     q{ALTER TABLE element_type__site DROP CONSTRAINT } . (
-        test_primary_key('element__site_pkey', 'element_type__site')
+        test_primary_key('element_type__site', 'element__site_pkey')
             ? 'element__site_pkey'
             : 'pk_element__site__id'
     ),

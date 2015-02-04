
$FreeBSD$

--- lib/ansible/modules/core/database/postgresql/postgresql_privs.py.orig
+++ lib/ansible/modules/core/database/postgresql/postgresql_privs.py
@@ -462,10 +462,13 @@
         if obj_type == 'group':
             set_what = ','.join(pg_quote_identifier(i, 'role') for i in obj_ids)
         else:
+            # function types are already quoted above
+            if obj_type != 'function':
+                obj_ids = [pg_quote_identifier(i, 'table') for i in obj_ids]
             # Note: obj_type has been checked against a set of string literals
             # and privs was escaped when it was parsed
             set_what = '%s ON %s %s' % (','.join(privs), obj_type,
-                                        ','.join(pg_quote_identifier(i, 'table') for i in obj_ids))
+                                        ','.join(obj_ids))
 
         # for_whom: SQL-fragment specifying for whom to set the above
         if roles == 'PUBLIC':

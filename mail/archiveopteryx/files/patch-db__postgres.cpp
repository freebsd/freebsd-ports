--- ./db/postgres.cpp.orig	2014-05-06 13:03:48.795894217 -0500
+++ ./db/postgres.cpp	2014-05-06 13:04:03.207891218 -0500
@@ -85,7 +85,7 @@
                 "from pg_locks h join pg_locks w using (locktype) "
                 "join pg_stat_activity a on (h.pid="
             );
-            if (Postgres::version() < 90300)
+            if (Postgres::version() < 90200)
                 s.append( "a.procpid" );
             else
                 s.append( "a.pid" );

--- cdr/cdr_pgsql.c.orig	2019-10-06 21:08:37 UTC
+++ cdr/cdr_pgsql.c
@@ -707,7 +707,7 @@ static int config_module(int reload)
 			schemaname = ast_alloca(strlen(tmp_schemaname) * 2 + 1);
 			PQescapeStringConn(conn, schemaname, tmp_schemaname, strlen(tmp_schemaname), NULL);
 
-			snprintf(sqlcmd, sizeof(sqlcmd), "SELECT a.attname, t.typname, a.attlen, a.attnotnull, d.adsrc, a.atttypmod FROM (((pg_catalog.pg_class c INNER JOIN pg_catalog.pg_namespace n ON n.oid = c.relnamespace AND c.relname = '%s' AND n.nspname = %s%s%s) INNER JOIN pg_catalog.pg_attribute a ON (NOT a.attisdropped) AND a.attnum > 0 AND a.attrelid = c.oid) INNER JOIN pg_catalog.pg_type t ON t.oid = a.atttypid) LEFT OUTER JOIN pg_attrdef d ON a.atthasdef AND d.adrelid = a.attrelid AND d.adnum = a.attnum ORDER BY n.nspname, c.relname, attnum",
+			snprintf(sqlcmd, sizeof(sqlcmd), "SELECT a.attname, t.typname, a.attlen, a.attnotnull, pg_catalog.pg_get_expr(d.adbin, d.adrelid) adsrc, a.atttypmod FROM (((pg_catalog.pg_class c INNER JOIN pg_catalog.pg_namespace n ON n.oid = c.relnamespace AND c.relname = '%s' AND n.nspname = %s%s%s) INNER JOIN pg_catalog.pg_attribute a ON (NOT a.attisdropped) AND a.attnum > 0 AND a.attrelid = c.oid) INNER JOIN pg_catalog.pg_type t ON t.oid = a.atttypid) LEFT OUTER JOIN pg_attrdef d ON a.atthasdef AND d.adrelid = a.attrelid AND d.adnum = a.attnum ORDER BY n.nspname, c.relname, attnum",
 				tablename,
 				ast_strlen_zero(schemaname) ? "" : "'", ast_strlen_zero(schemaname) ? "current_schema()" : schemaname, ast_strlen_zero(schemaname) ? "" : "'");
 		} else {

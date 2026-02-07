--- check_postgres.pl.orig	2015-04-08 10:32:58 UTC
+++ check_postgres.pl
@@ -47,7 +47,7 @@ our $DEFAULT_OUTPUT = 'nagios';
 
 ## If psql binaries are not in your path, it is recommended to hardcode it here,
 ## as an alternative to the --PGBINDIR option
-$PGBINDIR = '';
+$PGBINDIR = '%%LOCALBASE%%/bin';
 
 ## If this is true, $opt{PSQL} and $opt{PGBINDIR} are disabled for security reasons
 our $NO_PSQL_OPTION = 1;

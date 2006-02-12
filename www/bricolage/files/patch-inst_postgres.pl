--- inst/postgres.pl.orig	Sun Feb 12 12:39:15 2006
+++ inst/postgres.pl	Sun Feb 12 12:39:32 2006
@@ -133,14 +133,9 @@
     ask_password("Postgres Root Password (leave empty for no password)",
 		\$PG{root_pass}, $QUIET);
 
-    while(1) {
 	$PG{system_user} = $PG{root_user};
         ask_confirm("Postgres System Username", \$PG{system_user}, $QUIET);
 	$PG{system_user_uid} = (getpwnam($PG{system_user}))[2];
-	last if defined $PG{system_user_uid};
-	print "User \"$PG{system_user}\" not found!  This user must exist ".
-	    "on your system.\n";
-    }
 
     while(1) {
       ask_confirm("Bricolage Postgres Username", \$PG{sys_user}, $QUIET);

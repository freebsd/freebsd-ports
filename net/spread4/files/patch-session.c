--- session.c	Tue Aug  5 21:35:52 2003
+++ session.c	Tue Aug  5 21:31:30 2003
@@ -406,7 +406,7 @@
 	    Alarm( EXIT, "Sess_init: UNIX sock error\n" );
 
 	unix_addr.sun_family	= AF_UNIX;
-	sprintf( name, "/tmp/%d",My.port );
+	sprintf( name, "%s/spread.sock", _PATH_SPREAD_PIDDIR );
 	strcpy( unix_addr.sun_path, name ); 
 	unlink( name );
 

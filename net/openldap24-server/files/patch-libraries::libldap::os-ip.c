--- libraries/libldap/os-ip.c	Thu Jan 20 18:01:01 2005
+++ libraries/libldap/os-ip.c	Mon Jan 31 16:53:39 2005
@@ -258,15 +258,15 @@
 	if ( async ) return ( -2 );
 #endif
 
-	FD_ZERO(&wfds);
-	FD_SET(s, &wfds );
+	do {
+		FD_ZERO(&wfds);
+		FD_SET(s, &wfds );
 
 #ifdef HAVE_WINSOCK
-	FD_ZERO(&efds);
-	FD_SET(s, &efds );
+		FD_ZERO(&efds);
+		FD_SET(s, &efds );
 #endif
 
-	do {
 		rc = select(ldap_int_tblsize, z, &wfds,
 #ifdef HAVE_WINSOCK
 			&efds,

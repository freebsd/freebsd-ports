--- blip-0.1/msn_core.C.orig	Sat Dec 14 07:58:01 2002
+++ blip-0.1/msn_core.C	Thu Oct 23 20:02:19 2003
@@ -18,19 +18,18 @@
 #include <sys/stat.h>
 
 #include "md5.h"
-
 #include "msn_core.h"
 #include "msn_bittybits.h"
 #include "msn_interface.h"
+#include "../connwrap-0.1/connwrap.h"
 
 #define DEBUG 1
+#define MSN_VERSION_ID		0	// ID that is sent after commands like CHG, NLN, etc.
 
 // Define all those extern'ed variables in msn_core.h:
 llist * connections=NULL;
-
 int next_trid=10;
 char buf[BUF_SIZE]; // used for anything temporary
-
 char * errors[1000];
 char default_error_msg[]="Unknown error code";
 
@@ -218,143 +217,151 @@
   write(conn->sock, buf, strlen(buf));
 }
 
-void msn_sync_lists(msnconn * conn, int version)
+void msn_get_list_info( msnconn *conn, int nargs, char **args )
 {
-  syncinfo * info=new syncinfo;
+        char    buf[ 1000 ];
+	syncinfo *info;
 
-  info->serial=version;
+	info = conn->sync_info;
 
-  sprintf(buf, "SYN %d %d\r\n", next_trid, version);
-  write(conn->sock, buf, strlen(buf));
+	if ( NULL == info )
+	{
+		ext_debug("error! : conn->sync_info == NULL in msn_get_list_info");
+		return ;
+	}
 
-  msn_add_callback(conn, msn_syncdata, next_trid, info);
-  next_trid++;
-}
+        if ( !nargs )
+		return ;
 
-void msn_syncdata(msnconn * conn, int trid, char ** args, int numargs, callback_data * data)
-{
-  syncinfo * info=(syncinfo *)data;
-
-  if(!strcmp(args[0], "SYN"))
+        if ( !strcmp( args[ 0 ], "SYN" ) )
   {
-    if(info->serial==atoi(args[2]))
+                if ( info->serial == atoi( args[ 2 ] ) )
     {
       delete info;
-      info=NULL;
-      msn_del_callback(conn, trid);
+                        info = NULL;
       ext_got_info(conn, NULL);
       return;
-    } else {
-      info->serial=atoi(args[2]);
-      ext_latest_serial(conn, info->serial);
-      msn_add_callback(conn, msn_phonedata, info->serial, info);
     }
+
+                info->serial = atoi( args[ 2 ] );
+                ext_latest_serial( conn, info->serial );
+                info->nContacts = atoi( args[ 3 ] );
+                info->nGroups = atoi( args[ 4 ] );
+		return ;
   }
 
-  if(!strcmp(args[0], "LST"))
-  {
-    if(!strcmp(args[2], "FL"))
-    {
-      if(!strcmp(args[5], "0"))
+        if ( !strcmp( args[ 0 ], "GTC" ) )
       {
-	info->fl=NULL; info->complete|=LST_FL;
-      } else {
-	userdata * newuser=new userdata();
-	newuser->username=msn_permstring(args[6]);
-	newuser->friendlyname=msn_decode_URL(msn_permstring(args[6]));
-	msn_add_to_llist(info->fl, newuser);
-	if(atoi(args[4])==atoi(args[5]))
-	{ info->complete|=LST_FL; }
-      }
+                info->gtc = args[ 1 ][ 0 ];
+                info->complete |= COMPLETE_GTC;
+                ext_got_GTC( conn, args[ 1 ][ 0 ] );
     }
-    if(!strcmp(args[2], "RL"))
-    {
-      if(!strcmp(args[5], "0"))
+
+        if ( !strcmp( args[ 0 ], "BLP" ) )
       {
-	info->rl=NULL; info->complete|=LST_RL; // no mates! :-)
-      } else {
-	userdata * newuser=new userdata();
-	newuser->username=msn_permstring(args[6]);
-	newuser->friendlyname=msn_decode_URL(msn_permstring(args[6]));
-	msn_add_to_llist(info->rl, newuser);
-	if(atoi(args[4])==atoi(args[5]))
-	{ info->complete|=LST_RL; }
+                info->blp = args[ 1 ][0];
+                info->complete |= COMPLETE_BLP;
+                ext_got_BLP( conn, args[ 1 ][ 0 ] );
       }
+
+        if ( !strcmp( args[ 0 ], "PRP" ) )
+        {
+                // We just eat PRP-codes.
+		return ;
     }
-    if(!strcmp(args[2], "AL"))
+
+        if ( !strcmp( args[ 0 ], "LSG" ) )
     {
-      if(!strcmp(args[5], "0"))
+                if ( !info->nContacts )
       {
-	info->al=NULL; info->complete|=LST_AL;
-      } else {
-	userdata * newuser=new userdata();
-	newuser->username=msn_permstring(args[6]);
-	newuser->friendlyname=msn_decode_URL(msn_permstring(args[6]));
-	msn_add_to_llist(info->al, newuser);
-	if(atoi(args[4])==atoi(args[5]))
-	{ info->complete|=LST_AL; }
+                        msn_check_rl(conn, info);
+                        ext_got_info(conn, info);
+                        delete info;
+                        conn->sync = 0;
       }
+
+                // Just eat 'm.
+		return ;
     }
-    if(!strcmp(args[2], "BL"))
-    {
-      if(!strcmp(args[5], "0"))
+
+        if ( !strcmp( args[ 0 ], "BPR" ) )
       {
-	info->bl=NULL; info->complete|=LST_BL;
+        	if ( !info->nFound ) {
+       			ext_debug("MSNp8: error: got BPR without contact");
       } else {
-	userdata * newuser=new userdata();
-	newuser->username=msn_permstring(args[6]);
-	newuser->friendlyname=msn_decode_URL(msn_permstring(args[6]));
-	msn_add_to_llist(info->bl, newuser);
-	if(atoi(args[4])==atoi(args[5]))
-	{ info->complete|=LST_BL; }
+        		llist *ll = info->fl;
+
+			while( ll ) {
+				userdata * ud = (userdata *) ll->data;
+				
+				if( !strcmp( ud->username, info->last_user_handled ) )
+				{
+					phonedata * newphone=new phonedata();
+					newphone->title=msn_permstring(args[1]);
+					newphone->number=msn_decode_URL(msn_permstring(args[2]));
+					msn_add_to_llist( ud->phone, newphone );
+					break;
       }
+				
+				ll = ll->next;
     }
   }
 
-  if(!strcmp(args[0], "GTC"))
-  {
-    info->gtc=args[3][0];
-    info->complete|=COMPLETE_GTC;
-    ext_got_GTC(conn, args[3][0]);
+		return ;
   }
 
-  if(!strcmp(args[0], "BLP"))
+        //  0         1                  2
+        // LST email@address.com Friendly%20Nickname w x,y,z
+        if ( !strcmp( args[ 0 ], "LST" ) )
   {
-    info->blp=args[3][0];
-    info->complete|=COMPLETE_BLP;
-    ext_got_BLP(conn, args[3][0]);
-  }
+                // XXX - Todo: see if the user is really on our FL
+                //             list and handle the BL list.
+
+                userdata *newuser_fl = new userdata();
+                newuser_fl->username = msn_permstring( args[ 1 ] );
+                newuser_fl->friendlyname = msn_decode_URL( msn_permstring( args[ 1 ] ) );
+                                  
+               	info->last_user_handled = newuser_fl->username;
+ 
+                msn_add_to_llist( info->fl, newuser_fl );
+
+                userdata *newuser_rl = new userdata();
+                newuser_rl->username = msn_permstring( args[ 1 ] );
+                newuser_rl->friendlyname = msn_decode_URL( msn_permstring( args[ 1 ] ) );
+
+                msn_add_to_llist( info->rl, newuser_rl );
 
-  if(info->complete == (LST_FL|LST_RL|LST_AL|LST_BL|COMPLETE_BLP|COMPLETE_GTC))
+                userdata *newuser_al = new userdata();
+                newuser_al->username = msn_permstring( args[ 1 ] );
+                newuser_al->friendlyname = msn_decode_URL( msn_permstring( args[ 1 ] ) );
+
+                msn_add_to_llist( info->al, newuser_al );                        
+
+                info->nFound++;
+                
+                if ( info->nFound == info->nContacts )
   {
-    msn_del_callback(conn, trid);
-    msn_del_callback(conn, info->serial);
     msn_check_rl(conn, info);
     ext_got_info(conn, info);
     delete info;
+			conn->sync = 0;
+                }
   }
 }
 
-void msn_phonedata(msnconn * conn, int trid, char ** args, int numargs, callback_data * data)
+void msn_sync_lists(msnconn * conn, int version)
 {
-  syncinfo * info=(syncinfo *)data;
+  syncinfo * info=new syncinfo;
 
-  if(!strcmp(args[0], "BPR"))
-  {
-    llist * ll = info->fl;
-    while(ll) {
-      userdata * ud = (userdata *) ll->data;
-      if(!strcmp(ud->username, args[2]))
-      {
-	phonedata * newphone=new phonedata();
-	newphone->title=msn_permstring(args[3]);
-	newphone->number=msn_decode_URL(msn_permstring(args[4]));
-	msn_add_to_llist(ud->phone, newphone);
-	break;
-      }
-      ll = ll->next;
-    }
-  }
+  info->serial=version;
+
+  sprintf(buf, "SYN %d %d\r\n", next_trid, version);
+  write(conn->sock, buf, strlen(buf));
+
+  conn->sync = 1;
+  conn->sync_info = info;
+
+  next_trid++;
 }
 
 void msn_check_rl(msnconn * conn, syncinfo * info)
@@ -544,6 +551,11 @@
   if(!readable) { return; }
 
   args=msn_read_line(sock, &numargs);
+  if ( !numargs )
+  {
+  	ext_debug("msn: error: no arguments for this data");
+	return ;
+  }
 
   if(args==NULL)
   {
@@ -582,6 +594,22 @@
 
   trid=atoi(args[1]);
 
+  if ( conn->sync )
+  {
+	// connection is synching. is this a SYNC-relation instruction?
+	if ( !strcmp( args[ 0 ], "SYN" ) || !strcmp( args[ 0 ], "GTC") || !strcmp( args[ 0 ], "BLP" ) ||
+	     !strcmp( args[ 0 ], "PRP" ) || !strcmp( args[ 0 ], "LSG") || !strcmp( args[ 0 ], "BPR" ) ||
+	     !strcmp( args[ 0 ], "LST" ) )
+	{
+		msn_get_list_info( conn, numargs, args );
+		delete args[0];
+		delete args;
+		return ;
+	}  
+
+	// else: it's a normal message
+  } 
+
   list=conn->callbacks;
 
   if(list!=NULL && trid>0)
@@ -775,6 +803,10 @@
   #endif
   if((tmp=strstr(content, "; charset"))!=NULL) { *tmp='\0'; }
 
+  if(!strcmp(content, "text/x-msmsgsprofile"))
+  {
+    ext_debug("MSNp8: got x-msmsgsprofile");
+  } else
   if(!strcmp(content, "text/plain"))
   {
     message * msg=new message;
@@ -1024,7 +1056,6 @@
   write(conn->sock, "VER MSNFTP\r\n", strlen("VER MSNFTP\r\n"));
 }
 
-
 void msn_handle_filetrans_incoming(msnconn * conn, int readable, int writable)
 {
   authdata_FTP * auth=(authdata_FTP *)conn->auth;
@@ -1445,10 +1476,12 @@
 
   md5_init(&state);
   md5_append(&state, (md5_byte_t *)(args[2]), strlen(args[2]));
-  md5_append(&state, (md5_byte_t *)"Q1P7W2E4J9R8U3S5", 16);
+  md5_append(&state, (md5_byte_t *)"VT6PX?UQTM4WM%YR", 16);
+
   md5_finish(&state, digest);
 
-  sprintf(buf, "QRY %d msmsgs@msnmsgr.com 32\r\n", next_trid++);
+  sprintf(buf, "QRY %d PROD0038W!61ZTF9 32\r\n", next_trid++ );
+
   write(conn->sock, buf, strlen(buf));
 
   for(a=0; a<16; a++)
@@ -1591,8 +1624,426 @@
   return inv;
 }
 
+#define szUser          info->username
+#define szPassword      info->password
+
+int msn_login_read( int nSock, char *buf, int nMax )
+{
+        return cw_read( nSock, buf, nMax, 0 );
+}
+
+int msn_login_wait( int nSocket, char *szCommand )
+{
+	int nRet = 0;
+	
+	while ( !nRet )
+		nRet = read( nSocket, szCommand, 1000 );
+	
+	#ifdef MSNDEBUG
+	printf("<< %s", szCommand );
+	#endif
+	
+	return 1;
+}
+
+void msn_login_write1( int nSocket, char *szString, char *szArg )
+{
+	char szWrite[ 1000 ];
+
+	// ext_debug( szString );
+	// ext_debug( szArg );
+
+	memset( szWrite, 0, 999 );
+	sprintf( szWrite, "%s %s\r\n", szString, szArg );
+	
+	// ext_debug( szWrite );
+
+	cw_write( nSocket, szWrite, strlen( szWrite ), 0 );
+}
+
+void msn_login_write( int nSocket, char *szString )
+{
+	char szWrite[ 1000 ];
+
+	memset( szWrite, 0, 1000 );
+	sprintf( szWrite, "%s\r\n", szString );
+	
+	cw_write( nSocket, szWrite, strlen( szWrite ), 0 );
+} 
+
+int msn_login_connect( int nPort, char *szAddress )
+{
+	return ext_connect_socket( szAddress, nPort );
+}
+
+int msn_login_ssl_write( int nSock, char *str )
+{
+        return cw_write( nSock, str, strlen( str ), 1 );
+}
+
+int msn_login_ssl_read( int nSock, char *buf, int nMax )
+{
+        return cw_read( nSock, buf, nMax, 1 );
+}
+
+int msn_login_close( int nSock )
+{
+        return cw_close( nSock );
+}
+
+int msn_login_ssl_connect( int nPort, char *szAddr )
+{
+	return ext_connect_socket_ssl( szAddr, nPort );
+}
+
+int msn_login_get_server( char *str, char *filter, char *Server, char *Site )
+{
+        char *c, *c1, *c2;
+
+        c = strstr( str, filter );
+        if ( NULL == c )
+             return 0;
+        // Skip the "Filter="-part.
+        c++;
+        c += strlen( filter );
+        c1 = strchr( c, '/' );
+        if ( NULL == c1 )
+             return 0;
+        c2 = strchr( c1, ',' );
+        if ( NULL == c2 )
+             return 0;
+
+        strncpy( Server, c, (unsigned long)c1 - (unsigned long)c );
+        strncpy( Site, c1, (unsigned long)c2 - (unsigned long)c1 );
+
+        return 1;
+}
+
+int msnAuth( char *lc, char *ticket, char *user, char *password )
+{
+        int     nexus;                  // Passport Login Nexus
+        int     logins;			// Login Server
+        char    result[ 5000 ];
+	char    result2[ 1000 ];
+        char    Server[ 100 ];		// e.g. www.server.com
+        char    Site[ 100 ];		// e.g. /site.html
+        char    String[ 800 ];
+        int     i;
+        char    mail[ 255 ];
+        char    name[ 255 ];
+
+        memset( mail, 0, 255 );
+        memset( name, 0, 255 );
+
+        for ( i = 0; i < strlen( user ); i++ )
+        {
+                if ( user[i] == '@' )
+                {
+                        strncpy( name, user, i );
+                        strcpy( mail, (char*)( (unsigned long)user + i + 1 ) );
+                        break;
+                }
+        }        
+
+        memset( Server, 0, 100 );
+        memset( Site, 0, 100 );
+
+        nexus = msn_login_ssl_connect( 443, "nexus.passport.com" );
+        msn_login_ssl_write( nexus, "GET /rdr/pprdr.asp HTTP/1.0\r\n\r\n" );
+        msn_login_ssl_read( nexus, result, 800 );
+        msn_login_close( nexus );
+        msn_login_get_server( result, "DALogin", Server, Site );
+
+        #ifdef MSNDEBUG
+        printf("Connecting to server '%s' .. site '%s'\n", Server, Site );
+        #endif
+
+	for ( ; ; )
+	{
+	        // Connect to Login Server
+	        logins = msn_login_ssl_connect( 443, Server );
+	        memset( String, 0, 800 );
+	        sprintf( String, "GET %s HTTP/1.1\r\n"
+	        		 "Authorization: Passport1.4 OrgVerb=GET,OrgURL=http%%3A%%2F%%2Fmessenger%%2Emsn%%2Ecom,sign-in=%s%%40%s,pwd=%s,%s\r\n"
+	     	  		 "Host: %s\r\n\r\n", 
+	        		 Site, name, mail, password, lc, Server );
+	
+	        #ifdef MSNDEBUG
+		printf("Writing: \n%s\n", String );
+	        #endif
+	
+		msn_login_ssl_write( logins, String );
+	
+		memset( result, 0, 5000 );
+		memset( result2, 0, 1000 );
+		
+		msn_login_ssl_read( logins, result, 5000 );
+		msn_login_ssl_read( logins, result2, 1000 );
+	
+		strcat( result, result2 );
+	
+	        if ( strstr( result, "200 OK" ) )
+	        {
+	        	char *tick;
+	        	char *c3, *c4;
+	        	// Okay.
+	        	
+	        	tick = strstr( result, "t=" );
+	        	if ( NULL == tick )
+	        	{
+	                        #ifdef MSNDEBUG
+	        		printf("No t= found in response.\n");
+	                        #endif
+	        		return 0;
+	        	}
+	        
+	        	tick += 2;
+	        	
+	        	c4 = strstr( tick, "," );
+	
+			strncpy( ticket, tick, (unsigned long)c4 - (unsigned long)tick - 1 );        	
+	
+			//msn_login_close( logins );
+	        	return 1;
+	        }
+	        
+	        if ( strstr( result, "302 Found") && strstr( result, "redir" ) && strstr( result, "Location: " ) )
+	        {
+	        	// Redirection.
+	        	char *c3, *c4;
+	        	        	
+	        	c3 = strstr( result, "Location: " );
+	        	c3 += 10;
+	
+			c3 = strstr( c3, "https://" );
+			c3 += 8;
+			
+			c4 = strstr( c3, "/" );
+			strncpy( Server, c3, (unsigned long)c4 - (unsigned long)c3 );
+			strncpy( Site, c4, (unsigned long)strchr( c4, '\r' ) - (unsigned long)c4 );
+		
+			// printf("Redirection to server [%s] - Site [%s]\n", Server, Site );
+			msn_login_close( logins );
+			continue;
+	        }
+	        
+	        break;
+	}	      
+        
+        // printf("Error\n");
+        return 0;
+}
+
+int msn_connect_v8_error( connectinfo *info, msnconn *conn, char *szErr )
+{
+        ext_show_error( NULL, szErr );
+        delete info;
+
+        if ( conn->sock != -1 )
+        {
+                ext_unregister_sock( conn->sock );
+                close( conn->sock );
+                conn->sock = -1;
+        }
+
+        return -1;
+}
+
+int msn_connect_v8( connectinfo *info, msnconn *conn, int *nNextTrid )
+{
+	int             ds;               // Dispatch Server
+	char            result[ 1000 ];
+	char            *c;
+	char            szIp[ 20 ];
+	char            szPort[ 20 ];
+	int             nPort;
+	char   		lc[ 400 ];
+ 	char   		ticket[ 2000 ];
+	
+	memset( result, 0, 500 );
+	
+  	ext_debug("MSNp8: finding login server");
+	
+	// ds = msn_login_connect( 1863, "messenger.hotmail.com" );
+        ds = conn->sock;
+
+	// >> VER 1 MSNP8 CVR0\r\n
+	msn_login_write( ds, "VER 1 MSNP8 CVR0" );
+	msn_login_wait( ds, result );
+        
+	if ( !strstr( result, "VER 1" ) )
+                return msn_connect_v8_error( info, conn, "Protocol error (didn't receive VER 1)" );
+	
+	// >> CVR 2 0x0409 win 4.10 i386 MSNMSGR 5.0.0544 MSMSGS something@something.com\r\n
+	// ext_debug( szUser );
+
+	msn_login_write1( ds, "CVR 2 0x0409 winnt 5.1 i386 MSNMSGR  5.0.0540 MSMSGS", szUser );
+
+	msn_login_wait( ds, result );
+        
+	if ( !strstr( result, "CVR 2" ) )
+                return msn_connect_v8_error( info, conn, "Protocol error (didn't receive CVR 2)" );
+
+	// >> USR 3 TWN I something@something.com\r\n
+	msn_login_write1( ds, "USR 3 TWN I", szUser );
+	msn_login_wait( ds, result );
+	if ( !strstr( result, "XFR 3 NS " ) )
+                return msn_connect_v8_error( info, conn, "Protocol error (didn't receive XFR 3)" );
+
+        // Read MSN Server IP from message.
+	c = strstr( result, "NS ");
+	c += 3;
+	memset( szIp, 0, 20 );
+	memset( szPort, 0, 20 );
+	strncpy( szIp, c, (unsigned long)strchr( c, ':' ) - (unsigned long)c );
+	c = strchr( c, ':' ); c++;
+	strncpy( szPort, c, (unsigned long)strchr( c, ' ' ) - (unsigned long)c );
+	nPort = atoi( szPort );
+
+        // Close current socket.
+	msn_login_close( ds );
+        ext_unregister_sock( ds );
+        conn->sock = -1;
+
+        #ifdef MSNDEBUG
+	printf("* Connecting to IP `%s' port %d *\n", szIp, nPort );
+        #endif
+
+  	ext_debug("MSNp8: found.. connecting");
+
+        // Try to connect to other server.
+	ds = msn_login_connect( nPort, szIp );
+	if ( ds <= 0 )
+                return msn_connect_v8_error( info, conn, "Error connecting to specified MSN Server" );
+
+        // OK. Register the socket.
+        conn->sock = ds;
+        ext_register_sock( ds, 1, 0 );
+
+	// >> VER 4 MSNP8 CVR0\r\n
+	msn_login_write( ds, "VER 4 MSNP8 CVR0" );
+	msn_login_wait( ds, result );
+        
+	if ( !strstr( result, "VER 4" ) )
+                return msn_connect_v8_error( info, conn, "Protocol error (didn't receive VER 4)" );
+	
+	// >> CVR 5 0x0409 win 4.10 i386 MSNMSGR 5.0.0544 MSMSGS something@something.com\r\n
+        msn_login_write1( ds, "CVR 5 0x0409 winnt 5.1 i386 MSNMSGR  5.0.0540 MSMSGS", szUser );
+	msn_login_wait( ds, result );
+        
+	if ( !strstr( result, "CVR 5" ) )
+                return msn_connect_v8_error( info, conn, "Protocol error (didn't receive CVR 5)" );
+
+	// >> USR 6 TWN I something@something.com\r\n
+	msn_login_write1( ds, "USR 6 TWN I", szUser );
+	msn_login_wait( ds, result );
+	
+	// << USR 6 TWN S something@something.com lc=....,....=...\r\n
+	if ( !strstr( result, "TWN S" ) )
+                return msn_connect_v8_error( info, conn, "Protocol error (didn't receive TWS S)" );
+
+	memset( lc, 0, 400 );
+	c = strstr( result, "TWN S " );
+	c+=6;
+
+	strncpy( lc, c, (unsigned long)strchr(c, '\r')  - (unsigned long)c );
+
+        #ifdef MSNDEBUG
+	printf("LC-etc string = `%s'\n", lc );
+        #endif
+
+	memset( ticket, 0, 2000 );
+	
+  	ext_debug("MSNp8: doing SSL auth");
+	
+	if ( ! msnAuth( lc, ticket, szUser, szPassword ) )
+	{
+	        // printf("Error #6\n");
+                return 0;
+	}
+
+  	ext_debug("MSNp8: OK.. logging in");
+
+        #ifdef MSNDEBUG
+	printf("Ticket = `%s'\n", ticket );
+        #endif
+	
+	memset( result, 0, 500 );
+	sprintf( result, "USR 7 TWN S t=%s", ticket );
+
+        // >> USR 7 TWN S t=<ticket>
+	msn_login_write( ds, result );
+	memset( result, 0, 500 );
+	msn_login_wait( ds, result );
+        
+	if ( !strstr( result, "USR 7 OK") )
+	{
+                if ( result[ 0 ] >= '0' && result[ 0 ] <= '9' )
+                {
+                        char *err;
+                        int  nCode = 0;
+                        // We received an error code.
+
+                        err = strchr( result, ' ' );
+                        if ( NULL == err )
+                                nCode = atoi( result );
+                        else {
+                                *err = '\0';
+                                nCode = atoi( result );
+                        }
+                        if ( nCode <= 0 )
+                           return msn_connect_v8_error( info, conn, "Protocol error (Invalid response after USR 7)" );
+                        return nCode;
+                }
+                
+                // Invalid response.
+                return msn_connect_v8_error( info, conn, "Protocol error (Invalid response after USR 7)" );
+	}
+
+        // We are now connected to the MSN Server
+        
+	// msn_login_write( ds, "OUT" );
+	// msn_login_close( ds );
+
+        // << USR 7 OK something@something.com Something%20Friendly%Nick 1 0
+        {
+                char *szFriendly;
+                char *cEnd;
+                int  i;
+
+                szFriendly = result;
+                
+                for ( i = 0; i < 4; i++ )
+                {
+                        szFriendly = strchr( szFriendly, ' ' );
+
+                        if ( NULL == szFriendly )
+                        {
+                                ext_got_friendlyname( conn, "Unknown nickname" );
+                                return 0;
+                        }
+                        
+                        szFriendly++;
+                }
+
+                cEnd = strchr( szFriendly, ' ');
+                if ( NULL != cEnd )
+                     *cEnd = '\0';
+
+		// ext_debug( msn_decode_URL( szFriendly ) );
+                ext_got_friendlyname( conn, msn_decode_URL( szFriendly ) );
+        }
+
+        *nNextTrid = 8;
+        
+        // No error.
+	return 0;
+}
+
 void msn_connect(msnconn * conn, const char * server, int port)
 {
+  int result;
+  
   conn->ready=0;
 
   if(conn->type==CONN_SB)
@@ -1645,106 +2096,37 @@
 
   ext_register_sock(conn->sock, 1, 0);
 
-  #ifdef MSNDEBUG
-  printf("Connected\n"); // DEBUG
-  #endif
-
-  sprintf(buf, "VER %d MSNP7\r\n", next_trid);
-  write(conn->sock, buf, strlen(buf));
-  msn_add_callback(conn, msn_connect_2, next_trid, (callback_data *)info);
-  next_trid++;
-}
-
-// Further connection functions:
+  // Okay, now try to connect.
 
-void msn_connect_2(msnconn * conn, int trid, char ** args, int numargs, callback_data * data)
-{
-  connectinfo * info;
+  ext_debug("MSNp8: connecting to MSN.. this could take a few seconds");
 
-  info=(connectinfo *)data;
-  msn_del_callback(conn, trid);
+  result = msn_connect_v8( info, conn, &next_trid );
 
-  if(strcmp(args[0], "VER") || strcmp(args[2], "MSNP7")) // if either *differs*...
+  if ( 0 != result )
   {
-    ext_show_error(NULL, "Protocol negotiation failed");
-    delete info;
-    ext_unregister_sock(conn->sock);
-    close(conn->sock);
-    conn->sock=-1;
-    return;
-  }
-
-  sprintf(buf, "USR %d MD5 I %s\r\n", next_trid, info->username);
-  write(conn->sock, buf, strlen(buf));
-
-  msn_add_callback(conn, msn_connect_3, next_trid, data);
-  next_trid++;
-}
-
-void msn_connect_3(msnconn * conn, int trid, char ** args, int numargs, callback_data * data)
-{
-  connectinfo * info;
-
-  md5_state_t state;
-  md5_byte_t digest[16];
-  int a;
-
-  info=(connectinfo *)data;
-  msn_del_callback(conn, trid);
+        // Error code.
 
-  if(isdigit(args[0][0]))
+        if ( result > 0 )
   {
-    msn_show_verbose_error(conn, atoi(args[0]));
-    msn_clean_up(conn);
+                msn_show_verbose_error( conn, result );
     delete info;
-    return;
-  }
+                msn_clean_up( conn );
+                conn->sock = -1;
 
-  // OK, the challenge just arrived as args[4]
+        } // else: connection failed completely. msn_connect_v8 already took care of destroying the connection
 
-  md5_init(&state);
-  md5_append(&state, (md5_byte_t *)(args[4]), strlen(args[4]));
-  md5_append(&state, (md5_byte_t *)(info->password), strlen(info->password));
-  md5_finish(&state, digest);
-
-  sprintf(buf, "USR %d MD5 S ", next_trid);
-  write(conn->sock, buf, strlen(buf));
-
-  for(a=0; a<16; a++)
-  {
-    sprintf(buf, "%02x", digest[a]);
-    write(conn->sock, buf, 2);
   }
-
-  write(conn->sock, "\r\n", 2);
-
-  msn_add_callback(conn, msn_connect_4, next_trid, data);
-  next_trid++;
-}
-
-void msn_connect_4(msnconn * conn, int trid, char ** args, int numargs, callback_data * data)
-{
-  connectinfo * info;
-
-  info=(connectinfo *)data;
-  msn_del_callback(conn, trid);
-
-  if(isdigit(args[0][0]))
+        else
   {
-    msn_show_verbose_error(conn, atoi(args[0]));
-    delete info;
-    msn_clean_up(conn);
-    return;
-  }
-
-  ext_got_friendlyname(conn, msn_decode_URL(args[4]));
 
+        // We received no error code. Everything went ok!
   delete info;
 
-  next_trid++;
+	ext_debug("MSNp8: OK");
 
-  conn->ready=1;
-  ext_new_connection(conn);
+        conn->ready = 1;
+        ext_new_connection( conn );
+  }
 }
 
 void msn_SB_ans(msnconn * conn, int trid, char ** args, int numargs, callback_data * data)
@@ -1774,30 +2156,7 @@
 
 void msn_set_state(msnconn * conn, const char * state)
 {
-  sprintf(buf, "CHG %d %s\r\n", next_trid, state);
+  sprintf(buf, "CHG %d %s %d\r\n", next_trid, state, MSN_VERSION_ID );
   write(conn->sock, buf, strlen(buf));
   next_trid++;
 }
-
-/*
-void msn_connect_3(msnconn * conn, char ** args, int numargs, callback_data * data)
-{
-  connectinfo * info;
-
-  info=(connectinfo *)data;
-  msn_del_callback(conn, trid);
-  trid++;
-
-  if(isdigit(args[0][0]))
-  {
-    msn_print_verbose_error(conn, atoi(args[0]));
-    delete info;
-    return;
-  }
-
-  sprintf(buf, "INF %d\r\n", trid, info->username);
-  write(conn.sock, buf, strlen(buf));
-
-  msn_add_callback(conn, msn_connect_4, trid, data);
-}
-*/

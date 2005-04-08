--- src/screem-application.c.orig	Fri Apr  8 01:54:41 2005
+++ src/screem-application.c	Fri Apr  8 02:15:23 2005
@@ -383,7 +383,7 @@ void screem_application_startup( ScreemA
 	if( conn ) {
 		dbus_connection_setup_with_g_main( conn, NULL );
 
-		if( dbus_bus_service_exists( conn, "org.screem", 
+		if( dbus_bus_name_has_owner( conn, "org.screem", 
 					&error ) ) {
 			message = dbus_message_new_method_call(
 					"org.screem",
@@ -392,9 +392,10 @@ void screem_application_startup( ScreemA
 					"Open" );
 			if( start_files ) {
 				while( *start_files ) {
-					dbus_message_append_iter_init( message,
+					dbus_message_iter_init_append( message,
 							&it );
-					dbus_message_iter_append_string( &it,
+					dbus_message_iter_append_basic( &it,
+							DBUS_TYPE_STRING,
 							*start_files );
 					start_files ++;
 				}
@@ -407,7 +408,7 @@ void screem_application_startup( ScreemA
 			return;
 
 		} else {
-			if( dbus_bus_acquire_service( conn, "org.screem",
+			if( dbus_bus_request_name( conn, "org.screem",
 				0, &error ) != -1 ) {
 				/* acquired, listen in for 
 				 * org.screem stuff */
@@ -1522,7 +1523,8 @@ static DBusHandlerResult screem_applicat
 		dbus_message_iter_init( message, &it );
 		
 		add = ( ! priv->start_files ); 
-		while( ( uri = dbus_message_iter_get_string( &it ) ) ) {
+		while( dbus_message_iter_get_arg_type( &it ) == DBUS_TYPE_STRING ) {
+			dbus_message_iter_get_basic( &it, &uri );
 			priv->start_files = g_slist_prepend( priv->start_files, uri );	
 			if( ! dbus_message_iter_next( &it ) ) {
 				break;

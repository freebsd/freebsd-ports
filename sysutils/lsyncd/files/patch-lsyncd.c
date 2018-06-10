--- lsyncd.c.orig	2018-03-09 12:39:11 UTC
+++ lsyncd.c
@@ -1614,10 +1614,21 @@ l_configure( lua_State *L )
 			openlog( log_ident, 0, settings.log_facility );
 		}
 
+#ifdef __FreeBSD__
+		if( !settings.nodaemon )
+		{
+			// daemonnize is already done before open_inotify with FreeBSD.
+			// just writing pidfile is needed at this time.
+			logstring( "Normal", "--- Startup, daemonizing ---" );
+			if (settings.pidfile)
+                        {
+                                write_pidfile( L, settings.pidfile );
+                        }
+		}
+#endif
 		if( !settings.nodaemon && !is_daemon )
 		{
 			logstring( "Normal", "--- Startup, daemonizing ---" );
-
 			daemonize( L, settings.pidfile );
 		}
 		else
@@ -2433,6 +2444,10 @@ main1( int argc, char *argv[] )
 
 	int argp = 1;
 
+#ifdef __FreeBSD__
+	static bool call_daemonize = true;
+#endif
+
 	// load Lua
 	L = luaL_newstate( );
 
@@ -2482,6 +2497,14 @@ main1( int argc, char *argv[] )
 
 		while( i < argc )
 		{
+#ifdef __FreeBSD__
+			if (!strcmp (argv[i], "-nodaemon" ))
+			{
+				call_daemonize = false;
+				i++;
+				continue;
+			}
+#endif
 			if(
 				strcmp( argv[ i ], "-log"  ) &&
 				strcmp( argv[ i ], "--log" )
@@ -2796,6 +2819,14 @@ main1( int argc, char *argv[] )
 		}
 	}
 
+#ifdef __FreeBSD__
+	// daemonize should be done before open_inofity with FreeBSD.
+ 	if( call_daemonize )
+	{
+		daemonize( L, NULL );
+	}
+#endif
+
 #ifdef WITH_INOTIFY
 	open_inotify( L );
 #endif

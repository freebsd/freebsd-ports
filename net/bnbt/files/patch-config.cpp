--- config.cpp	Fri Sep 24 20:01:58 2004
+++ config.cpp.new	Sat Oct 23 14:42:45 2004
@@ -147,10 +147,10 @@
 		CFG_SetString( "bnbt_realm", "BNBT" );
 
 	if( CFG_GetString( "bnbt_error_log_dir", string( ) ).empty( ) )
-		CFG_SetString( "bnbt_error_log_dir", string( ) );
+		CFG_SetString( "bnbt_error_log_dir", "/var/log/bnbt/" );
 
 	if( CFG_GetString( "bnbt_access_log_dir", string( ) ).empty( ) )
-		CFG_SetString( "bnbt_access_log_dir", string( ) );
+		CFG_SetString( "bnbt_access_log_dir", "/var/log/bnbt/" );
 
 	if( CFG_GetInt( "bnbt_flush_interval", 0 ) < 1 )
 		CFG_SetInt( "bnbt_flush_interval", 100 );

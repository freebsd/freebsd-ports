--- libtransmission/platform.c.orig	2009-06-19 10:53:49.000000000 -0500
+++ libtransmission/platform.c	2009-06-19 10:55:52.000000000 -0500
@@ -232,22 +232,17 @@
 
     if( !home )
     {
-        home = tr_strdup( getenv( "HOME" ) );
-
-        if( !home )
-        {
 #ifdef WIN32
-            char appdata[MAX_PATH]; /* SHGetFolderPath() requires MAX_PATH */
-            *appdata = '\0';
-            SHGetFolderPath( NULL, CSIDL_PERSONAL, NULL, 0, appdata );
-            home = tr_strdup( appdata );
+        char appdata[MAX_PATH]; /* SHGetFolderPath() requires MAX_PATH */
+        *appdata = '\0';
+        SHGetFolderPath( NULL, CSIDL_PERSONAL, NULL, 0, appdata );
+        home = tr_strdup( appdata );
 #else
-            struct passwd * pw = getpwuid( getuid( ) );
-            if( pw )
-                home = tr_strdup( pw->pw_dir );
-            endpwent( );
+        struct passwd * pw = getpwuid( getuid( ) );
+        if( pw )
+            home = tr_strdup( pw->pw_dir );
+        endpwent( );
 #endif
-        }
 
         if( !home )
             home = tr_strdup( "" );

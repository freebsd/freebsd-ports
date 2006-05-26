--- scan/sane/io.c.orig	Tue May 23 15:15:04 2006
+++ scan/sane/io.c	Tue May 23 15:17:40 2006
@@ -210,6 +210,13 @@
 {
     char message[ BUFFER_SIZE ];
     MsgAttributes ma;
+    int remaining;
+    char *p;
+    int state = 0;
+    int d = 0;
+    char * uri = NULL; 
+    char * mdl = NULL;      
+
 
     int len = sprintf( message, "msg=ProbeDevicesFiltered\nbus=%s\nfilter=scan\nformat=default\n", 
         "usb,cups,par" );
@@ -228,18 +235,14 @@
 
     hplip_ParseMsg( message, len, &ma );
 
-    int d = 0;
-    char * uri = NULL;
-    char * mdl = NULL;
-    
     if( ma.ndevice > 0 )
     {
         *devices = malloc( sizeof( SANE_Device * ) * ( ma.ndevice + 1 ) );
 
-        int remaining = ma.length;
-        char *p = (char *)ma.data;
+        remaining = ma.length;
+        p = (char *)ma.data;
 
-        int state = 0;
+        state = 0;
 
         while( remaining > 0 && *p != '\0' && d < ma.ndevice )
         {

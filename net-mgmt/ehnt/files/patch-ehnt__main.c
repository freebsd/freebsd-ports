
$FreeBSD$

--- ehnt_main.c.orig	Thu Oct  4 22:18:29 2001
+++ ehnt_main.c	Mon May 24 12:03:14 2004
@@ -228,14 +228,15 @@
     e_dat.recentmin=(int)(ts->tm_min + (ts->tm_hour*60) + (ts->tm_yday * 60 * 24));
   }
 
-  NewStats(e_dat.stats);
-
-  Init_ASN_Lookups();
+  if (e_cfg.mode != EM_COLONDUMP) {
+    NewStats(e_dat.stats);
+    Init_ASN_Lookups();
 
-  /* ehnt_client (in ehnt_client.c) connects to the server, then loops forever, 
-     calling ProcessPacket for each incoming flow. */
-  printf("Using report interval of %d minute(s)\n",e_cfg.si);
-  printf("Starting. Hit '?' for help with keys.\r");
+    /* ehnt_client (in ehnt_client.c) connects to the server, then loops forever, 
+       calling ProcessPacket for each incoming flow. */
+    printf("Using report interval of %d minute(s)\n",e_cfg.si);
+    printf("Starting. Hit '?' for help with keys.\r");
+  }
 
   ehnt_client(e_cfg.servername,e_cfg.serverport,&my_ehnt_struct);
 }

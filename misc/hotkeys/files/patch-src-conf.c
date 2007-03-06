--- src/conf.c.orig	Thu Nov 28 03:30:08 2002
+++ src/conf.c	Fri Mar  2 19:57:12 2007
@@ -31,6 +31,8 @@
 
 #include "conf.h"
 
+#define DB_VERSION (DB_VERSION_MAJOR*100000+DB_VERSION_MINOR*1000+DB_VERSION_PATCH)
+
 char* conf_keys[] = {
 
     /* KEY             DEFAULT VALUE           */
@@ -68,6 +70,9 @@
     "Shopping",        "mozilla -remote 'openURL(http://thinkgeek.com)'",
     "Go",              "mozilla -remote 'openURL(http://linux.com)'",
     "Print",           "lpr",
+    "Messenger",       "gaim",
+    "Webcam",          "\0",
+    "Media",           "xmms",
 /*
     "Screendump",      "xwd -root",
 */
@@ -75,9 +80,14 @@
 //    "osd_font",        "-*-lucidatypewriter-bold-r-normal-*-*-250-*-*-*-*-*-*",
     "osd_font",        "lucidasanstypewriter-bold-24",
     "osd_color",       "LawnGreen",
+    "osd_shadow_color",	"Black",
+    "osd_shadow_offset",	"3",
     "osd_timeout",     "3",
     "osd_position",    "bottom",
-    "osd_offset",      "25",
+    "osd_align",	"center",
+    "osd_hoffset",      "25",
+    "osd_voffset",      "25",
+    "osd_bar_length",	"25",
     NULL,              NULL
 };
 
@@ -242,14 +252,24 @@
     char*   h;
     char    filename[MAXPATHLEN];
 
+    dbp = NULL;
+
     /* Create the hash table */
+#if DB_VERSION >= 300000
     if ( (ret = db_create(&dbp, dbenv, 0)) != 0 )
     {
         uError("Failed in db_create: %d", ret);
         bailout();
     }
+#endif
 
+#if DB_VERSION >= 401025
+    if ( (ret = dbp->open(dbp, NULL, NULL, NULL, DB_HASH, DB_CREATE, 0664)) != 0 )
+#elif DB_VERSION >= 300000
     if ( (ret = dbp->open(dbp, NULL, NULL, DB_HASH, DB_CREATE, 0664)) != 0 )
+#else
+    if ( (ret = dbp->open(NULL, DB_HASH, DB_CREATE, 0644, NULL, NULL, &dbp)) != 0 )
+#endif
     {
         uError("Can't create hash table: %d", ret);
         bailout();

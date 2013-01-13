--- ./libatalk/util/netatalk_conf.c.orig	2013-01-07 12:21:30.309544508 +0000
+++ ./libatalk/util/netatalk_conf.c	2013-01-07 12:23:22.360529479 +0000
@@ -563,7 +563,7 @@
     EC_INIT;
     struct vol  *volume = NULL;
     int         i, suffixlen, vlen, tmpvlen, u8mvlen, macvlen;
-    char        *tmpname;
+    char        tmpname[AFPVOL_U8MNAMELEN+1];
     ucs2_t      u8mtmpname[(AFPVOL_U8MNAMELEN+1)*2], mactmpname[(AFPVOL_MACNAMELEN+1)*2];
     char        suffix[6]; /* max is #FFFF */
     uint16_t    flags;
@@ -643,7 +643,7 @@
     EC_NULL( volume->v_maccodepage = strdup(obj->options.maccodepage) );
 
     vlen = strlen(name);
-    tmpname = strdup(name);
+    strlcpy(tmpname, name, sizeof(tmpname));
     for(i = 0; i < vlen; i++)
         if(tmpname[i] == '/') tmpname[i] = ':';
 

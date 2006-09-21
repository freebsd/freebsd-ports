--- lib/precompiled_sets.c	Sat Jul  9 18:03:15 2005
+++ lib/precompiled_sets.c	Sun Sep 10 03:29:48 2006
@@ -404,7 +404,8 @@
     { CS_charset_magic, &cs_euc,      &map_EUC_ascii,  SET_valid,  "GB2312",  NULL, 
       &set_EUCCN,         2025,  "GB2312-1980" }, /* ASCII + GB 2312-80 */
 
-    { CS_charset_magic, &cs_unknown,  NULL,  SET_valid,  "Big5",  NULL, NULL,           2026,  NULL },
+    { CS_charset_magic, &cs_ascii,    &map_latin1,      SET_valid,  "Big5",   ASCII,
+      &(sets_iso_8859_X[1]),  2026,  "Big5" },
     { CS_charset_magic, &cs_ascii,    NULL,  SET_valid, "windows-1250", ASCII, NULL,     2250,  NULL },
     { CS_charset_magic, &cs_ascii,    NULL,  SET_valid, "windows-1253", ASCII, NULL,     2253,  NULL },
     { CS_charset_magic, &cs_ascii,    NULL,  SET_valid, "windows-1254", ASCII ,NULL,     2254,  NULL },

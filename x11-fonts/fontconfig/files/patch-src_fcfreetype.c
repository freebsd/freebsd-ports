From a61e145304da86c8c35b137493bbd8fd5dd1e7f5 Mon Sep 17 00:00:00 2001
From: Akira TAGOH <akira@tagoh.org>
Date: Mon, 09 Sep 2013 10:59:31 +0000
Subject: Fix memory leaks in FcFreeTypeQueryFace

---
diff --git a/src/fcfreetype.c b/src/fcfreetype.c
index 02e85cb..e394307 100644
--- src/fcfreetype.c
+++ src/fcfreetype.c
@@ -1105,7 +1105,6 @@ FcFreeTypeQueryFace (const FT_Face  face,
     const char	    *tmp;
 
     FcChar8	    *hashstr = NULL;
-    char	    *fontdata = NULL;
     FT_Error	    err;
     FT_ULong	    len = 0, alen;
 
@@ -1668,15 +1667,21 @@ FcFreeTypeQueryFace (const FT_Face  face,
     err = FT_Load_Sfnt_Table (face, 0, 0, NULL, &len);
     if (err == FT_Err_Ok)
     {
+	char *fontdata;
+
 	alen = (len + 63) & ~63;
 	fontdata = malloc (alen);
 	if (!fontdata)
 	    goto bail3;
 	err = FT_Load_Sfnt_Table (face, 0, 0, (FT_Byte *)fontdata, &len);
 	if (err != FT_Err_Ok)
+	{
+	    free (fontdata);
 	    goto bail3;
+	}
 	memset (&fontdata[len], 0, alen - len);
 	hashstr = FcHashGetSHA256DigestFromMemory (fontdata, len);
+	free (fontdata);
     }
     else if (err == FT_Err_Invalid_Face_Handle)
     {
@@ -1692,7 +1697,11 @@ FcFreeTypeQueryFace (const FT_Face  face,
     if (hashstr)
     {
 	if (!FcPatternAddString (pat, FC_HASH, hashstr))
+	{
+	    free (hashstr);
 	    goto bail1;
+	}
+	free (hashstr);
     }
 bail3:
 
@@ -1783,10 +1792,6 @@ bail3:
 bail2:
     FcCharSetDestroy (cs);
 bail1:
-    if (hashstr)
-	free (hashstr);
-    if (fontdata)
-	free (fontdata);
     FcPatternDestroy (pat);
 bail0:
     return NULL;
--
cgit v0.9.0.2-2-gbebe

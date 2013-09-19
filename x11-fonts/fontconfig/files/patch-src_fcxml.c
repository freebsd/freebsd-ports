From 3e5f70a16ac6d54f1e01c92ddaa5985deec1b7f9 Mon Sep 17 00:00:00 2001
From: Akira TAGOH <akira@tagoh.org>
Date: Mon, 02 Sep 2013 11:51:46 +0000
Subject: Do not create a config dir for migration when no config files nor dirs

---
diff --git a/src/fcxml.c b/src/fcxml.c
index b464b4e..8ff10b6 100644
--- src/fcxml.c
+++ src/fcxml.c
@@ -2233,11 +2233,6 @@ FcParseInclude (FcConfigParse *parse)
 	    /* No config dir nor file on the XDG directory spec compliant place
 	     * so need to guess what it is supposed to be.
 	     */
-	    FcChar8 *parent = FcStrDirname (s);
-
-	    if (!FcFileIsDir (parent))
-		FcMakeDirectory (parent);
-	    FcStrFree (parent);
 	    if (FcStrStr (s, (const FcChar8 *)"conf.d") != NULL)
 		goto userdir;
 	    else
@@ -2259,6 +2254,11 @@ FcParseInclude (FcConfigParse *parse)
 	{
 	    if (FcFileIsDir (filename))
 	    {
+		FcChar8 *parent = FcStrDirname (userdir);
+
+		if (!FcFileIsDir (parent))
+		    FcMakeDirectory (parent);
+		FcStrFree (parent);
 		if (FcFileIsDir (userdir) ||
 		    rename ((const char *)filename, (const char *)userdir) != 0 ||
 		    symlink ((const char *)userdir, (const char *)filename) != 0)
@@ -2272,6 +2272,11 @@ FcParseInclude (FcConfigParse *parse)
 	    }
 	    else
 	    {
+		FcChar8 *parent = FcStrDirname (userconf);
+
+		if (!FcFileIsDir (parent))
+		    FcMakeDirectory (parent);
+		FcStrFree (parent);
 		if (FcFileIsFile (userconf) ||
 		    rename ((const char *)filename, (const char *)userconf) != 0 ||
 		    symlink ((const char *)userconf, (const char *)filename) != 0)
--
cgit v0.9.0.2-2-gbebe

--- c/shared/source/uforead/uforead.c.orig	2023-04-24 14:46:56 UTC
+++ c/shared/source/uforead/uforead.c
@@ -1243,7 +1243,7 @@ static void updateGLIFRec(ufoCtx h, char* glyphName, x
     if (fileName == NULL) {
         /* this is basically muted for now, as the previous check will return and skip if not parseable.
            We'll add this back once we add verbosity flag */
-        message(h, ufoErrParse, "Encountered glyph reference %s in alternate layer's contents.plist with an empty file path. ", glyphName);
+        message(h, "Encountered glyph reference %s in alternate layer's contents.plist with an empty file path. ", glyphName);
         return;
     }
 
@@ -2009,7 +2009,7 @@ static long strtolCheck(ufoCtx h, char* keyValue, bool
             fatal(h, ufoErrParse, msg);
         else if (msg)
             message(h, msg);
-        return NULL;
+        return 0;
     }
 }
 
@@ -2024,7 +2024,7 @@ static unsigned long strtoulCheck(ufoCtx h, char* keyV
             fatal(h, ufoErrParse, msg);
         else if (msg)
             message(h, msg);
-        return NULL;
+        return 0;
     }
 }
 

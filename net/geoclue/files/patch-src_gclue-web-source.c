diff --git a/src/gclue-web-source.c b/src/gclue-web-source.c
index cd0ee89..13c50ef 100644
--- src/gclue-web-source.c.orig
+++ src/gclue-web-source.c
@@ -257,7 +257,6 @@ gclue_web_source_start (GClueLocationSource *source)
         if (!base_class->start (source))
                 return FALSE;
 
-        gclue_web_source_refresh (GCLUE_WEB_SOURCE (source));
         return TRUE;
 }
 

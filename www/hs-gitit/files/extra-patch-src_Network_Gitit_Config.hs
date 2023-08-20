--- src/Network/Gitit/Config.hs.orig	2023-07-10 14:38:47 UTC
+++ src/Network/Gitit/Config.hs
@@ -130,7 +130,9 @@ extractConfig cp = do
       cfWikiTitle <- get cp "DEFAULT" "wiki-title"
       cfFeedDays <- get cp "DEFAULT" "feed-days"
       cfFeedRefreshTime <- get cp "DEFAULT" "feed-refresh-time"
+      cfExports <- get cp "DEFAULT" "exports"
       cfPDFExport <- get cp "DEFAULT" "pdf-export"
+      cfPDFEngine <- get cp "DEFAULT" "pdf-engine"
       cfPandocUserData <- get cp "DEFAULT" "pandoc-user-data"
       cfXssSanitize <- get cp "DEFAULT" "xss-sanitize"
       cfRecentActivityDays <- get cp "DEFAULT" "recent-activity-days"
@@ -232,7 +234,9 @@ extractConfig cp = do
         , wikiTitle            = cfWikiTitle
         , feedDays             = readNumber "feed-days" cfFeedDays
         , feedRefreshTime      = readNumber "feed-refresh-time" cfFeedRefreshTime
+        , exports              = cfExports
         , pdfExport            = cfPDFExport
+        , pdfEngine            = cfPDFEngine
         , pandocUserData       = if null cfPandocUserData
                                     then Nothing
                                     else Just cfPandocUserData

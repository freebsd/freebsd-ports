--- src/Network/Gitit/Initialize.hs.orig	2001-09-09 01:46:40 UTC
+++ src/Network/Gitit/Initialize.hs
@@ -123,7 +123,10 @@ createDefaultPages :: Config -> IO ()
 createDefaultPages conf = do
     let fs = filestoreFromConfig conf
         pt = defaultPageType conf
-        toPandoc = readMarkdown def{ readerExtensions = enableExtension Ext_smart (readerExtensions def) }
+        rOpts = def{ readerExtensions = getDefaultExtensions "markdown"
+                                        <> extensionsFromList [Ext_smart]
+                                        <> readerExtensions def }
+        toPandoc = readMarkdown rOpts
         defOpts = def{ writerExtensions = if showLHSBirdTracks conf
                                              then enableExtension
                                                   Ext_literate_haskell

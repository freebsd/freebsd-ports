--- src/Network/Gitit/Export.hs.orig	2023-07-10 14:38:47 UTC
+++ src/Network/Gitit/Export.hs
@@ -61,6 +61,7 @@ respondX :: String -> String -> String
           -> WriterOptions -> String -> Pandoc -> Handler
 respondX templ mimetype ext fn opts page doc = do
   cfg <- getConfig
+  unless (exports cfg) $ error "exports are disabled"
   doc' <- if ext `elem` ["odt","pdf","beamer","epub","docx","rtf"]
              then fixURLs page doc
              else return doc
@@ -169,7 +170,11 @@ respondTexinfo = respondS "texinfo" "application/x-tex
 
 respondDocbook :: String -> Pandoc -> Handler
 respondDocbook = respondS "docbook" "application/docbook+xml" "xml"
+#if MIN_VERSION_pandoc(3,0,0)
+  writeDocBook5 defaultRespOptions
+#else
   writeDocbook5 defaultRespOptions
+#endif
 
 respondOrg :: String -> Pandoc -> Handler
 respondOrg = respondS "org" "text/plain; charset=utf-8" ""
@@ -228,7 +233,7 @@ respondPDF useBeamer page old_pndc = fixURLs page old_
                 setInputFiles [baseUrl cfg]
                 let templ = if useBeamer then "beamer" else "latex"
                 compiledTemplate <- compileDefaultTemplate templ
-                makePDF "pdflatex" [] (if useBeamer then writeBeamer else writeLaTeX)
+                makePDF (pdfEngine cfg) [] (if useBeamer then writeBeamer else writeLaTeX)
                   defaultRespOptions{ writerTemplate = Just compiledTemplate
                                     , writerTableOfContents = toc } pndc
               either (liftIO . throwIO) return res

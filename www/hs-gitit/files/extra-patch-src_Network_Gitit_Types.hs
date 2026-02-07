--- src/Network/Gitit/Types.hs.orig	2023-07-10 14:38:47 UTC
+++ src/Network/Gitit/Types.hs
@@ -204,8 +204,12 @@ data Config = Config {
   feedDays             :: Integer,
   -- | Number of minutes to cache feeds before refreshing
   feedRefreshTime      :: Integer,
+  -- | Allow exports?
+  exports              :: Bool,
   -- | Allow PDF export?
   pdfExport            :: Bool,
+  -- | Which PDF engine to use?
+  pdfEngine            :: String,
   -- | Directory to search for pandoc customizations
   pandocUserData       :: Maybe FilePath,
   -- | Filter HTML through xss-sanitize

--- _cabal_deps/filestore-0.6.5/Data/FileStore/Darcs.hs.orig	2001-09-09 01:46:40 UTC
+++ _cabal_deps/filestore-0.6.5/Data/FileStore/Darcs.hs
@@ -205,7 +205,7 @@ getNames = map (drop 2) . lines . toString
 -- | Get a list of all known files inside and managed by a repository.
 darcsIndex :: FilePath ->IO [FilePath]
 darcsIndex repo = withVerifyDir repo $ do
-  (status, _errOutput, output) <- runDarcsCommand repo "query"  ["files","--no-directories"]
+  (status, _errOutput, output) <- runDarcsCommand repo "show"  ["files","--no-directories"]
   if status == ExitSuccess
      then return . getNames $ output
      else return []   -- return empty list if invalid path (see gitIndex)
@@ -214,8 +214,8 @@ darcsIndex repo = withVerifyDir repo $ do
 darcsDirectory :: FilePath -> FilePath -> IO [Resource]
 darcsDirectory repo dir = withVerifyDir (repo </> dir) $ do
   let dir' = if null dir then "" else addTrailingPathSeparator dir
-  (status1, _errOutput1, output1) <- runDarcsCommand repo "query"  ["files","--no-directories"]
-  (status2, _errOutput2, output2) <- runDarcsCommand repo "query" ["files","--no-files"]
+  (status1, _errOutput1, output1) <- runDarcsCommand repo "show"  ["files","--no-directories"]
+  (status2, _errOutput2, output2) <- runDarcsCommand repo "show" ["files","--no-files"]
   if status1 == ExitSuccess && status2 == ExitSuccess
      then do
        let files = adhocParsing dir' . lines . toString $ output1

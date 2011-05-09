--- ./Setup.hs.orig	2010-07-22 12:13:20.000000000 +0200
+++ ./Setup.hs	2011-03-27 01:53:35.109600797 +0100
@@ -204,7 +204,7 @@
                        else docdir (absoluteInstallDirs pd lbi cd) `joinFileName` "doc"
         let manDir = if isWindows
                        then dataPref `joinFileName` "Documentation"
-                       else datadir (absoluteInstallDirs pd lbi cd) `joinFileName` ".." `joinFileName` "man" `joinFileName` "man1"
+                       else prefix (absoluteInstallDirs pd lbi cd) `joinFileName` "man" `joinFileName` "man1"
         createDirectoryIfMissing True docDir
         copyFileVerbose v (lhs2texDocDir `joinFileName` "Guide2.pdf") (docDir `joinFileName` "Guide2.pdf")
         when (not isWindows) $
@@ -291,9 +291,9 @@
              do  let mProg = lookupProgram (simpleProgram progName) programConf
                  case mProg of
                    Just (ConfiguredProgram { programLocation = UserSpecified p,
-                                             programArgs = args })  -> return (p,args)
+                                             programDefaultArgs = args })  -> return (p,args)
                    Just (ConfiguredProgram { programLocation = FoundOnSystem p,
-                                             programArgs = args })  -> return (p,args)
+                                             programDefaultArgs = args })  -> return (p,args)
                    _ -> (die (progName ++ " command not found"))
 
 -- | Run a command in a specific environment and return the output and errors.

--- ./Setup.hs.orig	2012-05-13 05:04:40.000000000 +0200
+++ ./Setup.hs	2012-05-15 16:22:31.000000000 +0200
@@ -7,7 +7,7 @@
          (LocalBuildInfo(..), absoluteInstallDirs)
 import Distribution.Verbosity ( Verbosity, silent )
 import Distribution.Simple.GHC (ghcPackageDbOptions)
-import Distribution.Simple.InstallDirs (mandir, bindir, CopyDest (NoCopyDest))
+import Distribution.Simple.InstallDirs (prefix, bindir, CopyDest (NoCopyDest))
 import Distribution.Simple.Utils (installOrdinaryFiles)
 import Control.Exception ( bracket_ )
 import Control.Monad ( unless )
@@ -86,7 +86,7 @@
 installManpages :: PackageDescription -> LocalBuildInfo
                 -> Verbosity -> CopyDest -> IO ()
 installManpages pkg lbi verbosity copy =
-  installOrdinaryFiles verbosity (mandir (absoluteInstallDirs pkg lbi copy))
+  installOrdinaryFiles verbosity (prefix (absoluteInstallDirs pkg lbi copy) </> manDir)
              (zip (repeat manDir) manpages)
 
 -- | Returns a list of 'dependencies' that have been modified after 'file'.

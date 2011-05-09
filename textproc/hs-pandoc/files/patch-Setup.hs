--- ./Setup.hs.orig	2011-02-13 18:03:00.000000000 +0100
+++ ./Setup.hs	2011-03-13 01:14:26.580023488 +0100
@@ -6,7 +6,7 @@
 import Distribution.Simple.LocalBuildInfo
          (LocalBuildInfo(..), absoluteInstallDirs)
 import Distribution.Verbosity ( Verbosity, silent )
-import Distribution.Simple.InstallDirs (mandir, bindir, CopyDest (NoCopyDest))
+import Distribution.Simple.InstallDirs (prefix, bindir, CopyDest (NoCopyDest))
 import Distribution.Simple.Utils (copyFiles)
 import Control.Exception ( bracket_ )
 import Control.Monad ( unless )
@@ -85,7 +85,7 @@
 installManpages :: PackageDescription -> LocalBuildInfo
                 -> Verbosity -> CopyDest -> IO ()
 installManpages pkg lbi verbosity copy =
-  copyFiles verbosity (mandir (absoluteInstallDirs pkg lbi copy))
+  copyFiles verbosity (prefix (absoluteInstallDirs pkg lbi copy) </> "man")
              (zip (repeat manDir) manpages)
 
 -- | Returns a list of 'dependencies' that have been modified after 'file'.

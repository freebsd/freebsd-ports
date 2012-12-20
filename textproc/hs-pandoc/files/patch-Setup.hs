--- ./Setup.hs.orig	2012-10-21 23:06:41.000000000 +0200
+++ ./Setup.hs	2012-10-23 18:33:48.000000000 +0200
@@ -6,7 +6,7 @@
 import Distribution.Simple.LocalBuildInfo
          (LocalBuildInfo(..), absoluteInstallDirs)
 import Distribution.Verbosity ( Verbosity, silent )
-import Distribution.Simple.InstallDirs (mandir, CopyDest (NoCopyDest))
+import Distribution.Simple.InstallDirs (prefix, CopyDest (NoCopyDest))
 import Distribution.Simple.Utils (installOrdinaryFiles)
 import Prelude hiding (catch)
 import System.Process ( rawSystem )
@@ -49,5 +49,5 @@
 installManpages :: PackageDescription -> LocalBuildInfo
                 -> Verbosity -> CopyDest -> IO ()
 installManpages pkg lbi verbosity copy =
-  installOrdinaryFiles verbosity (mandir (absoluteInstallDirs pkg lbi copy))
+  installOrdinaryFiles verbosity (prefix (absoluteInstallDirs pkg lbi copy) </> manDir)
              (zip (repeat manDir) manpages)

--- ./Setup.hs.orig	2013-01-29 01:14:38.000000000 +0100
+++ ./Setup.hs	2013-02-17 00:48:54.000000000 +0100
@@ -8,7 +8,7 @@
 import Distribution.Simple.LocalBuildInfo
          (LocalBuildInfo(..), absoluteInstallDirs)
 import Distribution.Verbosity ( Verbosity, silent )
-import Distribution.Simple.InstallDirs (mandir, CopyDest (NoCopyDest))
+import Distribution.Simple.InstallDirs (prefix, CopyDest (NoCopyDest))
 import Distribution.Simple.Utils (installOrdinaryFiles, info)
 import Prelude hiding (catch)
 import System.Process ( rawSystem )
@@ -53,7 +53,7 @@
 installManpages :: PackageDescription -> LocalBuildInfo
                 -> Verbosity -> CopyDest -> IO ()
 installManpages pkg lbi verbosity copy =
-  installOrdinaryFiles verbosity (mandir (absoluteInstallDirs pkg lbi copy))
+  installOrdinaryFiles verbosity (prefix (absoluteInstallDirs pkg lbi copy) </> manDir)
              (zip (repeat manDir) manpages)
 
 ppBlobSuffixHandler :: PPSuffixHandler

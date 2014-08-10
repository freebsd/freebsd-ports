--- ./Setup.hs.orig	2013-12-09 04:22:42.000000000 +0100
+++ ./Setup.hs	2013-12-27 02:49:01.000000000 +0100
@@ -9,7 +9,7 @@
 import Distribution.Simple.LocalBuildInfo
          (LocalBuildInfo(..), absoluteInstallDirs)
 import Distribution.Verbosity ( Verbosity, silent )
-import Distribution.Simple.InstallDirs (mandir, CopyDest (NoCopyDest), toPathTemplate)
+import Distribution.Simple.InstallDirs (prefix, CopyDest (NoCopyDest), toPathTemplate)
 import Distribution.Simple.Utils (installOrdinaryFiles, info)
 import Distribution.Simple.Test (test)
 import Prelude hiding (catch)
@@ -59,7 +59,7 @@
 installManpages :: PackageDescription -> LocalBuildInfo
                 -> Verbosity -> CopyDest -> IO ()
 installManpages pkg lbi verbosity copy =
-  installOrdinaryFiles verbosity (mandir (absoluteInstallDirs pkg lbi copy))
+  installOrdinaryFiles verbosity (prefix (absoluteInstallDirs pkg lbi copy) </> manDir)
              (zip (repeat manDir) manpages)
 
 ppBlobSuffixHandler :: PPSuffixHandler

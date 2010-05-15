--- ./Setup.hs.orig	2010-03-29 16:24:56.000000000 +0200
+++ ./Setup.hs	2010-05-15 13:39:12.000000000 +0200
@@ -6,7 +6,7 @@
 import Distribution.Simple.LocalBuildInfo
          (LocalBuildInfo(..), absoluteInstallDirs)
 import Distribution.Verbosity ( Verbosity, silent )
-import Distribution.Simple.InstallDirs (mandir, bindir, CopyDest (NoCopyDest))
+import Distribution.Simple.InstallDirs (prefix, bindir, CopyDest (NoCopyDest))
 import Distribution.Simple.Utils (copyFiles)
 import Control.Exception ( bracket_ )
 import Control.Monad ( unless )
@@ -86,7 +86,7 @@
 installManpages :: PackageDescription -> LocalBuildInfo
                 -> Verbosity -> CopyDest -> IO ()
 installManpages pkg lbi verbosity copy =
-  copyFiles verbosity (mandir (absoluteInstallDirs pkg lbi copy) </> "man1")
+  copyFiles verbosity (prefix (absoluteInstallDirs pkg lbi copy) </> "man/man1")
              (zip (repeat manDir) manpages)
 
 -- | Returns a list of 'dependencies' that have been modified after 'file'.

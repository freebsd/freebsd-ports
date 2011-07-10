--- ./Setup.hs.orig	2011-03-17 11:23:52.000000000 +0100
+++ ./Setup.hs	2011-05-22 14:33:40.000000000 +0200
@@ -204,7 +204,7 @@
                        else docdir (absoluteInstallDirs pd lbi cd) `joinFileName` "doc"
         let manDir = if isWindows
                        then dataPref `joinFileName` "Documentation"
-                       else datadir (absoluteInstallDirs pd lbi cd) `joinFileName` ".." `joinFileName` "man" `joinFileName` "man1"
+                       else prefix (absoluteInstallDirs pd lbi cd) `joinFileName` "man" `joinFileName` "man1"
         createDirectoryIfMissing True docDir
         installOrdinaryFile v (lhs2texDocDir `joinFileName` "Guide2.pdf") (docDir `joinFileName` "Guide2.pdf")
         when (not isWindows) $

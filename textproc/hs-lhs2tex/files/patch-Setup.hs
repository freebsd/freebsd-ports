--- Setup.hs.orig	2012-09-08 22:29:52.000000000 +0100
+++ Setup.hs	2013-12-08 15:55:17.403235103 +0000
@@ -205,7 +205,7 @@
                        else docdir (absoluteInstallDirs pd lbi cd) `joinFileName` "doc"
         let manDir = if isWindows
                        then dataPref `joinFileName` "Documentation"
-                       else datadir (absoluteInstallDirs pd lbi cd) `joinFileName` ".." `joinFileName` "man" `joinFileName` "man1"
+                       else prefix (absoluteInstallDirs pd lbi cd) `joinFileName` "man" `joinFileName` "man1"
         createDirectoryIfMissing True docDir
         installOrdinaryFile v (lhs2texDocDir `joinFileName` "Guide2.pdf") (docDir `joinFileName` "Guide2.pdf")
         when (not isWindows) $
@@ -213,7 +213,8 @@
              installOrdinaryFile v ("lhs2TeX.1") (manDir `joinFileName` "lhs2TeX.1")
         -- polytable
         case (installPolyTable ebi) of
-          Just texmf -> do  let texmfDir = texmf
+          Just texmf -> do  let CopyTo destdir = cd
+                                texmfDir = destdir `joinFileName` texmf
                                 ptDir = texmfDir `joinFileName` "tex" `joinFileName` "latex"
                                                  `joinFileName` "polytable"
                             createDirectoryIfMissing True ptDir

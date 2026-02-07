--- Setup.hs.orig	2017-09-29 08:44:16 UTC
+++ Setup.hs
@@ -210,7 +210,7 @@ lhs2texPostCopy a (CopyFlags { copyDest = cdf, copyVer
                        else docdir (absoluteInstallDirs pd lbi cd) `joinFileName` "doc"
         let manDir = if isWindows
                        then dataPref `joinFileName` "Documentation"
-                       else datadir (absoluteInstallDirs pd lbi cd) `joinFileName` ".." `joinFileName` "man" `joinFileName` "man1"
+                       else prefix (absoluteInstallDirs pd lbi cd) `joinFileName` "man" `joinFileName` "man1"
         createDirectoryIfMissing True docDir
         installOrdinaryFile v (lhs2texDocDir `joinFileName` "Guide2.pdf") (docDir `joinFileName` "Guide2.pdf")
         when (not isWindows) $
@@ -218,7 +218,8 @@ lhs2texPostCopy a (CopyFlags { copyDest = cdf, copyVer
              installOrdinaryFile v ("lhs2TeX.1") (manDir `joinFileName` "lhs2TeX.1")
         -- polytable
         case (installPolyTable ebi) of
-          Just texmf -> do  let texmfDir = texmf
+          Just texmf -> do  let CopyTo destdir = cd
+                                texmfDir = destdir `joinFileName` texmf
                                 ptDir = texmfDir `joinFileName` "tex" `joinFileName` "latex"
                                                  `joinFileName` "polytable"
                             createDirectoryIfMissing True ptDir

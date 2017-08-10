Backport of:
From 2f787c5c1ba42ccee2f1ced759b3a4570afa9b28 Mon Sep 17 00:00:00 2001
From: ilovezfs <ilovezfs@icloud.com>
Date: Mon, 23 May 2016 03:53:52 -0700
Subject: [PATCH] cgrep: fix isSymbolicLink collision

System.Directory.isSymbolicLink collides with
System.PosixCompat.Files.isSymbolicLink (and with
System.Posix.Files.isSymbolicLink)

This applies the solution proposed here:
https://github.com/haskell/directory/issues/52#issuecomment-220879392
--- src/Main.hs.orig	2014-06-21 09:27:05 UTC
+++ src/Main.hs
@@ -37,7 +37,7 @@ import System.Console.CmdArgs
 import System.Directory
 import System.FilePath ((</>), takeFileName)
 import System.Environment
-import System.Posix.Files
+import System.Posix.Files as PosixFiles
 import System.IO
 import System.Exit
 
@@ -67,7 +67,7 @@ putRecursiveContents opts inchan topdir langs prunedir
                 status  <- getFileStatus path
                 lstatus <- getSymbolicLinkStatus path
                 unless (cpath `Set.member` visited) $
-                    if isDirectory status && (not (isSymbolicLink lstatus) || deference_recursive opts)
+                    if isDirectory status && (not (PosixFiles.isSymbolicLink lstatus) || deference_recursive opts)
                        then unless (filename `elem` prunedir)  $
                            putRecursiveContents opts inchan path langs prunedir (Set.insert cpath visited)
                        else case getLang opts filename >>= (\f -> f `elemIndex` langs <|> toMaybe 0 (null langs) ) of

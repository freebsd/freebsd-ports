--- ./chrome/common/chrome_paths.cc.orig	2010-12-16 02:12:13.000000000 +0100
+++ ./chrome/common/chrome_paths.cc	2010-12-20 20:15:08.000000000 +0100
@@ -164,7 +164,7 @@
       cur = cur.Append(FILE_PATH_LITERAL("inspector"));
       break;
     case chrome::DIR_APP_DICTIONARIES:
-#if defined(OS_LINUX) || defined(OS_MACOSX)
+#if defined(OS_POSIX)
       // We can't write into the EXE dir on Linux, so keep dictionaries
       // alongside the safe browsing database in the user data dir.
       // And we don't want to write into the bundle on the Mac, so push

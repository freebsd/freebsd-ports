--- dir.cc.orig	2015-06-23 12:16:14.909394000 +0800
+++ dir.cc	2015-06-23 12:16:22.284741000 +0800
@@ -103,7 +103,7 @@
     if ( !entryPtr )
       return false;
 
-#ifndef __APPLE__
+#if !defined(__APPLE__) && !defined(__FreeBSD__)
     if ( fstatat( dirfd( dir ), entry.d_name, &entryStats,
                   AT_SYMLINK_NOFOLLOW ) != 0 )
 #else

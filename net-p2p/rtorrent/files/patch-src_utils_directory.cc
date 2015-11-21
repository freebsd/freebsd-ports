--- src/utils/directory.cc.orig	2014-04-21 13:34:45 UTC
+++ src/utils/directory.cc
@@ -88,6 +88,10 @@ Directory::update(int flags) {
     itr->d_fileno = entry->d_ino;
     itr->d_reclen = 0;
     itr->d_type = s.st_mode;
+#elif defined(__DragonFly__)
+    itr->d_fileno = entry->d_fileno;
+    itr->d_reclen = _DIRENT_RECLEN(entry->d_namlen);
+    itr->d_type   = entry->d_type;
 #else
     itr->d_fileno = entry->d_fileno;
     itr->d_reclen = entry->d_reclen;

--- src/utils/directory.cc.orig	2012-03-29 13:06:11.000000000 +0000
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

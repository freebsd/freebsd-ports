--- libs/sqwebmail/maildir.h.orig	2004-02-17 01:58:24.000000000 +0100
+++ libs/sqwebmail/maildir.h	2009-06-04 08:40:43.000000000 +0200
@@ -49,6 +49,7 @@
 extern int maildir_name2pos(const char *, const char *, size_t *);
 
 extern char maildirfile_type(const char *);
+extern int maildirfile_flag(const char *);
 extern void maildir_markread(const char *, size_t);
 extern void maildir_markreplied(const char *, const char *);
 extern void maildir_msgdeletefile(const char *, const char *, size_t);
@@ -56,6 +57,8 @@
 extern void maildir_msgpurgefile(const char *, const char *);
 extern void maildir_purgemimegpg();
 extern void maildir_purgesearch();
+extern void maildir_msgmarkfile(const char *, const char *, size_t);
+extern void maildir_msgunmarkfile(const char *, const char *, size_t);
 
 extern int maildir_msgmove(const char *, size_t, const char *);
 extern int maildir_msgmovefile(const char *, const char *, const char *, size_t);

--- webmail/maildir.h.orig	2004-02-17 01:58:24.000000000 +0100
+++ webmail/maildir.h	2009-06-04 08:40:43.000000000 +0200
@@ -35,12 +35,15 @@
 extern int maildir_name2pos(const char *, const char *, size_t *);
 
 extern char maildirfile_type(const char *);
+extern int maildirfile_flag(const char *);
 extern void maildir_markread(const char *, size_t);
 extern void maildir_markreplied(const char *, const char *);
 extern void maildir_msgdeletefile(const char *, const char *, size_t);
 extern void maildir_msgpurge(const char *, size_t);
 extern void maildir_msgpurgefile(const char *, const char *);
 extern void maildir_purgemimegpg();
+extern void maildir_msgmarkfile(const char *, const char *, size_t);
+extern void maildir_msgunmarkfile(const char *, const char *, size_t);
 
 extern int maildir_msgmove(const char *, size_t, const char *);
 extern int maildir_msgmovefile(const char *, const char *, const char *, size_t);

--- lib/ftlib.h.orig	Wed Sep 26 16:21:50 2007
+++ lib/ftlib.h	Wed Sep 26 16:21:23 2007
@@ -416,8 +416,8 @@
 };
 
 struct fttime {
-  u_int32 secs;
-  u_int32 msecs;
+  time_t secs;
+  time_t msecs;
 };
 
 struct ftver {
@@ -2710,7 +2710,7 @@
 int ftfile_dump(struct ftfile_entries *fte);
 struct ftfile_entry *ftfile_entry_new(int len);
 void ftfile_entry_free(struct ftfile_entry *entry);
-int ftfile_mkpath(u_int32 ftime, int nest);
+int ftfile_mkpath(time_t ftime, int nest);
 void ftfile_pathname(char *buf, int bsize, int nest, struct ftver ftv,
  int done, u_int32 ftime);
 

--XsQoSWH+UP9D9v3l--

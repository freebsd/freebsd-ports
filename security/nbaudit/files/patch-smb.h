diff -ru ../../work/nat10/smb.h ./smb.h
--- smb.h.orig	Sun Feb 16 19:18:04 1997
+++ smb.h	Sat Jun 14 23:02:35 2003
@@ -733,7 +733,6 @@
 int get_share_mode_byname(int cnum,char *fname,int *pid);
 int get_share_mode_by_fnum(int cnum,int fnum,int *pid);
 BOOL check_file_sharing(int cnum,char *fname);
-char *StrCpy(char *dest,char *src);
 int unix_error_packet(char *inbuf,char *outbuf,int def_class,uint32 def_code,int line);
 time_t make_unix_date2(void *date_ptr);
 int cached_error_packet(char *inbuf,char *outbuf,int fnum,int line);

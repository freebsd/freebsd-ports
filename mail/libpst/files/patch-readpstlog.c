--- readpstlog.c.orig	Sun Sep 25 14:25:38 2005
+++ readpstlog.c	Sun Sep 25 14:29:10 2005
@@ -21,11 +21,11 @@
 
 int main(int argc, char** argv) {
   int *i=NULL, x, ptr, stop=0, flag;  
-  char *fname, *buf, format, rec_type;
+  char *fname, *buf, format = ' ', rec_type;
   unsigned char version;
   int *show_type=NULL, show_size=0;
   int *ex_type=NULL, ex_size=0;
-  unsigned int funcname, filename, text, end, dtype, line, c;
+  unsigned int funcname=0, filename=0, text=0, end=0, dtype=0, line=0, c;
   FILE *fp;
   struct _debug_file_rec_m mfile_rec;
   struct _debug_file_rec_l lfile_rec;

--- mh.c.orig	Fri Nov  9 10:28:55 2001
+++ mh.c	Tue Dec  4 16:06:14 2001
@@ -29,6 +29,12 @@
 #include "buffy.h"
 #include "sort.h"
 
+/*
+ * Additional maildir handling routines so that mutt abides
+ * by the maildir specification
+ */
+#include "maildir_clean_dir.h"
+
 #include <sys/stat.h>
 #include <dirent.h>
 #include <limits.h>
@@ -41,6 +47,8 @@
 #include <errno.h>
 #include <string.h>
 
+#define MACRO_MAILDIR_TMP_CLN_INTERVAL	((MaildirTmpClnInterval>0) ? (MaildirTmpClnInterval*60) : (MAILDIR_TMP_TIME_LIMIT))
+
 struct maildir
 {
   HEADER *h;
@@ -520,6 +528,11 @@
   
   if(ctx->magic == M_MAILDIR)
   {
+    if(option (OPTCLEANMTMP)) {
+      snprintf(buf, sizeof(buf), "%s/%s", ctx->path, "tmp");
+    if(stat (buf, &st) == 0)
+      ctx->mtime_tmp = st.st_mtime;
+    }
     snprintf(buf, sizeof(buf), "%s/%s", ctx->path, "cur");
     if(stat (buf, &st) == 0)
       ctx->mtime_cur = st.st_mtime;
@@ -750,8 +763,10 @@
 {
   /* maildir looks sort of like MH, except that there are two subdirectories
    * of the main folder path from which to read messages
+   * and one to clean up
    */
-  if (mh_read_dir (ctx, "new") == -1 || mh_read_dir (ctx, "cur") == -1)
+  if (mh_read_dir (ctx, "new") == -1 || mh_read_dir (ctx, "cur") == -1 ||
+      maildir_clean_dir (ctx, "tmp", (MACRO_MAILDIR_TMP_CLN_INTERVAL)) == -1)
     return (-1);
 
   return 0;
@@ -850,8 +865,6 @@
   return 0;
 }
 
-
-
 /*
  * Commit a message to a maildir folder.
  * 
@@ -1246,6 +1259,9 @@
   struct maildir **last;
   HASH *fnames;
   int i, j;
+  struct stat st_tmp;
+  short aged_tmp = 0;
+  time_t rightnow = 0;
   
   if(!option (OPTCHECKNEW))
     return 0;
@@ -1290,6 +1306,15 @@
     if(stat(buf, &st_cur) == -1)			/* XXX - name is bad. */
       modified = 1;
 
+    if (option (OPTCLEANMTMP)) {
+      snprintf(buf, sizeof(buf), "%s/tmp", ctx->path);
+      if (stat(buf, &st_tmp) == -1)
+        aged_tmp = 1;
+      if ((rightnow = time(NULL)) == ((time_t) -1))
+        return -1; /* can't get time ? */
+    } else {
+      aged_tmp = 1;
+    }
   }
   
   if(!modified && ctx->magic == M_MAILDIR && st_cur.st_mtime > ctx->mtime_cur)
@@ -1301,12 +1326,18 @@
   if(modified || (ctx->magic == M_MAILDIR && st.st_mtime > ctx->mtime))
     have_new = 1;
   
+  aged_tmp = (!aged_tmp && ctx->magic == M_MAILDIR &&
+	((st_tmp.st_mtime > ctx->mtime_tmp) || (ctx->atime_tmp && 
+		(difftime (rightnow,ctx->atime_tmp) > (MACRO_MAILDIR_TMP_CLN_INTERVAL) )))) ? 1 : 0;
+
   if(!modified && !have_new)
     return 0;
 
   ctx->mtime_cur = st_cur.st_mtime;
   ctx->mtime = st.st_mtime;
 
+  if(aged_tmp)
+	ctx->mtime_tmp = st_tmp.st_mtime;
 #if 0
   if(Sort != SORT_ORDER)
   {
@@ -1328,6 +1359,8 @@
       maildir_parse_dir(ctx, &last, "new", NULL);
     if(modified)
       maildir_parse_dir(ctx, &last, "cur", NULL);
+    if(aged_tmp)
+      maildir_clean_dir(ctx, "tmp", (MACRO_MAILDIR_TMP_CLN_INTERVAL));
   }
   else if(ctx->magic == M_MH)
   {

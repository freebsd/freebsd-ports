--- mutt.h.orig	Wed Feb 21 02:33:48 2001
+++ mutt.h	Wed Feb 21 02:34:30 2001
@@ -16,6 +16,9 @@
  *     Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111, USA.
  */ 
 
+#ifndef _MUTT_H
+# define _MUTT_H
+
 #include "config.h"
 
 #include <stdio.h>
@@ -42,6 +45,8 @@
 # define MUTT_VERSION (VERSION)
 #endif
 
+#define MAILDIR_TMP_TIME_LIMIT (36*60*60) /* seconds */
+
 /* nifty trick I stole from ELM 2.5alpha. */
 #ifdef MAIN_C
 #define WHERE 
@@ -278,6 +283,7 @@
   OPTBEEPNEW,
   OPTBOUNCEDELIVERED,
   OPTCHECKNEW,
+  OPTCLEANMTMP,
   OPTCOLLAPSEUNREAD,
   OPTCONFIRMAPPEND,
   OPTCONFIRMCREATE,
@@ -639,6 +645,8 @@
   FILE *fp;
   time_t mtime;
   time_t mtime_cur;		/* used with maildir folders */
+  time_t mtime_tmp;		/* these 2 used with maildir folders */
+  time_t atime_tmp;
   off_t size;
   off_t vsize;
   char *pattern;                /* limit pattern string */
@@ -716,3 +724,5 @@
 #include "protos.h"
 #include "lib.h"
 #include "globals.h"
+
+#endif /* _MUTT_H */

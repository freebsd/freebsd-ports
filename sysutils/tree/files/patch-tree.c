--- tree.c.orig	Tue Jan  9 23:07:16 2007
+++ tree.c	Thu Jan 25 18:58:28 2007
@@ -17,7 +17,6 @@
  * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
  */
 
-#include <features.h>
 #include <stdlib.h>
 #include <stdio.h>
 #include <time.h>
@@ -148,7 +147,7 @@
 int findino(ino_t, dev_t);
 void *xmalloc(size_t), *xrealloc(void *, size_t);
 void listdir(char *, int *, int *, u_long, dev_t), usage(int);
-void parse_dir_colors(), printit(unsigned char *), free_dir(struct _info **), indent();
+void parse_dir_colors(), printit(char *), free_dir(struct _info **), indent();
 void saveino(ino_t, dev_t);
 char **split(char *, char *, int *);
 char *gidtoname(int), *uidtoname(int), *do_date(time_t);
@@ -178,12 +177,6 @@
 char *sLevel, *curdir, *outfilename = NULL;
 FILE *outfile;
 int *dirs, maxdirs;
-
-#ifdef CYGWIN
-extern int MB_CUR_MAX;
-#else
-extern size_t MB_CUR_MAX;
-#endif
 
 int main(int argc, char **argv)
 {
@@ -622,7 +615,7 @@
 #ifdef __USE_FILE_OFFSET64
     if (inodeflag) sprintf(path," %7lld",(*dir)->inode);
 #else
-    if (inodeflag) sprintf(path," %7ld",(*dir)->inode);
+    if (inodeflag) sprintf(path," %7i",(*dir)->inode);
 #endif
     if (devflag) sprintf(path+strlen(path), " %3d", (int)(*dir)->dev);
 #ifdef __EMX__
@@ -1041,8 +1034,10 @@
   } else {
     if (Hflag) fprintf(outfile,"<br>\t\t\t\t   ");
     for(i=0;dirs[i];i++) {
+      if( dirs[i] <= 0 )
+          break;
       fprintf(outfile,"%s ",
-	      dirs[i+1] ? (dirs[i]==1 ? linedraw->vert     : (Hflag? "&nbsp;&nbsp;&nbsp;" : "   ") )
+	      dirs[i+1] > 0 ? (dirs[i]==1 ? linedraw->vert     : (Hflag? "&nbsp;&nbsp;&nbsp;" : "   ") )
 			: (dirs[i]==1 ? linedraw->vert_left:linedraw->corner));
     }
   }
@@ -1180,7 +1175,7 @@
   return t->name;
 }
 
-void printit(unsigned char *s)
+void printit(char *s)
 {
   int c;
 

--- ./tree.c.orig	2010-01-14 14:08:55.000000000 +0100
+++ ./tree.c	2010-01-14 14:15:23.000000000 +0100
@@ -682,7 +682,7 @@
 #ifdef __USE_FILE_OFFSET64
     if (inodeflag) sprintf(path," %7lld",(*dir)->inode);
 #else
-    if (inodeflag) sprintf(path," %7ld",(*dir)->inode);
+    if (inodeflag) sprintf(path," %7u",(*dir)->inode);
 #endif
     if (devflag) sprintf(path+strlen(path), " %3d", (int)(*dir)->dev);
 #ifdef __EMX__
@@ -1106,8 +1106,10 @@
   } else {
     if (Hflag) fprintf(outfile,"<br>\t\t\t\t   ");
     for(i=0; dirs[i] && i <= maxlevel; i++) {
+      if (dirs[i] <= 0)
+         break;
       fprintf(outfile,"%s ",
-	      dirs[i+1] ? (dirs[i]==1 ? linedraw->vert     : (Hflag? "&nbsp;&nbsp;&nbsp;" : "   ") )
+             dirs[i+1] > 0 ? (dirs[i]==1 ? linedraw->vert     : (Hflag? "&nbsp;&nbsp;&nbsp;" : "   ") )
 			: (dirs[i]==1 ? linedraw->vert_left:linedraw->corner));
     }
   }
@@ -1294,8 +1296,12 @@
 {
   char *unit="BKMGTPEZY";
   int idx;
-
-  if (!hflag) sprintf(buf, sizeof(off_t) == sizeof(long long)? " %11lld" : " %9ld", size);
+  if (!hflag) {
+	if (sizeof(off_t) == sizeof(__int64_t))
+	  sprintf(buf, sizeof(long) == sizeof(long long) ? " %11ld" : " %11lld", size);
+	else
+	  sprintf(buf, sizeof(long) == sizeof(long long) ? " %9ld" : " %9lld", size);
+  }
   else {
     for (idx=size<1024?0:1; size >= (1024*1024); idx++,size>>=10);
     if (!idx) sprintf(buf, " %4d", (int)size);

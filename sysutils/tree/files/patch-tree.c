--- tree.c.orig	2008-08-28 03:05:43.000000000 +0800
+++ tree.c	2008-09-22 21:37:05.000000000 +0800
@@ -663,7 +663,7 @@
 #ifdef __USE_FILE_OFFSET64
     if (inodeflag) sprintf(path," %7lld",(*dir)->inode);
 #else
-    if (inodeflag) sprintf(path," %7ld",(*dir)->inode);
+    if (inodeflag) sprintf(path," %7u",(*dir)->inode);
 #endif
     if (devflag) sprintf(path+strlen(path), " %3d", (int)(*dir)->dev);
 #ifdef __EMX__
@@ -1087,8 +1087,10 @@
   } else {
     if (Hflag) fprintf(outfile,"<br>\t\t\t\t   ");
     for(i=0;dirs[i];i++) {
+      if( dirs[i] <= 0 )
+        break;
       fprintf(outfile,"%s ",
-	      dirs[i+1] ? (dirs[i]==1 ? linedraw->vert     : (Hflag? "&nbsp;&nbsp;&nbsp;" : "   ") )
+          dirs[i+1] > 0 ? (dirs[i]==1 ? linedraw->vert     : (Hflag? "&nbsp;&nbsp;&nbsp;" : "   ") )
 			: (dirs[i]==1 ? linedraw->vert_left:linedraw->corner));
     }
   }
@@ -1276,7 +1276,12 @@
   char *unit="BKMGTPEZY";
   int idx;
 
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

$FreeBSD$

--- tree.c.orig	Mon Jan 29 22:38:30 2001
+++ tree.c	Mon Dec 24 08:09:39 2001
@@ -422,7 +422,7 @@
       if (!noindent) indent();
 
       if (inodeflag || devflag || pflag || sflag || uflag || gflag || Dflag) fprintf(outfile,"[");
-      if (inodeflag) fprintf(outfile,"%7ld",(*dir)->inode);
+      if (inodeflag) fprintf(outfile,"%7ld",(long)(*dir)->inode);
       if (inodeflag && (devflag || pflag || uflag || gflag || sflag || Dflag)) fprintf(outfile,"%s",sp);
       if (devflag) fprintf(outfile,"%3d",(*dir)->dev);
       if (devflag && (pflag || uflag || gflag || sflag || Dflag)) fprintf(outfile,"%s",sp);

$FreeBSD$

--- tree.c.orig	Mon Jan 29 22:38:30 2001
+++ tree.c	Mon Dec 24 08:09:39 2001
@@ -417,7 +417,7 @@
       if (uflag && (gflag || sflag || Dflag)) fprintf(outfile,"%s",sp);
       if (gflag) fprintf(outfile,"%-8.8s",gidtoname((*dir)->gid));
       if (gflag && (sflag || Dflag)) fprintf(outfile,"%s",sp);
-      if (sflag) fprintf(outfile,"%9ld",(*dir)->size);
+      if (sflag) fprintf(outfile,"%9ld",(long)(*dir)->size);
       if (sflag && Dflag) fprintf(outfile,"%s",sp);
       if (Dflag) fprintf(outfile,"%s",do_date((*dir)->mtime));
       if (pflag || sflag || uflag || gflag || Dflag) fprintf(outfile,"]%s%s",sp,sp);

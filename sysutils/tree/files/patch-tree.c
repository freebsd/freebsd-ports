--- tree.c.orig	Mon May 12 16:44:19 2003
+++ tree.c	Mon May 12 16:44:24 2003
@@ -22,10 +22,10 @@
 #include <grp.h>
 
 static char *version = "$Version: $ tree v1.3 (c) 1996 - 1999 by Steve Baker, Thomas Moore $";
-static char *hversion= "tree v1.3 \251 1996 - 1999 by Steve Baker and Thomas Moore\
-<BR>HTML output hacked and copyleft \251 1998 by Francesc Rocher\
-<BR>This software is experimental. Send commends and/or
-<BR>suggestions to <A HREF=\"mailto:rocher@econ.udg.es\">rocher@econ.udg.es</A>";
+static char *hversion= "tree v1.3 \251 1996 - 1999 by Steve Baker and Thomas Moore"
+"<BR>HTML output hacked and copyleft \251 1998 by Francesc Rocher"
+"<BR>This software is experimental. Send commends and/or\n"
+"<BR>suggestions to <A HREF=\"mailto:rocher@econ.udg.es\">rocher@econ.udg.es</A>";
 
 #define scopy(x)	strcpy(xmalloc(strlen(x)+1),(x))
 
@@ -417,7 +417,7 @@
       if (uflag && (gflag || sflag || Dflag)) fprintf(outfile,"%s",sp);
       if (gflag) fprintf(outfile,"%-8.8s",gidtoname((*dir)->gid));
       if (gflag && (sflag || Dflag)) fprintf(outfile,"%s",sp);
-      if (sflag) fprintf(outfile,"%9ld",(*dir)->size);
+      if (sflag) fprintf(outfile,"%9ld",(long)(*dir)->size);
       if (sflag && Dflag) fprintf(outfile,"%s",sp);
       if (Dflag) fprintf(outfile,"%s",do_date((*dir)->mtime));
       if (pflag || sflag || uflag || gflag || Dflag) fprintf(outfile,"]%s%s",sp,sp);
@@ -1022,6 +1022,7 @@
 	}
       }
     default:
+      ;
     }
   }
 

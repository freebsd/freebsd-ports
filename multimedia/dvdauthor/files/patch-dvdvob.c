--- src/dvdvob.c.orig	Sun Mar 14 22:13:26 2004
+++ src/dvdvob.c	Wed Aug 11 19:52:52 2004
@@ -1148,7 +1148,7 @@
                         printpts(pts1);
                         fprintf(stderr,"\n");
                         ach->audpts[ach->numaudpts-1].pts[1]=pts0;
-                    noshow:
+                    noshow:;
                     }
                     ach->audpts[ach->numaudpts].pts[0]=pts0;
                     ach->audpts[ach->numaudpts].pts[1]=pts1;

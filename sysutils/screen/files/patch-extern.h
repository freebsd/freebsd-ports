--- extern.h.orig	2019-10-01 15:08:00.000000000 -0700
+++ extern.h	2019-10-28 19:37:41.584313000 -0700
@@ -235,6 +235,7 @@
 /* termcap.c */
 extern int   InitTermcap __P((int, int));
 extern char *MakeTermcap __P((int));
+extern void  DumpTermcap __P((int, FILE *));
 extern char *gettermcapstring __P((char *));
 #ifdef MAPKEYS
 extern int   remap __P((int, int));

--- topo/src/extractcoll.c.orig	2023-04-26 07:46:42 UTC
+++ topo/src/extractcoll.c
@@ -233,8 +233,6 @@ void usage (char *progname)
     exit (1) ;
 }
 
-MOBJ *mobjlist [NB_MOBJ] ;
-
 int main (int argc, char *argv [])
 {
     char *prog, *errstr ;

--- p0f.c.orig	Thu Jan 17 21:05:58 2002
+++ p0f.c	Mon Jan 21 00:22:56 2002
@@ -348,10 +348,9 @@
         T_tstamp = 1;
 	break;
       case 'o':
-        { FILE* x;
-          x=fopen(optarg,"a");
-          if (!x) { perror(optarg); exit(1); }
-          stdout=x;
+        if (!freopen(optarg,"a",stdout)) {
+          perror(optarg);
+          exit(1);
         }
 	break;
       default:

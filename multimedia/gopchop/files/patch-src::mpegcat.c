--- src/mpegcat.c.orig	Sun Apr 27 12:08:37 2003
+++ src/mpegcat.c	Sun Jun  8 16:50:36 2003
@@ -392,11 +392,19 @@
                 break;
 
             case 'n':
+#ifdef __FreeBSD__
+                num_bytes = strtoll(optarg, NULL, 10);
+#else
                 num_bytes = atoll(optarg);
+#endif
                 break;
 
             case 'b':
+#ifdef __FreeBSD__
+                begin_at = num_bytes = strtoll(optarg, NULL, 10);
+#else
                 begin_at = atoll(optarg);
+#endif
                 break;
 
             case 'w':

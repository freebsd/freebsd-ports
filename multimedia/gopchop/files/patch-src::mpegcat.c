--- src/mpegcat.c.orig	Mon Apr 14 12:21:04 2003
+++ src/mpegcat.c	Tue May  6 21:46:58 2003
@@ -390,11 +390,19 @@
 			break;
 
 		case 'n':
+#ifdef __FreeBSD__
+			num_bytes = strtoll(optarg, NULL, 10);
+#else
 			num_bytes = atoll(optarg);
+#endif
 			break;
 
 		case 'b':
+#ifdef __FreeBSD__
+			begin_at = strtoll(optarg, NULL, 10);
+#else
 			begin_at = atoll(optarg);
+#endif
 			break;
 
 		case 'w':

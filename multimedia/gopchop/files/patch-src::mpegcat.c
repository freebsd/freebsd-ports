--- src/mpegcat.c.orig	Mon Mar 11 23:53:10 2002
+++ src/mpegcat.c	Fri Jul 12 00:50:19 2002
@@ -143,11 +143,11 @@
 			break;
 
 		case 'n':
-			num_bytes = atoll(optarg);
+			num_bytes = strtoll(optarg, (char **)NULL, 10);
 			break;
 
 		case 'b':
-			begin_at = atoll(optarg);
+			begin_at = strtoll(optarg, (char **)NULL, 10);
 			break;
 
 		default:

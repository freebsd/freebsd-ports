--- ./src/racoon/var.h.orig	Wed Jun  6 01:06:51 2007
+++ ./src/racoon/var.h	Wed Jun  6 01:07:00 2007
@@ -76,9 +76,9 @@
 do { \
 	if (getnameinfo((x), sysdep_sa_len(x), (y), sizeof(y), (z), sizeof(z), \
 			NIFLAGS) != 0) { \
-		if (y) \
+		if (y != NULL) \
 			strncpy((y), "(invalid)", sizeof(y)); \
-		if (z) \
+		if (z != NULL) \
 			strncpy((z), "(invalid)", sizeof(z)); \
 	} \
 } while (0);
@@ -87,7 +87,7 @@
 do { \
 	if (getnameinfo((x), sysdep_sa_len(x), (y), sizeof(y), NULL, 0, \
 			NIFLAGS) != 0) { \
-		if (y) \
+		if (y != NULL) \
 			strncpy((y), "(invalid)", sizeof(y)); \
 	} \
 } while (0);

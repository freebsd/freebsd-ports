--- src/wireless.c.orig	Tue Mar  9 20:39:17 2004
+++ src/wireless.c	Mon Jul 11 10:57:43 2005
@@ -143,6 +143,7 @@
 
 	max = get_max_ifs();
 	step = 0;
+	found = 0;
 
 	if (old > max)
 		old = max; /* just be sure to not be out of bounds */
@@ -193,9 +194,11 @@
 
 		if (ioctl(s, SIOCGIFMEDIA, (caddr_t) &ifmr) < 0)
 		{
-			perror("ioctl");
+			char str[128];
+			snprintf(str, 128, "ioctl for interface %s failed", ifmr.ifm_name);
 			close(s);
-			exit(1);
+			warn(str);
+			continue;
 		}
 		close(s);
 		/* we cannot monitor interfaces in hostap mode, so just
@@ -207,6 +210,10 @@
 			found++;
 		}
 	}
+
+	if (!found)
+	  return -1;
+
 	return index;
 }
 /* how many interfaces do we have? this includes non-wireless! */

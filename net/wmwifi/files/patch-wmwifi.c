--- src/wmwifi.c.orig	Mon Jul 11 10:58:32 2005
+++ src/wmwifi.c	Mon Jul 11 11:01:27 2005
@@ -67,9 +67,11 @@
     int ncolor = 0;
     struct wifi wfi;
 
-	/* find a valid wireless interface */
+    bzero(&wfi, sizeof(wfi));
+    /* find a valid wireless interface */
 #if __FreeBSD__
-	wfi.ifnum = get_wlaniface(0, 1);
+    if ((wfi.ifnum = get_wlaniface(0, 1)) < 0)
+      errx(1, "No wireless interface found!");
 #else
     wfi.ifnum = 0;
 #endif
@@ -146,14 +148,16 @@
 		    break;
 		case Button2:
 #ifdef __FreeBSD__
-			wfi.ifnum = get_wlaniface(wfi.ifnum, 1);
+		    if ((wfi.ifnum = get_wlaniface(wfi.ifnum, 1)) < 0)
+			errx(1, "No wireless interface found!");
 #else
 		    next_if(&wfi);
 #endif
 		    break;
 		case Button3:
 #ifdef __FreeBSD__
-			wfi.ifnum = get_wlaniface(wfi.ifnum, -1);
+		    if ((wfi.ifnum = get_wlaniface(wfi.ifnum, -1)) < 0)
+		      errx(1, "No wireless interface found!");
 #else
 		    prev_if(&wfi);
 #endif

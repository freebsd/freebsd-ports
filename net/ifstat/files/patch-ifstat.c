--- ifstat.c.orig	2003-11-21 19:27:51.000000000 -0600
+++ ifstat.c	2015-05-14 19:32:07.000000000 -0500
@@ -229,6 +229,7 @@
 #define OPT_WRAP      64
 #define OPT_NOTITLE  128
 #define OPT_NOSCROLL 256
+#define OPT_MEGA     512
 
 #define SPACE "  "
 
@@ -278,8 +279,21 @@
     if (pos > 0)
       fputs(SPACE, stdout);
     len = LEN(options, ptr->namelen);
-    print_center((options & OPT_UNITBITS) ? " Kbps in  Kbps out" :
-		 " KB/s in  KB/s out", WIDTH, len);
+    // print_center((options & OPT_UNITBITS) ? " Kbps in  Kbps out" :
+    //		 " KB/s in  KB/s out", WIDTH, len);
+    if (options & OPT_UNITBITS) {
+      if (options & OPT_MEGA) {
+        print_center(" Mbps in  Mbps out", WIDTH, len);
+      } else {
+        print_center(" Kbps in  Kbps out", WIDTH, len);
+      }
+    } else {
+      if (options & OPT_MEGA) {
+        print_center(" MB/s in  MB/s out", WIDTH, len);
+      } else {
+        print_center(" KB/s in  KB/s out", WIDTH, len);
+      }
+    }
     if ((pos = pos_next(pos, len, options)) == 0 && ptr->next != NULL)
       return;
   }
@@ -338,7 +352,18 @@
   
   delay = end->tv_sec - start->tv_sec + ((double) (end->tv_usec - start->tv_usec))
     / (double) 1000000;
-  scale = delay * (options & OPT_UNITBITS ? 128 : 1024);
+  //scale = delay * (options & OPT_UNITBITS ? 128 : 1024);
+  if (options & OPT_UNITBITS) {
+    scale = delay * 128;
+    if (options & OPT_MEGA)
+      scale = scale * 1024;
+  } else { 
+    if (options & OPT_MEGA) {
+      scale = delay * 1024 * 1024;
+    }else {
+      scale = delay * 1024;
+    }
+  }
   
   tkbin = tkbout = 0;
   for (ptr = ifs->first; ptr != NULL; ptr = ptr->next) {
@@ -511,6 +536,9 @@
       case 'b':
 	options |= OPT_UNITBITS;
 	break;
+      case 'm':
+        options |= OPT_MEGA;
+        break;
       case 'z':
 	options |= OPT_NONULL;
 	break;

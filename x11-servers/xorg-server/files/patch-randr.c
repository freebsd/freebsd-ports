--- randr/randr.c.orig	Thu Mar 15 13:21:48 2007
+++ randr/randr.c	Thu Mar 15 13:22:00 2007
@@ -472,8 +472,8 @@
     rep.type = X_Reply;
     rep.length = 0;
     rep.sequenceNumber = client->sequence;
-    rep.majorVersion = RANDR_MAJOR;
-    rep.minorVersion = RANDR_MINOR;
+    rep.majorVersion = 1;
+    rep.minorVersion = 2;
     if (client->swapped) {
     	swaps(&rep.sequenceNumber, n);
     	swapl(&rep.length, n);

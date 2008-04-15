--- libfprint/imgdev.c.orig	2008-04-12 14:37:10.000000000 +0200
+++ libfprint/imgdev.c	2008-04-12 14:40:17.000000000 +0200
@@ -175,7 +175,7 @@
 
 	if (img == NULL) {
 		fp_err("capture succeeded but no image returned?");
-		return -ENODATA;
+		return -ENOMSG;
 	}
 
 	if (!unconditional && imgdrv->await_finger_off) {

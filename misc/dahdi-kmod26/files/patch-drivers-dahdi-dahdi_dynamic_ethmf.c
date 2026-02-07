--- drivers/dahdi/dahdi_dynamic_ethmf.c.orig	2015-03-22 01:02:19.881617000 +0600
+++ drivers/dahdi/dahdi_dynamic_ethmf.c	2015-03-22 01:02:39.709444000 +0600
@@ -660,7 +660,7 @@
 		kfree(z->msgbuf);
 		kfree(z);
 	} else {
-		if (z && z->span && z->span->name) {
+		if (z && z->span) {
 			printk(KERN_ERR "Cannot find interface for %s\n",
 				z->span->name);
 		}

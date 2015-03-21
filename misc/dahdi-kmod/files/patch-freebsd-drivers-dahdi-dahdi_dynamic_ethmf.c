--- freebsd/drivers/dahdi/dahdi_dynamic_ethmf.c.orig	2010-09-02 01:11:41.000000000 +0700
+++ freebsd/drivers/dahdi/dahdi_dynamic_ethmf.c	2015-03-22 00:52:55.655191000 +0600
@@ -689,7 +690,7 @@
 		kfree(z);
 		module_put(THIS_MODULE);
 	} else {
-		if (z && z->span && z->span->name) {
+		if (z && z->span) {
 			printk(KERN_ERR "Cannot find interface for %s\n",
 				z->span->name);
 		}

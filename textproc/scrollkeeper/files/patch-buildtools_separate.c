--- buildtools/separate.c.orig	Mon Jun 17 15:09:34 2002
+++ buildtools/separate.c	Mon Jun 17 15:09:27 2002
@@ -242,6 +242,7 @@
 					xmlUnlinkNode(w_node);
 					xmlFreeNode(w_node);
 				}
+				continue;
 			}
 			else {
 				if (strcmp(lang, "C")) {

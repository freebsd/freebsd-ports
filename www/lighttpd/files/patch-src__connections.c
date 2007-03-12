--- src/connections.c.orig	2007-01-05 10:56:08.000000000 -0800
+++ src/connections.c	2007-01-05 10:56:23.000000000 -0800
@@ -970,7 +970,7 @@
 								}
 							} else {
 								/* a splited \r \n */
-								return -1;
+								break;
 							}
 						}
 					}

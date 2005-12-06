--- pop2.c
+++ pop2.c
@@ -132,8 +132,8 @@
 static const struct method pop2 =
 {
     "POP2",				/* Post Office Protocol v2 */
-    109,				/* standard POP2 port */
-    109,				/* ssl POP2 port - not */
+    "pop2",				/* standard POP2 port */
+    "pop2",				/* ssl POP2 port - not */
     FALSE,				/* this is not a tagged protocol */
     FALSE,				/* does not use message delimiter */
     pop2_ok,				/* parse command response */

===================================================================
RCS file: /cvs/gnome/evolution/camel/Attic/camel-lock-helper.c,v
retrieving revision 1.5
retrieving revision 1.5.74.1
diff -u -r1.5 -r1.5.74.1
--- camel/camel-lock-helper.c	2001/10/27 16:59:27	1.5
+++ camel/camel-lock-helper.c	2005/01/20 07:28:44	1.5.74.1
@@ -360,8 +360,9 @@
 			switch(msg.id) {
 			case CAMEL_LOCK_HELPER_LOCK:
 				res = CAMEL_LOCK_HELPER_STATUS_NOMEM;
-				path = malloc(msg.data+1);
-				if (path != NULL) {
+				if (msg.data > 0xffff) {
+					res = CAMEL_LOCK_HELPER_STATUS_PROTOCOL;
+				} else if ((path = malloc(msg.data+1)) != NULL) {
 					res = CAMEL_LOCK_HELPER_STATUS_PROTOCOL;
 					len = read_n(STDIN_FILENO, path, msg.data);
 					if (len == msg.data) {

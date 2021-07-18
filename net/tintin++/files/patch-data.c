--- data.c.orig	2021-04-24 20:46:04 UTC
+++ data.c
@@ -27,6 +27,8 @@
 
 #include <limits.h>
 
+extern char **environ;
+
 struct listroot *init_list(struct session *ses, int type, int size)
 {
 	struct listroot *listhead;

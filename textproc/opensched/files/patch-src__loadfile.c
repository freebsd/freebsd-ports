--- src/loadfile.c.orig	Sat Oct 19 15:29:13 2002
+++ src/loadfile.c	Sat Oct 19 15:28:40 2002
@@ -268,6 +268,7 @@
     t = (TASK*)malloc(sizeof(TASK));
     if ( t == NULL )
 	Error("Can't malloc task in AddTask()");
+    memset(t, 0, sizeof(TASK));
     
     t->id = strdup(id);
     t->name = strdup(name);


$FreeBSD$

--- src/read-todos.c.orig	Mon Feb  2 23:09:47 2004
+++ src/read-todos.c	Mon Feb  2 23:10:22 2004
@@ -184,7 +184,7 @@
 		printf("Priority: %d\n", t.priority);
 		printf("Completed: %s\n", t.complete ? "Yes" : "No");
 		if (t.indefinite)
-			printf("Due: No Date");
+			printf("Due: No Date\n");
 		else
 			printf("Due: %s", asctime(&t.due));
 		if (t.description)

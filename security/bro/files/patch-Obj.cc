--- Obj.cc.orig	Sun Oct  5 18:27:31 2003
+++ Obj.cc	Sun Oct  5 18:27:44 2003
@@ -47,7 +47,7 @@
 	delete_data = true;
 
 	int tmp;
-	return s->Read(&(char*) filename, &tmp) &&
+	return s->Read((char**) &filename, &tmp) &&
 		s->Read(&first_line) && s->Read(&last_line) &&
 		s->Read(&first_column) && s->Read(&last_column);
 	}

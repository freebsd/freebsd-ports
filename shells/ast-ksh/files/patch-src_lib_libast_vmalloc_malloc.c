--- src/lib/libast/vmalloc/malloc.c.orig	2016-02-28 17:09:23 UTC
+++ src/lib/libast/vmalloc/malloc.c
@@ -906,7 +906,7 @@ union Alloca_u
 	{	char*		addr;
 		Alloca_t*	next;
 	} head;
-	char	array[ALIGN];
+	char	array[MEM_ALIGN];
 };
 struct Alloca_s
 {	union Alloca_u	head;
@@ -914,7 +914,7 @@ struct Alloca_s
 };
 
 extern Void_t* alloca(size_t size)
-{	char		array[ALIGN];
+{	char		array[MEM_ALIGN];
 	char*		file;
 	int		line;
 	Void_t*		func;

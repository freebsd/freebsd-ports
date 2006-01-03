--- src/memfunc.c.orig	Sat Dec  3 11:28:00 2005
+++ src/memfunc.c	Tue Jan  3 13:44:56 2006
@@ -575,8 +575,8 @@
 		    mem_type->name);
 
 	if ( (mem = malloc(size + MEM_DESC_BUF_OFFSET + sizeof(gbytes))) == NULL) {
-		logmsgx("mem_malloc(%lu + %u, %s) failed: malloc: %s",
-		    (u_long)size, MEM_DESC_BUF_OFFSET, mem_type->name,
+		logmsgx("mem_malloc(%lu + %lu, %s) failed: malloc: %s",
+		    (u_long)size, (u_long)MEM_DESC_BUF_OFFSET, mem_type->name,
 		    strerror(errno));
 		return NULL;
 	}
@@ -614,8 +614,8 @@
 
 	size *= number;
 	if ( (mem = malloc(size + MEM_DESC_BUF_OFFSET + sizeof(gbytes))) == NULL) {
-		logmsgx("mem_calloc(%lu + %u, %s) failed: %s",
-		    (u_long)size, MEM_DESC_BUF_OFFSET, mem_type->name,
+		logmsgx("mem_calloc(%lu + %lu, %s) failed: %s",
+		    (u_long)size, (u_long)MEM_DESC_BUF_OFFSET, mem_type->name,
 		    strerror(errno));
 		return NULL;
 	}
@@ -714,8 +714,8 @@
 #ifdef WITH_MEMFUNC_DEBUG
 	/* malloc() --> memcpy() --> free() */
 	if ( (mem2 = malloc(size2 + MEM_DESC_BUF_OFFSET + sizeof(gbytes))) == NULL) {
-		logmsgx("mem_realloc(%s): malloc(%lu + %u) failed: %s",
-		    mem_type->name, (u_long)size2, MEM_DESC_BUF_OFFSET,
+		logmsgx("mem_realloc(%s): malloc(%lu + %lu) failed: %s",
+		    mem_type->name, (u_long)size2, (u_long)MEM_DESC_BUF_OFFSET,
 		    strerror(errno));
 		return NULL;
 	}
@@ -733,8 +733,8 @@
 	/* True realloc(). */
 	mem1->signature = MEM_NOSIGNATURE;
 	if ( (mem2 = realloc(mem1, size2 + MEM_DESC_BUF_OFFSET + sizeof(gbytes))) == NULL) {
-		logmsgx("mem_realloc(%lu + %u, %s) failed: %s",
-		    (u_long)size2, MEM_DESC_BUF_OFFSET, mem_type->name,
+		logmsgx("mem_realloc(%lu + %lu, %s) failed: %s",
+		    (u_long)size2, (u_long)MEM_DESC_BUF_OFFSET, mem_type->name,
 		    strerror(errno));
 		mem1->signature = MEM_SIGNATURE & (int)size1;
 		return NULL;

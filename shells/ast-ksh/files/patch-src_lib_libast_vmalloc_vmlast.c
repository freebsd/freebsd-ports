--- src/lib/libast/vmalloc/vmlast.c.orig	2016-02-28 17:09:23 UTC
+++ src/lib/libast/vmalloc/vmlast.c
@@ -61,7 +61,7 @@ int		local;
 
 	LASTLOCK(last, local);
 
-	size = size < ALIGN ? ALIGN : ROUND(size,ALIGN);
+	size = size < MEM_ALIGN ? MEM_ALIGN : ROUND(size,MEM_ALIGN);
 
 	last->last = NIL(Vmuchar_t*); /* wipe record of last allocation */
 
@@ -119,7 +119,7 @@ int		local;
 	if(data != (Void_t*)last->last )
 		data = NIL(Void_t*);
 	else
-	{	size = last->data - last->last;	/**/DEBUG_ASSERT(size > 0 && size%ALIGN == 0);
+	{	size = last->data - last->last;	/**/DEBUG_ASSERT(size > 0 && size%MEM_ALIGN == 0);
 		last->data -= size;
 		last->size += size;
 		last->last = NIL(Vmuchar_t*);
@@ -166,8 +166,8 @@ int		local;
 	if(data != (Void_t*)last->last )
 		data = NIL(Void_t*);
 	else
-	{	oldz = last->data - last->last; /**/DEBUG_ASSERT(oldz > 0 && oldz%ALIGN == 0);
-		size = ROUND(size, ALIGN);
+	{	oldz = last->data - last->last; /**/DEBUG_ASSERT(oldz > 0 && oldz%MEM_ALIGN == 0);
+		size = ROUND(size, MEM_ALIGN);
 		if(size <= oldz) /* getting smaller */
 		{	sz = oldz - size;
 			last->data -= sz;
@@ -249,7 +249,7 @@ int		local;
 
 	LASTLOCK(last, local);
 
-	size = ROUND(size,ALIGN);
+	size = ROUND(size,MEM_ALIGN);
 	align = (*_Vmlcm)(align, 2*sizeof(Block_t));
 
 	if((data = (Vmuchar_t*)KPVALLOC(vm, size + align, lastalloc)) )

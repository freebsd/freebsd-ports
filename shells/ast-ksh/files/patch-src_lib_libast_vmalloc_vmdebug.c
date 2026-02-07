--- src/lib/libast/vmalloc/vmdebug.c.orig	2016-02-28 17:09:23 UTC
+++ src/lib/libast/vmalloc/vmdebug.c
@@ -335,7 +335,7 @@ int		local;
 	if(vm->data->mode&VM_DBCHECK)
 		vmdbcheck(vm);
 
-	sz = ROUND(size,ALIGN) + DB_EXTRA;
+	sz = ROUND(size,MEM_ALIGN) + DB_EXTRA;
 	sz = sz >= sizeof(Body_t) ? sz : sizeof(Body_t);
 	if(!(data = (Vmuchar_t*)KPVALLOC(vm, sz, (*(Vmbest->allocf))) ) )
 	{	dbwarn(vm, NIL(Vmuchar_t*), DB_ALLOC, file, line, func, DB_ALLOC);
@@ -483,7 +483,7 @@ int		local;
 	oldline = DBLINE(addr);
 
 	/* do the resize */
-	sz = ROUND(size,ALIGN) + DB_EXTRA;
+	sz = ROUND(size,MEM_ALIGN) + DB_EXTRA;
 	sz = sz >= sizeof(Body_t) ? sz : sizeof(Body_t);
 	data = (Vmuchar_t*)KPVRESIZE(vm, (Void_t*)data, sz, (type&~VM_RSZERO), (*(Vmbest->resizef)) );
 	if(!data) /* failed, reset data for old block */
@@ -632,7 +632,7 @@ int		local;
 
 	asolock(&vm->data->dlck, KEY_DEBUG, ASO_LOCK);
 
-	if((sz = ROUND(size,ALIGN) + DB_EXTRA) < sizeof(Body_t))
+	if((sz = ROUND(size,MEM_ALIGN) + DB_EXTRA) < sizeof(Body_t))
 		sz = sizeof(Body_t);
 
 	if((data = (Vmuchar_t*)KPVALIGN(vm, sz, align, (*(Vmbest->alignf)))) )

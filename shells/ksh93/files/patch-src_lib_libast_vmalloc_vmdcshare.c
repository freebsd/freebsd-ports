--- src/lib/libast/vmalloc/vmdcshare.c.orig	2016-02-28 17:09:23 UTC
+++ src/lib/libast/vmalloc/vmdcshare.c
@@ -61,7 +61,7 @@ void _STUB_vmdcshare(){}
 #define MM_REMOVE	02	/* remove files/segments	*/
 
 /* macros to get the data section and size */
-#define MMHEAD(name)	ROUND(sizeof(Mmvm_t)+strlen(name), ALIGN)
+#define MMHEAD(name)	ROUND(sizeof(Mmvm_t)+strlen(name), MEM_ALIGN)
 #define MMDATA(mmvm)	((Vmuchar_t*)(mmvm)->base + MMHEAD(mmvm->name))
 #define MMSIZE(mmvm)	((mmvm)->size - MMHEAD(mmvm->name))
 
@@ -178,7 +178,7 @@ static int mminit(Mmdisc_t* mmdc)
 	/* fixed size region so make it reasonably large */
 	if((size = mmdc->size) < MM_MINSIZE )
 		size =  MM_MINSIZE;
-	size += MMHEAD(mmdc->name) + ALIGN;
+	size += MMHEAD(mmdc->name) + MEM_ALIGN;
 	size  = ROUND(size, _Vmpagesize);
 
 	/* get/create the initial segment of data */

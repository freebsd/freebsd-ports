--- src/lib/libast/vmalloc/vmbest.c.orig
+++ src/lib/libast/vmalloc/vmbest.c
@@ -1169,6 +1169,7 @@
 }
 #endif /* _mem_win32 */
 
+#undef _mem_sbrk
 #if _mem_sbrk /* getting space via brk/sbrk - not concurrent-ready */
 static Void_t* sbrkmem(Void_t* caddr, size_t csize, size_t nsize)
 {
@@ -1265,10 +1266,13 @@
 		}
 	}
 	else if(nsize == 0)
-	{	Vmuchar_t	*addr = (Vmuchar_t*)sbrk(0);
+	{
+#if 0
+		Vmuchar_t	*addr = (Vmuchar_t*)sbrk(0);
 		if(addr < (Vmuchar_t*)caddr ) /* in sbrk space */
 			return NIL(Void_t*);
 		else
+#endif
 		{	(void)munmap(caddr, csize);
 			return caddr;
 		}

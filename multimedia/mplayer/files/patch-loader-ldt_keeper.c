--- loader/ldt_keeper.c.orig	Sun Nov 17 12:41:19 2002
+++ loader/ldt_keeper.c	Tue Sep  2 17:55:21 2003
@@ -88,11 +88,16 @@
 #define       LDT_SEL(idx) ((idx) << 3 | 1 << 2 | 3)
 
 /* i got this value from wine sources, it's the first free LDT entry */
+#if defined(__FreeBSD__) && defined(LDT_AUTO_ALLOC)
+#define       TEB_SEL_IDX     LDT_AUTO_ALLOC
+#endif
+
 #ifndef       TEB_SEL_IDX
 #define       TEB_SEL_IDX     17
 #endif
 
-#define       TEB_SEL LDT_SEL(TEB_SEL_IDX)
+static unsigned int fs_ldt = TEB_SEL_IDX;
+
 
 /**
  * here is a small logical problem with Restore for multithreaded programs -
@@ -104,8 +109,10 @@
 #endif
 void Setup_FS_Segment(void)
 {
+    unsigned int ldt_desc = LDT_SEL(fs_ldt);
+
     __asm__ __volatile__(
-	"movl %0,%%eax; movw %%ax, %%fs" : : "i" (TEB_SEL)
+	"movl %0,%%eax; movw %%ax, %%fs" : : "r" (ldt_desc)
     );
 }
 
@@ -211,7 +218,13 @@
         unsigned long d[2];
 
         LDT_EntryToBytes( d, &array );
+#if defined(__FreeBSD__) && defined(LDT_AUTO_ALLOC)
+        ret = i386_set_ldt(LDT_AUTO_ALLOC, (union descriptor *)d, 1);
+        array.entry_number = ret;
+        fs_ldt = ret;
+#else
         ret = i386_set_ldt(array.entry_number, (union descriptor *)d, 1);
+#endif
         if (ret < 0)
         {
             perror("install_fs");
@@ -224,7 +237,7 @@
 #if defined(__svr4__)
     {
 	struct ssd ssd;
-	ssd.sel = TEB_SEL;
+	ssd.sel = LDT_SEL(TEB_SEL_IDX);
 	ssd.bo = array.base_addr;
 	ssd.ls = array.limit - array.base_addr;
 	ssd.acc1 = ((array.read_exec_only == 0) << 1) |

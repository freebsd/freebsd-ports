--- src/libw32dll/wine/ldt_keeper.c.orig	Sat Oct 11 12:22:18 2003
+++ src/libw32dll/wine/ldt_keeper.c	Tue Dec  2 19:49:23 2003
@@ -138,7 +138,7 @@
 #define       TEB_SEL_IDX     1024
 #endif
 
-#define       TEB_SEL LDT_SEL(TEB_SEL_IDX)
+static unsigned int teb_sel = LDT_SEL(TEB_SEL_IDX);
 
 #ifdef __cplusplus
 extern "C"
@@ -146,7 +146,7 @@
 void Setup_FS_Segment(void)
 {
     __asm__ __volatile__(
-	"movl %0,%%eax; movw %%ax, %%fs" : : "i" (TEB_SEL) : "%eax"
+	"movl %0,%%eax; movw %%ax, %%fs" : : "r" (teb_sel) : "%eax"
     );
 }
 
@@ -158,7 +158,7 @@
     );
     fs = fs & 0xffff;
     
-    if( fs != TEB_SEL ) {
+    if( fs != teb_sel ) {
       printf("ldt_keeper: FS segment is not set or has being lost!\n");
       printf("            Please report this error to xine-devel@sourceforge.net\n");
       printf("            Aborting....\n");
@@ -230,7 +230,13 @@
         unsigned long d[2];
 
         LDT_EntryToBytes( d, &array );
+#if defined(__FreeBSD__) && defined(LDT_AUTO_ALLOC)
+        ret = i386_set_ldt(LDT_AUTO_ALLOC, (union descriptor *)d, 1);
+        array.entry_number = ret;
+        teb_sel = ret;
+#else
         ret = i386_set_ldt(array.entry_number, (union descriptor *)d, 1);
+#endif
         if (ret < 0)
         {
             perror("install_fs");
@@ -244,7 +250,7 @@
 #if defined(__svr4__)
     {
 	struct ssd ssd;
-	ssd.sel = TEB_SEL;
+	ssd.sel = teb_sel;
 	ssd.bo = array.base_addr;
 	ssd.ls = array.limit - array.base_addr;
 	ssd.acc1 = ((array.read_exec_only == 0) << 1) |

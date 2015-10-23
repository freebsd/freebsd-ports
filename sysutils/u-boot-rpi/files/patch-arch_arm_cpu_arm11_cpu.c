--- arch/arm/cpu/arm11/cpu.c.orig	2015-10-19 23:59:38 UTC
+++ arch/arm/cpu/arm11/cpu.c
@@ -52,6 +52,14 @@ static void cache_flush(void)
 	asm volatile("mcr p15, 0, %0, c7, c10, 4" : : "r" (i));
 }
 
+void invalidate_icache_all(void)
+{
+	/* invalidate entire icache and btb */
+	asm volatile("mcr p15, 0, %0, c7, c5, 0" : : "r" (0));
+	/* mem barrier to sync things */
+	asm volatile("mcr p15, 0, %0, c7, c10, 4" : : "r" (0));
+}
+
 #ifndef CONFIG_SYS_DCACHE_OFF
 
 #ifndef CONFIG_SYS_CACHELINE_SIZE

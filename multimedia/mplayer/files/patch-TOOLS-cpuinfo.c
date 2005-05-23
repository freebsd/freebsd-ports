--- TOOLS/cpuinfo.c.orig	Mon Oct 11 21:26:13 2004
+++ TOOLS/cpuinfo.c	Sun May 22 20:57:11 2005
@@ -40,13 +40,9 @@
 cpuid(int func) {
 	cpuid_regs_t regs;
 #define	CPUID	".byte 0x0f, 0xa2; "
-	asm("push %%ebx; "
-	    "movl %4,%%eax; " CPUID
-	    "movl %%eax,%0; movl %%ebx,%1; movl %%ecx,%2; movl %%edx,%3; "
-	    "pop %%ebx"
-		: "=m" (regs.eax), "=m" (regs.ebx), "=m" (regs.ecx), "=m" (regs.edx)
-		: "g" (func)
-		: "%eax", "%ecx", "%edx");
+	asm(CPUID
+		: "=a" (regs.eax), "=b" (regs.ebx), "=c" (regs.ecx), "=d" (regs.edx)
+		: "0" (func));
 	return regs;
 }
 

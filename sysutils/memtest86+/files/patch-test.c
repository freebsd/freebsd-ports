--- test.c.orig	2013-08-10 02:29:44 UTC
+++ test.c
@@ -14,7 +14,6 @@
 #include "stdint.h"
 #include "cpuid.h"
 #include "smp.h"
-#include <sys/io.h>
 
 extern struct cpu_ident cpu_id;
 extern volatile int    mstr_cpu;
@@ -1543,6 +1542,19 @@ void sleep(long n, int flag, int me, int
 	}
 }
 
+static inline unsigned char inb(unsigned int port)
+{
+        unsigned char data;
+
+        asm __volatile__("inb %1,%0" : "=a" (data) : "id" ((unsigned short)(port)));
+        return (data);
+}
+
+static inline void outb(unsigned int port, unsigned char data)
+{
+        asm __volatile__("outb %0,%1" : : "a" (data), "id" ((unsigned short)(port)));
+}
+
 /* Beep function */
 
 void beep(unsigned int frequency)
@@ -1551,18 +1563,18 @@ void beep(unsigned int frequency)
 	unsigned int count = 1193180 / frequency;
 
 	// Switch on the speaker
-	outb_p(inb_p(0x61)|3, 0x61);
+	outb(inb(0x61)|3, 0x61);
 
 	// Set command for counter 2, 2 byte write
-	outb_p(0xB6, 0x43);
+	outb(0xB6, 0x43);
 
 	// Select desired Hz
-	outb_p(count & 0xff, 0x42);
+	outb(count & 0xff, 0x42);
 	outb((count >> 8) & 0xff, 0x42);
 
 	// Block for 100 microseconds
 	sleep(100, 0, 0, 1);
 
 	// Switch off the speaker
-	outb(inb_p(0x61)&0xFC, 0x61);
+	outb(inb(0x61)&0xFC, 0x61);
 }

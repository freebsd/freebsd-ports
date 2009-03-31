--- test.c	2008-11-16 02:18:14.000000000 +0200
+++ test.c	2009-02-18 00:27:11.000000000 +0200
@@ -6,12 +6,11 @@
  * ----------------------------------------------------
  * MemTest86+ V2.01 Specific code (GPL V2.0)
  * By Samuel DEMEULEMEESTER, sdemeule@memtest.org
  * http://www.canardpc.com - http://www.memtest.org
  */
 
-#include "test.h"
 #include "config.h"
-#include <sys/io.h>
+#include "test.h"
 #include "dmi.h"
 
 extern int segs, bail;
@@ -1400,6 +1399,20 @@ void sleep(int n, int sms)
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
+
 /* Beep function */
 
 void beep(unsigned int frequency)
@@ -1407,18 +1420,18 @@ void beep(unsigned int frequency)
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
 	sleep(100, 1);
 
 	// Switch off the speaker
-	outb(inb_p(0x61)&0xFC, 0x61);
+	outb(inb(0x61)&0xFC, 0x61);
 }

--- rovclock.c.orig	2006-01-04 21:23:32 UTC
+++ rovclock.c
@@ -20,11 +20,16 @@
  */
  /*****************************************************************************/
 
+#include <fcntl.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <getopt.h>
-#include <sys/io.h>
+#include <sys/types.h>
+#if !defined(__amd64__) && !defined(__i386__)
+#include <machine/pio.h>
+#endif
+#include <machine/cpufunc.h>
 #include <sys/mman.h>
 
 #include "pci.h"
@@ -122,18 +127,18 @@ struct rovclock_data {
 /* PCI read/write functions */
 unsigned int pci_read(u8 bus, u8 device, u8 func, u8 addr)
 {
-	outl(0x80000000 | (bus << 16) | 
+	outl(0xcf8, 0x80000000 | (bus << 16) | 
 		 (PCI_DEVFN(device, func) << 8) |
-		 (addr & ~3), 0xcf8);
+		 (addr & ~3));
 	return inl(0xcfc);
 }
 
 void pci_write(u8 bus, u8 device, u8 func, u8 addr, u32 data)
 {
-	outl(0x80000000 | (bus << 16) | 
+	outl(0xcf8, 0x80000000 | (bus << 16) | 
 		 (PCI_DEVFN(device, func) << 8) |
-		 (addr & ~3), 0xcf8);
-	outl(data, 0xcfc);
+		 (addr & ~3));
+	outl(0xcfc, data);
 }
 
 /* Register read/write functions */
@@ -144,38 +149,38 @@ u32 reg_read(struct rovclock_data *rovclock, u32 addr)
 
 void reg_write(struct rovclock_data *rovclock, u32 addr, u32 data)
 {
-	outl(data, rovclock->iobase + addr);
+	outl(rovclock->iobase + addr, data);
 }
 
 /* PLL read/write functions */
 u32 pll_read(struct rovclock_data *rovclock, u32 addr)
 {
-	outb(addr & 0x0000003f, rovclock->iobase + CLOCK_CNTL_INDEX);
+	outb(rovclock->iobase + CLOCK_CNTL_INDEX, addr & 0x0000003f);
 	return inl(rovclock->iobase + CLOCK_CNTL_DATA);
 }
 
 void pll_write(struct rovclock_data *rovclock, u32 addr, u32 data)
 {
-	outb((addr & 0x3f) | PLL_WR_EN, rovclock->iobase + CLOCK_CNTL_INDEX);
-	outl(data, rovclock->iobase + CLOCK_CNTL_DATA);
+	outb(rovclock->iobase + CLOCK_CNTL_INDEX, (addr & 0x3f) | PLL_WR_EN);
+	outl(rovclock->iobase + CLOCK_CNTL_DATA, data);
 }
 
 /* MM read/write functions */
 u32 mm_read(struct rovclock_data *rovclock, u32 addr)
 {
-	outl(addr, rovclock->iobase + MM_INDEX);
+	outl(rovclock->iobase + MM_INDEX, addr);
 	return inl(rovclock->iobase + MM_DATA);
 }
 
 void mm_write(struct rovclock_data *rovclock, u32 addr, u32 data)
 {
-	outl(addr, rovclock->iobase + MM_INDEX);
-	outl(data, rovclock->iobase + MM_DATA);
+	outl(rovclock->iobase + MM_INDEX, addr);
+	outl(rovclock->iobase + MM_DATA, data);
 }
 
 int round_div(int num, int den)
 {
-    return (num + (den / 2)) / den;
+    return den ? (num + (den / 2)) / den : 0;
 }
 
 /* Print usage */
@@ -281,10 +286,11 @@ void pll_set_freq(struct rovclock_data *rovclock)
 /* Search for ATI card on PCI bus */
 int find_card(struct rovclock_data *rovclock)
 {
+	u32 id;
+#if 0
 	FILE *proc;
 	char temp;
-	u32 id;
-	
+
 	/* Check /proc/bus/pci/devices first */
 	if ((proc = fopen("/proc/bus/pci/devices", "r")) != NULL) {
 		while (fscanf(proc, "%x\t%x", &rovclock->pci_bus, &id) == 2) {
@@ -305,8 +311,9 @@ int find_card(struct rovclock_data *rovclock)
 					break;
 		}
 	}
+#endif
 	if ((rovclock->pci_id & 0xffff) != PCI_VENDOR_ID_ATI) {
-		fprintf(stderr, "Search in /proc/bus/pci/devices failed, scanning the PCI bus.\n");
+		fprintf(stderr, "Scanning the PCI bus.\n");
 
 		/* Find card by scanning the PCI devices, check from bus 1 to 9 for ATI device */
 		rovclock->pci_dev = 0;
@@ -423,7 +430,7 @@ int main(int argc, char **argv)
 	}
 	
 	/* Get I/O permission */
-	if (iopl(3) != 0) {
+	if (open("/dev/io", O_RDONLY) < 0) {
 		fprintf(stderr, "Error getting I/O permissions (root?).\n");
 		return 1;
 	}

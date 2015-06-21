--- pci_pm.h.orig	2004-07-14 15:02:49 UTC
+++ pci_pm.h
@@ -32,10 +32,10 @@
 #define getSMBBA0	0x90	/* PIIX4, VIA596,686 */
 #define getSMBBA1	0xD0	/* VT8233/A/C */
 #define getSMBBA2	0x20	/* Intel801_ICH's */
-#define getSMBBA3	0x58	/* AMD756,766,768 */
+#define getSMBBA3	0x58	/* AMD756,766,768,8111 */
 #define getSMBBA4	0x14	/* NVidia nForce */
 #define getSMBBA5	0xE2	/* ALI7101 */
-#define getSMBBA6	0x10	/* AMD8111 */
+#define getSMBBA6	0x10	/* AMD8111 SMBus 2.0 */
 #define getSMBBA70	0x50	/* NVidia nForce2, bus0 */
 #define getSMBBA71	0x54	/* NVidia nForce2, bus1 */
 
@@ -63,12 +63,14 @@
 #define ID_I801CA	0x24838086
 #define ID_I801DB	0x24C38086
 #define ID_I801EB	0x24D38086
+#define ID_I801IB	0x29308086
 #define ID_I6300ESB	0x25A48086
 #define ID_IICH6	0x266A8086
 #define ID_AMD756	0x740B1022
 #define ID_AMD766	0x74131022
 #define ID_AMD768	0x74431022
-#define ID_AMD8111	0x746A1022
+#define ID_AMD8111_1	0x746B1022
+#define ID_AMD8111_2	0x746A1022
 #define ID_NFORCE	0x01B410DE
 #define ID_NFORCE2	0x006410DE
 #define ID_ALI7101	0x710110B9

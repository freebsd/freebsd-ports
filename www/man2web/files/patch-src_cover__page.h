
$FreeBSD$

--- src/cover_page.h.orig	Sat Apr 19 13:56:03 2003
+++ src/cover_page.h	Sat Apr 19 13:58:38 2003
@@ -8,15 +8,16 @@
 char *find_section(struct section_entry **node, char *pseudo);
 
 /* default section entries that are used if configuration file is disabled*/
-#define SECTION_COUNT 8
+#define SECTION_COUNT 9
 struct section_entry section_matrix[] = {
-        { "1", "1",	"User Commands" },
-        { "2", "2",     "System Calls" },
-        { "3", "3",     "Library Functions" },
-        { "4", "4",     "Device Drivers & Files" },
+        { "1", "1",	"General Commands (Tools and Utilities)" },
+        { "2", "2",     "System Calls and Error Numbers" },
+        { "3", "3",     "C Libraries" },
+        { "4", "4",     "Devices and Device Drivers" },
         { "5", "5",     "File Formats" },
-        { "6", "6",     "Games and Demos" },
-        { "7", "7",     "Conventions & Miscellany" },
-        { "8", "8",     "System Administration Commands" }
+        { "6", "6",     "Games" },
+        { "7", "7",     "Miscellaneous Information Pages" },
+        { "8", "8",     "System Maintenance and Operation Commands" },
+        { "9", "9",     "Kernel Interfaces" }
 };
 

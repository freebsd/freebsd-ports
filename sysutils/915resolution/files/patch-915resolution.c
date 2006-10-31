--- 915resolution.c.orig	Fri Feb  3 01:28:34 2006
+++ 915resolution.c	Sun Oct 15 20:39:56 2006
@@ -21,8 +21,10 @@
 #define __USE_GNU
 #include <string.h>
 #include <sys/mman.h>
+#include <machine/cpufunc.h>
+#define OUTB(a, b) outb(b, a)
+#define OUTL(a, b) outl(b, a)
 #include <fcntl.h>
-#include <sys/io.h>
 #include <unistd.h>
 #include <assert.h>
 
@@ -161,7 +163,8 @@
 void initialize_system(char * filename) {
 
     if (!filename) {
-        if (iopl(3) < 0) {
+        FILE* iof = fopen("/dev/io", "r");
+        if (iof == NULL) {
             perror("Unable to obtain the proper IO permissions");
             exit(2);
         }
@@ -169,7 +172,7 @@
 }
 
 cardinal get_chipset_id(void) {
-    outl(0x80000000, 0xcf8);
+    OUTL(0x80000000, 0xcf8);
     return inl(0xcfc);
 }
 
@@ -476,11 +479,11 @@
         case CT_UNKWN:
             break;
         case CT_855GM:
-            outl(0x8000005a, 0xcf8);
+            OUTL(0x8000005a, 0xcf8);
             map->b1 = inb(0xcfe);
             
-            outl(0x8000005a, 0xcf8);
-            outb(0x33, 0xcfe);
+            OUTL(0x8000005a, 0xcf8);
+            OUTB(0x33, 0xcfe);
             break;
         case CT_845G:
         case CT_865G:
@@ -488,13 +491,13 @@
         case CT_915GM:
         case CT_945G:
         case CT_945GM:
-            outl(0x80000090, 0xcf8);
+            OUTL(0x80000090, 0xcf8);
             map->b1 = inb(0xcfd);
             map->b2 = inb(0xcfe);
             
-            outl(0x80000090, 0xcf8);
-            outb(0x33, 0xcfd);
-            outb(0x33, 0xcfe);
+            OUTL(0x80000090, 0xcf8);
+            OUTB(0x33, 0xcfd);
+            OUTB(0x33, 0xcfe);
             break;
         }
     }
@@ -526,8 +529,8 @@
         case CT_UNKWN:
             break;
         case CT_855GM:
-            outl(0x8000005a, 0xcf8);
-            outb(map->b1, 0xcfe);
+            OUTL(0x8000005a, 0xcf8);
+            OUTB(map->b1, 0xcfe);
             break;
         case CT_845G:
         case CT_865G:
@@ -535,9 +538,9 @@
         case CT_915GM:
         case CT_945G:
         case CT_945GM:
-            outl(0x80000090, 0xcf8);
-            outb(map->b1, 0xcfd);
-            outb(map->b2, 0xcfe);
+            OUTL(0x80000090, 0xcf8);
+            OUTB(map->b1, 0xcfd);
+            OUTB(map->b2, 0xcfe);
             break;
         }
     }

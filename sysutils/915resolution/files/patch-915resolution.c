--- 915resolution.c.orig	2007-04-15 10:46:56 UTC
+++ 915resolution.c
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
 
@@ -165,7 +167,8 @@ typedef struct {
 void initialize_system(char * filename) {
 
     if (!filename) {
-        if (iopl(3) < 0) {
+        FILE* iof = fopen("/dev/io", "r");
+        if (iof == NULL) {
             perror("Unable to obtain the proper IO permissions");
             exit(2);
         }
@@ -173,7 +176,7 @@ void initialize_system(char * filename) 
 }
 
 cardinal get_chipset_id(void) {
-    outl(0x80000000, 0xcf8);
+    OUTL(0x80000000, 0xcf8);
     return inl(0xcfc);
 }
 
@@ -496,11 +499,11 @@ void unlock_vbios(vbios_map * map) {
         break;
     case CT_830:
     case CT_855GM:
-        outl(0x8000005a, 0xcf8);
+        OUTL(0x8000005a, 0xcf8);
         map->b1 = inb(0xcfe);
         
-        outl(0x8000005a, 0xcf8);
-        outb(0x33, 0xcfe);
+        OUTL(0x8000005a, 0xcf8);
+        OUTB(0x33, 0xcfe);
         break;
     case CT_845G:
     case CT_865G:
@@ -511,13 +514,13 @@ void unlock_vbios(vbios_map * map) {
     case CT_946GZ:
     case CT_G965:
     case CT_Q965:
-        outl(0x80000090, 0xcf8);
+        OUTL(0x80000090, 0xcf8);
         map->b1 = inb(0xcfd);
         map->b2 = inb(0xcfe);
         
-        outl(0x80000090, 0xcf8);
-        outb(0x33, 0xcfd);
-        outb(0x33, 0xcfe);
+        OUTL(0x80000090, 0xcf8);
+        OUTB(0x33, 0xcfd);
+        OUTB(0x33, 0xcfe);
         break;
     }
 
@@ -539,8 +542,8 @@ void relock_vbios(vbios_map * map) {
         break;
     case CT_830:
     case CT_855GM:
-        outl(0x8000005a, 0xcf8);
-        outb(map->b1, 0xcfe);
+        OUTL(0x8000005a, 0xcf8);
+        OUTB(map->b1, 0xcfe);
         break;
     case CT_845G:
     case CT_865G:
@@ -551,9 +554,9 @@ void relock_vbios(vbios_map * map) {
     case CT_946GZ:
     case CT_G965:
     case CT_Q965:
-        outl(0x80000090, 0xcf8);
-        outb(map->b1, 0xcfd);
-        outb(map->b2, 0xcfe);
+        OUTL(0x80000090, 0xcf8);
+        OUTB(map->b1, 0xcfd);
+        OUTB(map->b2, 0xcfe);
         break;
     }
 

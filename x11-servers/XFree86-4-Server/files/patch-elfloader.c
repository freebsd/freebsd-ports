--- programs/Xserver/hw/xfree86/loader/elfloader.c.orig	Mon Mar 28 19:12:53 2005
+++ programs/Xserver/hw/xfree86/loader/elfloader.c	Mon Mar 28 19:22:51 2005
@@ -203,6 +203,7 @@
 #if defined (__alpha__) || \
     defined (__ia64__) || \
     defined (__AMD64__) || \
+    defined (__amd64__) || \
     (defined (__sparc__) && \
      (defined (__arch64__) || \
       defined (__sparcv9)))
@@ -294,7 +295,8 @@
     defined(__alpha__) || \
     defined(__sparc__) || \
     defined(__ia64__) || \
-    defined(__AMD64__)
+    defined(__AMD64__) || \
+    defined(__amd64__)
 typedef Elf_Rela Elf_Rel_t;
 #else
 typedef Elf_Rel Elf_Rel_t;
@@ -488,7 +490,8 @@
     defined(__alpha__) || \
     defined(__sparc__) || \
     defined(__ia64__) || \
-    defined(__AMD64__)
+    defined(__AMD64__) || \
+    defined(__amd64__)
     ELFDEBUG(", r_addend 0x%lx", rel->r_addend);
 # endif
     ELFDEBUG("\n");
@@ -524,6 +527,7 @@
 #if defined(__alpha__) || \
     defined(__ia64__) || \
     defined(__AMD64__) || \
+    defined(__amd64__) || \
     (defined(__sparc__) && \
      (defined(__arch64__) || \
       defined(__sparcv9)))
@@ -548,6 +552,7 @@
 #if defined(__alpha__) || \
     defined(__ia64__) || \
     defined(__AMD64__) || \
+    defined(__amd64__) || \
     (defined(__sparc__) && \
      (defined(__arch64__) || \
       defined(__sparcv9)))
@@ -603,6 +608,7 @@
 #if defined(__alpha__) || \
     defined(__ia64__) || \
     defined(__AMD64__) || \
+    defined(__amd64__) || \
     (defined(__sparc__) && \
      (defined(__arch64__) || \
       defined(__sparcv9)))
@@ -1263,7 +1269,7 @@
     unsigned long *dest64;
     unsigned short *dest16;
 #endif
-#if  defined(__AMD64__)
+#if  defined(__AMD64__) || defined(__amd64__)
     unsigned long *dest64;
     int *dest32s;
 #endif
@@ -1281,7 +1287,8 @@
     defined(__alpha__) || \
     defined(__sparc__) || \
     defined(__ia64__) || \
-    defined(__AMD64__)
+    defined(__AMD64__) || \
+    defined(__amd64__)
     ELFDEBUG("%lx", rel->r_addend);
 # endif
     ELFDEBUG("\n");
@@ -1340,7 +1347,7 @@
 
 	break;
 #endif /* i386 */
-#if defined(__AMD64__)
+#if defined(__AMD64__) || defined(__amd64__)
     case R_X86_64_32:
 	dest32 = (unsigned int *)(secp + rel->r_offset);
 # ifdef ELFDEBUG

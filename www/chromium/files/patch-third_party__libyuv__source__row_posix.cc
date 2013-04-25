--- third_party/libyuv/source/row_posix.cc.orig	2013-04-25 16:12:41.000000000 +0200
+++ third_party/libyuv/source/row_posix.cc	2013-04-25 16:18:34.000000000 +0200
@@ -1805,7 +1805,7 @@
                                  uint8* dst_rgb24,
                                  int width) {
 // fpic 32 bit gcc 4.2 on OSX runs out of GPR regs.
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__llvm__)
   asm volatile (
     "movdqa    %[kShuffleMaskARGBToRGB24_0],%%xmm5 \n"
     "movdqa    %[kShuffleMaskARGBToRGB24],%%xmm6   \n"
@@ -1814,7 +1814,7 @@
 #endif
 
   asm volatile (
-#ifndef __APPLE__
+#if !(defined(__APPLE__) || defined(__llvm__))
     "movdqa    %[kShuffleMaskARGBToRGB24_0],%%xmm5 \n"
     "movdqa    %[kShuffleMaskARGBToRGB24],%%xmm6   \n"
 #endif
@@ -1843,7 +1843,7 @@
     [dst_rgb24]"+r"(dst_rgb24),  // %[dst_rgb24]
     [width]"+rm"(width)    // %[width]
   : [kYuvConstants]"r"(&kYuvConstants.kUVToB)
-#ifndef __APPLE__
+#if !(defined(__APPLE__) || defined(__llvm__))
     , [kShuffleMaskARGBToRGB24_0]"m"(kShuffleMaskARGBToRGB24_0),
     [kShuffleMaskARGBToRGB24]"m"(kShuffleMaskARGBToRGB24)
 #endif
@@ -1860,7 +1860,7 @@
                                uint8* dst_raw,
                                int width) {
 // fpic 32 bit gcc 4.2 on OSX runs out of GPR regs.
-#ifdef __APPLE__
+#if defined(__APPLE__) || defined(__llvm__)
   asm volatile (
     "movdqa    %[kShuffleMaskARGBToRAW_0],%%xmm5 \n"
     "movdqa    %[kShuffleMaskARGBToRAW],%%xmm6   \n"
@@ -1869,7 +1869,7 @@
 #endif
 
   asm volatile (
-#ifndef __APPLE__
+#if !(defined(__APPLE__) || defined(__llvm__))
     "movdqa    %[kShuffleMaskARGBToRAW_0],%%xmm5 \n"
     "movdqa    %[kShuffleMaskARGBToRAW],%%xmm6   \n"
 #endif
@@ -1898,7 +1898,7 @@
     [dst_raw]"+r"(dst_raw),  // %[dst_raw]
     [width]"+rm"(width)    // %[width]
   : [kYuvConstants]"r"(&kYuvConstants.kUVToB)
-#ifndef __APPLE__
+#if !(defined(__APPLE__) || defined(__llvm__))
     , [kShuffleMaskARGBToRAW_0]"m"(kShuffleMaskARGBToRAW_0),
     [kShuffleMaskARGBToRAW]"m"(kShuffleMaskARGBToRAW)
 #endif

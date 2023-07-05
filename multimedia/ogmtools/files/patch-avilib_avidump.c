--- avilib/avidump.c.orig	2004-11-02 15:30:16 UTC
+++ avilib/avidump.c
@@ -54,7 +54,7 @@
                    ((x<<8)  & 0x00ff0000) |\
                    ((x<<24) & 0xff000000))
 # define SWAP8(x) (((SWAP4(x)<<32) & 0xffffffff00000000ULL) |\
-                   (SWAP4(x)))
+                   SWAP4(x))
 #else
 # define SWAP2(a) (a)
 # define SWAP4(a) (a)

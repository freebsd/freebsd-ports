--- readTSC.C.orig	2019-02-27 09:30:27 UTC
+++ readTSC.C
@@ -19,10 +19,22 @@
 long long readTSC(void)
 {
   union { long long complete; unsigned int part[2]; } ticks;
+#ifdef __amd64__
   __asm__ ("rdtsc; mov %%eax,%0;mov %%edx,%1"
             : "=mr" (ticks.part[0]),
               "=mr" (ticks.part[1])
             : /* no inputs */
             : "eax", "edx");
+#elif __powerpc__
+  unsigned int tmp;
+  __asm__ ("0:"
+            "mftbu %[hi32]\n"
+            "mftb %[lo32]\n"
+            "mftbu %[tmp]\n"
+            "cmpw %[tmp],%[hi32]\n"
+            "bne 0b\n"
+            : [hi32] "=r"(ticks.part[0]), [lo32] "=r"(ticks.part[1]),
+            [tmp] "=r"(tmp));
+#endif
   return ticks.complete;
 }

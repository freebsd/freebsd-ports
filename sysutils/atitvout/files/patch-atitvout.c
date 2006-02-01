--- atitvout.c	Tue Sep 17 02:37:08 2002
+++ ./atitvout.c	Sun Sep 12 00:42:56 2004
@@ -17,10 +17,14 @@
  */
 
 #include <stdio.h>
-#include <sys/io.h>
 #include <string.h>
 #include <assert.h>
 
+#if defined(__linux__)
+#include <sys/io.h>
+#elif defined(__NetBSD__) || defined(__FreeBSD__)
+#include <machine/sysarch.h>
+#endif
 
 #include <lrmi.h>
 #include <vbe.h>
@@ -92,14 +96,24 @@
     char **c = argv+1;
     char oem[256];
     int vh, vl;
+#if defined(__NetBSD__)
+    unsigned long iomap[32];
+#endif
 
     if (argc <= 1) {
         help(argv[0]);
         return 0;
     }
     
+#if defined(__linux__)
     ioperm(0, 1024, 1);
     iopl(3);
+#elif defined(__NetBSD__)
+	memset(&iomap[0], 0xff, sizeof(iomap));
+	i386_set_ioperm(iomap);
+#elif defined(__FreeBSD__)
+	i386_set_ioperm(0, 0x10000, 1);
+#endif
 
     if (!LRMI_init()) {
         fprintf(stderr, "Could not initialise LRMI.\n");
@@ -118,6 +132,8 @@
     } else {
         if (strncmp(oem, "ATI MACH64", 10) == 0)
             radeon = 0;
+		else if (strcmp(oem, "ATI MOBILITY RADEON 9000") == 0)
+			radeon = 0;
         else if (strncmp(oem, "ATI RAGE128", 11) == 0)
             radeon = 1;
         /* Note: Also it's possible to have here 'RG6' for first radeons */

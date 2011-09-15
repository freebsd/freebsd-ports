--- AMD/powernow.c.orig	2011-09-15 15:43:33.000000000 -0700
+++ AMD/powernow.c	2011-09-15 15:43:40.000000000 -0700
@@ -9,8 +9,9 @@
 #include <stdio.h>
 #include <unistd.h>
 #include <sys/types.h>
-#include <pci/pci.h>
 #include "../x86info.h"
+#define	PCI_HAVE_Uxx_TYPES
+#include <pci/pci.h>
 #include "AMD.h"
 #include "powernow.h"
 

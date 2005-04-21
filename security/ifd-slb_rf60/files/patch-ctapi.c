--- ctapi.c.bak	Fri Feb 20 05:40:24 2004
+++ ctapi.c	Fri Feb 20 12:32:47 2004
@@ -29,7 +29,7 @@
     #endif
 
     #ifndef SUN_SPARC
-     BretVal = IO_InitializePort(9600,8,'E',"/dev/ttyS0");
+     BretVal = IO_InitializePort(9600,8,'E',"/dev/cuad0");
     #endif
 
     break;
@@ -41,7 +41,7 @@
     #endif
 
     #ifndef SUN_SPARC
-     BretVal = IO_InitializePort(9600,8,'E',"/dev/ttyS1");
+     BretVal = IO_InitializePort(9600,8,'E',"/dev/cuad1");
     #endif
 
     break;
@@ -53,7 +53,7 @@
     #endif
 
     #ifndef SUN_SPARC
-     BretVal = IO_InitializePort(9600,8,'E',"/dev/ttyS2");
+     BretVal = IO_InitializePort(9600,8,'E',"/dev/cuad2");
     #endif
 
     break;
@@ -65,7 +65,7 @@
     #endif
 
     #ifndef SUN_SPARC
-     BretVal = IO_InitializePort(9600,8,'E',"/dev/ttyS3");
+     BretVal = IO_InitializePort(9600,8,'E',"/dev/cuad3");
     #endif
 
     break;

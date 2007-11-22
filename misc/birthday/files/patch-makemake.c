--- makemake.c.orig	2007-11-22 16:13:14.000000000 +0100
+++ makemake.c	2007-11-22 16:13:25.000000000 +0100
@@ -17,7 +17,7 @@
   { "UNIX", "ifeq (", ",", ")", "else", "endif" }
 };
 
-main(int argc, char *argv[])
+int main(int argc, char *argv[])
 {
   enum {DOS=0,UNIX=1} os;
   char buf[256];
@@ -51,6 +51,8 @@
     } else
       printf("%s", buf);
   }
+
+  return (0);
 }
 
     

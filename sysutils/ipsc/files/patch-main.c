--- main.c.orig	Sun Sep 19 13:58:16 2004
+++ main.c	Sun Sep 19 13:58:51 2004
@@ -142,18 +142,18 @@
 
 void usage(const char *prog)
 {
-        fprintf(stderr, "usage: %s [options] <addr/mask | addr/offset | addr>
-        -C <class>      Network class (a, b, or c).  Must be used with -B
-	-B <bits>	Subnet bits (must be used with -C)
-        -i <if>		Reverse engineer an interface (e.g. eth0)
-	-a		Print all information available
-	-g		Print general information
-        -s 		Print all possible subnets
-	-h		Print host information
-	-c		Print CIDR information
-        -v		Print the program version
-        -?		Print this help message
-
+        fprintf(stderr, "usage: %s [options] <addr/mask | addr/offset | addr>\n\
+        -C <class>      Network class (a, b, or c).  Must be used with -B\n\
+	-B <bits>	Subnet bits (must be used with -C)\n\
+        -i <if>		Reverse engineer an interface (e.g. eth0)\n\
+	-a		Print all information available\n\
+	-g		Print general information\n\
+        -s 		Print all possible subnets\n\
+	-h		Print host information\n\
+	-c		Print CIDR information\n\
+        -v		Print the program version\n\
+        -?		Print this help message\n\
+\n\
         \rReport bugs to %s\n",
                         prog, MAINTAINER);
 }

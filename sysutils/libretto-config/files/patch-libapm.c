
$FreeBSD$

--- libapm.c.orig	Fri Jun 19 02:28:23 1998
+++ libapm.c	Sun Aug 22 23:31:55 2004
@@ -8,12 +8,19 @@
 /*                                                         */
 /***********************************************************/
 
+#undef HAVE_GETOPT_LONG
+#ifdef __linux__
+#define HAVE_GETOPT_LONG 1
+#endif
+
 #include <stdio.h>
 #include <stdlib.h>
 #include <sys/types.h>
 #include <string.h>
 #include <ctype.h>
+#ifdef HAVE_GETOPT_LONG
 #include <getopt.h>
+#endif
 #include <fcntl.h>
 #include <unistd.h>
 #include <sys/mman.h>
@@ -63,6 +70,7 @@
     int r;
     char c;
 
+#ifdef HAVE_GETOPT_LONG
     struct option longopts[] = {
       { "Help",        0, 0, 'h' },
       { "Version",     0, 0, 'v' },
@@ -78,6 +86,7 @@
 #endif /* CMOS_ACCESS */
       {0, 0, 0, 0}
     };
+#endif
 
     if( 0 != geteuid() ){
         printf("%s: Only root can execute !!\n", argv[0]);
@@ -98,8 +107,12 @@
 
     get_status();
 
+#ifdef HAVE_GETOPT_LONG
     while ((c = getopt_long(argc,argv,
                             "hvP:T:a:S:A:L:V:O:", longopts, NULL)) != -1) {
+#else
+    while ((c = getopt(argc,argv, "hvP:T:a:S:A:L:V:O:")) != -1) {
+#endif
       switch (c) {
         case 'h':
           usage();
@@ -189,7 +202,7 @@
         case '?':
           usage();
           break;
-        default:
+        default: break;
       }
     }
 #ifdef DEBUG
@@ -215,29 +228,60 @@
 void usage(void)
 {
 #ifdef CMOS_ACCESS
-    printf("
-usage: libapm [-v --Version]
-              [-h --Help]
-              [-P --PowerUp {boot,hibernation}]
-              [-T --StandbyTime {0,5,10,15,30,45,60,unlimit}]
-              [-a --AutoOff {disable,10,20,30,40,50,60}]
-              [-S --PanelSwitch {disable,enable}]
-              [-A --AlarmOn {disable,<time>}]
-              [-L --LcdPower {0,1,2,3}]
+# ifdef HAVE_GETOPT_LONG
+    printf("\n\
+usage: libretto-config [-v --Version]\n\
+              [-h --Help]\n\
+              [-P --PowerUp {boot,hibernation}]\n\
+              [-T --StandbyTime {0,5,10,15,30,45,60,unlimit}]\n\
+              [-a --AutoOff {disable,10,20,30,40,50,60}]\n\
+              [-S --PanelSwitch {disable,enable}]\n\
+              [-A --AlarmOn {disable,<time>}]\n\
+              [-L --LcdPower {0,1,2,3}]\n\
           \n");
-#else
-    printf("
-usage: libapm [-v --Version]
-              [-h --Help]
-              [-P --PowerUp {boot,hibernation}]
-              [-T --StandbyTime {0,5,10,15,30,45,60,unlimit}]
-              [-a --AutoOff {disable,10,20,30,40,50,60}]
-              [-S --PanelSwitch {disable,enable}]
-              [-A --AlarmOn {disable,<time>}]
-              [-L --LcdPower {0,1,2,3}]
-              [-V --Volume {0,1,2,3}]
-              [-O --Off {suspend|hibernation}  Use Only >= Libretto100]
+# else /* not HAVE_GETOPT_LONG */
+    printf("\n\
+usage: libretto-config [-v			: Version]\n\
+              [-h				: Help]\n\
+              [-P {boot,hibernation}		: PowerUp]\n\
+              [-T {0,5,10,15,30,45,60,unlimit}	: StandbyTime]\n\
+              [-a {disable,10,20,30,40,50,60}	: AutoOff]\n\
+              [-S {disable,enable}		: PanelSwitch]\n\
+              [-A {disable,<time>}		: AlarmOn]\n\
+              [-L {0,1,2,3}			: LcdPower]\n\
+          \n");
+# endif /* HAVE_GETOPT_LONG */
+
+#else /* not CMOS_ACCESS */
+
+# ifdef HAVE_GETOPT_LONG
+    printf("\
+usage: libretto-config [-v --Version]\n\
+              [-h --Help]\n\
+              [-P --PowerUp {boot,hibernation}]\n\
+              [-T --StandbyTime {0,5,10,15,30,45,60,unlimit}]\n\
+              [-a --AutoOff {disable,10,20,30,40,50,60}]\n\
+              [-S --PanelSwitch {disable,enable}]\n\
+              [-A --AlarmOn {disable,<time>}]\n\
+              [-L --LcdPower {0,1,2,3}]\n\
+              [-V --Volume {0,1,2,3}]\n\
+              [-O --Off {suspend|hibernation}  Use Only >= Libretto100]\n\
           \n");
+# else /* not HAVE_GETOPT_LONG */
+    printf("\
+usage: libretto-config [-v			: Version]\n\
+              [-h				: Help]\n\
+              [-P {boot,hibernation}		: PowerUp]\n\
+              [-T {0,5,10,15,30,45,60,unlimit}	: StandbyTime]\n\
+              [-a {disable,10,20,30,40,50,60}	: AutoOff]\n\
+              [-S {disable,enable}		: PanelSwitch]\n\
+              [-A {disable,<time>}		: AlarmOn]\n\
+              [-L {0,1,2,3}			: LcdPower]\n\
+              [-V {0,1,2,3}			: Volume]\n\
+              [-O {suspend|hibernation}		: Off (Use Only>=Libretto100)]\n\
+          \n");
+# endif /* HAVE_GETOPT_LONG */
+
 #endif /* CMOS_ACCESS */
     exit(1);
 }
@@ -246,7 +290,11 @@
 void init(void)
 {
   /* SMI port */
+#ifdef __linux__
   ioperm(0xb2, 1, 1);
+#else
+  open("/dev/io", O_RDWR, 0);
+#endif
 }
 #endif /* CMOS_ACCESS */
 
@@ -754,29 +802,29 @@
 #endif /* CMOS_ACCESS */
 
 #ifndef CMOS_ACCESS
-    printf("
-Power Management for Libretto V%-8s
-+-----------------------------------------------------------+
-|   0) Power-up Mode      : %-32s|
-|   1) Standby Time       : %-32s|
-|   2) System Auto Off    : %-32s|
-|   3) Panel Power On/Off : %-32s|
-|   4) Alarm Power On     : %-32s|
-|   5) LCD Power          : %-32s|
-|   6) Volume             : %-32s|
-|   7) Off (Suspend/Hiber): %-32s|
+    printf("\
+Power Management for Libretto V%-8s\n\
++-----------------------------------------------------------+\n\
+|   0) Power-up Mode      : %-32s|\n\
+|   1) Standby Time       : %-32s|\n\
+|   2) System Auto Off    : %-32s|\n\
+|   3) Panel Power On/Off : %-32s|\n\
+|   4) Alarm Power On     : %-32s|\n\
+|   5) LCD Power          : %-32s|\n\
+|   6) Volume             : %-32s|\n\
+|   7) Off (Suspend/Hiber): %-32s|\n\
 +-----------------------------------------------------------+\n\n",
     version, s[0], s[1], s[2], s[3], s[4], s[5], s[6], s[7]);
 #else
-    printf("
-Power Management for Libretto V%-8s
-+-----------------------------------------------------------+
-|   0) Power-up Mode      : %-32s|
-|   1) Standby Time       : %-32s|
-|   2) System Auto Off    : %-32s|
-|   3) Panel Power On/Off : %-32s|
-|   4) Alarm Power On     : %-32s|
-|   5) LCD Power          : %-32s|
+    printf("\
+Power Management for Libretto V%-8s\n\
++-----------------------------------------------------------+\n\
+|   0) Power-up Mode      : %-32s|\n\
+|   1) Standby Time       : %-32s|\n\
+|   2) System Auto Off    : %-32s|\n\
+|   3) Panel Power On/Off : %-32s|\n\
+|   4) Alarm Power On     : %-32s|\n\
+|   5) LCD Power          : %-32s|\n\
 +-----------------------------------------------------------+\n\n",
     version, s[0], s[1], s[2], s[3], s[4], s[5]);
 #endif /* CMOS_ACCESS */

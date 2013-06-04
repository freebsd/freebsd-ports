--- diwinpop.c.orig
+++ diwinpop.c
@@ -27,6 +27,8 @@
 #include	"hawin.h"
 #include        "haka.H"
 
+#include <unistd.h>
+
 /*************************************************************************
 ** FUNKTION:	DiWinPopdown
 ** ZWECK:	schliesst und zerstoert Widget

--- src/main.c.orig	2009-06-05 07:58:59.000000000 -0700
+++ src/main.c	2009-06-10 16:56:56.000000000 -0700
@@ -519,10 +519,6 @@
     }
   }
 
-  /* reset stdin/stdout to binary mode under Windows */
-  setmode(0,O_BINARY);
-  setmode(1,O_BINARY);
-
   /* if --keyref given, check encryption keys against named file */
   if (cmd.keyref && (cmd.mode == ENCRYPT || cmd.mode == KEYCHANGE)) {
     f = fopen(cmd.keyref, "rb");

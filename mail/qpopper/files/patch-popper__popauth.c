--- popper/popauth.c.orig	Wed Nov  1 11:42:03 2000
+++ popper/popauth.c	Wed Nov  1 11:41:56 2000
@@ -154,11 +154,11 @@
        char   *name;
 } modes[] = {
 #define SCRAM_AUTH  0
-    { "scramauth" },
+    { "qscramauth" },
 #define APOP_AUTH   1
-    { "apopauth"  },
+    { "qapopauth"  },
 #define POP_AUTH    2 
-    { "popauth"   },
+    { "qpopauth"   },
 #define OTHER       3
     { NULL        }
 };

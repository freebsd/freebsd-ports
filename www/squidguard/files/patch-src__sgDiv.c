--- src/sgDiv.c.orig	2008-03-12 20:41:53 UTC
+++ src/sgDiv.c
@@ -771,7 +771,7 @@ void sgEmergency ()
   }
   sgLogError("Going into emergency mode");
   while(fgets(buf, MAX_BUF, stdin) != NULL){
-    puts("");
+    puts("ERR");
     fflush(stdout);
   }
   sgLogError("ending emergency mode, stdin empty");

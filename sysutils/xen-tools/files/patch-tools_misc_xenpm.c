--- tools/misc/xenpm.c.orig	2015-11-03 09:11:18 UTC
+++ tools/misc/xenpm.c
@@ -97,8 +97,8 @@ static void parse_cpuid_and_int(int argc
 
     if ( argc == 0 || sscanf(argv[argc > 1], "%d", val) != 1 )
     {
-        fprintf(stderr, argc ? "Invalid %s '%s'\n" : "Missing %s\n",
-                what, argv[argc > 1]);
+        fprintf(stderr, argc ? "Invalid %s '%s'\n" : "Missing %s\n%s",
+                what, argc ? argv[argc > 1] : "");
         exit(EINVAL);
     }
 }

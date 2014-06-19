--- Xvnc/lib/font/Type1/type1.c.orig	2000-04-12 11:18:29.000000000 -0700
+++ Xvnc/lib/font/Type1/type1.c	2013-10-30 23:48:25.000000000 -0700
@@ -886,7 +886,7 @@
     if (!DoRead(&Code4)) goto ended;
     Push((double)((((((Code1<<8) + Code2)<<8) + Code3)<<8) + Code4));
   }
-  return;
+  return(0);
  
 ended: Error0("Decode: Premature end of Type 1 CharString");
 }
@@ -1321,7 +1321,7 @@
   for (;;) {
     if (!DoRead(&Code)) break;
     Decode(Code);
-    if (errflag) return;
+    if (errflag) return(0);
   }
   /* Copy snapped path to mypath and set path to NULL as above. */
   mypath = Snap(path);
@@ -1344,7 +1344,7 @@
   for (;;) {
     if (!DoRead(&Code)) break;
     Decode(Code);
-    if (errflag) return;
+    if (errflag) return(0);
   }
   path = Join(mypath, path);
 }

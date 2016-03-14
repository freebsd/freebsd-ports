--- testmain.c.orig	2016-03-02 15:04:22 UTC
+++ testmain.c
@@ -316,17 +316,38 @@ int main(int argc, char **argv)
     buildTestInterface(pSys);
     pVM = ficlNewVM(pSys);
 
-    ficlEvaluate(pVM, ".ver .( " __DATE__ " ) cr quit");
+    ficlEvaluate(pVM, ": loader_color? ( -- ) TRUE ;");
+    ficlEvaluate(pVM, "vocabulary support-functions");
+    ficlEvaluate(pVM, ": contains? ( -- ) FALSE ;");
+    ficlEvaluate(pVM, ": any_conf_read? ( -- ) FALSE ;");
+    ficlEvaluate(pVM, ": load_kernel ( -- ) ;");
+    ficlEvaluate(pVM, ": load_modules ( -- ) ;");
+    ficlEvaluate(pVM, ": delay_execute ( -- ) ;");
+    ficlEvaluate(pVM, "variable logoX");
+    ficlEvaluate(pVM, "variable logoY");
+
+    sprintf(in, "load %s", "/boot/screen.4th");
+    ficlEvaluate(pVM, in);
+    sprintf(in, "load %s", "/boot/beastie.4th");
+    ficlEvaluate(pVM, in);
 
     /*
     ** load file from cmd line...
     */
     if (argc  > 1)
     {
-        sprintf(in, ".( loading %s ) cr load %s\n cr", argv[1], argv[1]);
+        sprintf(in, "load %s", argv[1], argv[1]);
         ficlEvaluate(pVM, in);
+    } else {
+        fprintf(stderr, "usage: %s <logo.4th>\n", argv[0]);
+        return 1;
     }
 
+    system("clear");
+    ficlEvaluate(pVM, "draw-beastie");
+    printf("\n\n");
+    return 0;
+
     for (;;)
     {
         int ret;

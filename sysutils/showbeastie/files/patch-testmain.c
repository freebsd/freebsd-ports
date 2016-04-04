--- testmain.c.orig	2015-10-11 17:48:47 UTC
+++ testmain.c
@@ -296,6 +296,7 @@ void buildTestInterface(FICL_SYSTEM *pSy
     ficlBuild(pSys, "cd",       ficlChDir,    FW_DEFAULT);
     ficlBuild(pSys, "execxt",   execxt,       FW_DEFAULT);
     ficlBuild(pSys, "load",     ficlLoad,     FW_DEFAULT);
+    ficlBuild(pSys, "include",  ficlLoad,     FW_DEFAULT);
     ficlBuild(pSys, "pwd",      ficlGetCWD,   FW_DEFAULT);
     ficlBuild(pSys, "system",   ficlSystem,   FW_DEFAULT);
     ficlBuild(pSys, "spewhash", spewHash,     FW_DEFAULT);
@@ -316,17 +317,58 @@ int main(int argc, char **argv)
     buildTestInterface(pSys);
     pVM = ficlNewVM(pSys);
 
-    ficlEvaluate(pVM, ".ver .( " __DATE__ " ) cr quit");
+    ficlEvaluate(pVM, ": loader_color? ( -- ) TRUE ;");
+    ficlEvaluate(pVM, "vocabulary support-functions");
+    ficlEvaluate(pVM, ": contains? ( -- ) FALSE ;");
+    ficlEvaluate(pVM, ": any_conf_read? ( -- ) FALSE ;");
+    ficlEvaluate(pVM, ": boot_serial? ( -- ) TRUE ;");
+    ficlEvaluate(pVM, ": load_kernel ( -- ) ;");
+    ficlEvaluate(pVM, ": load_modules ( -- ) ;");
+    ficlEvaluate(pVM, ": delay_execute ( -- ) ;");
+    ficlEvaluate(pVM, ": boot ( -- ) ;");
+    ficlEvaluate(pVM, ": reboot ( -- ) ;");
+    ficlEvaluate(pVM, ": load_xen_throw ( -- ) ;");
+    ficlEvaluate(pVM, "variable logoX");
+    ficlEvaluate(pVM, "variable logoY");
+    ficlEvaluate(pVM, "variable brandX");
+    ficlEvaluate(pVM, "variable brandY");
+
+    sprintf(in, "load %s", "/boot/screen.4th");
+    ficlEvaluate(pVM, in);
+    sprintf(in, "load %s", "/boot/beastie.4th");
+    ficlEvaluate(pVM, in);
+    sprintf(in, "load %s", "/boot/brand.4th");
+    ficlEvaluate(pVM, in);
+    sprintf(in, "load %s", "/boot/frames.4th");
+    ficlEvaluate(pVM, in);
+    sprintf(in, "load %s", "/boot/menu.4th");
+    ficlEvaluate(pVM, in);
 
     /*
     ** load file from cmd line...
     */
     if (argc  > 1)
     {
-        sprintf(in, ".( loading %s ) cr load %s\n cr", argv[1], argv[1]);
+        char *brand = "/boot/brand-fbsd.4th";
+        sprintf(in, "load %s", argv[1]);
+        ficlEvaluate(pVM, in);        
+        if (argc > 2) {
+            brand = argv[2];
+        }
+        sprintf(in, "load %s", brand);
         ficlEvaluate(pVM, in);
+    } else {
+        fprintf(stderr, "usage: %s <logo.4th> [<brand.4th>]\n", argv[0]);
+        return 1;
     }
 
+    system("clear");
+    ficlEvaluate(pVM, "draw-beastie");
+    ficlEvaluate(pVM, "draw-brand");
+    ficlEvaluate(pVM, "menu-init");
+    printf("\n\n");
+    return 0;
+
     for (;;)
     {
         int ret;

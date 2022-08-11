--- apps/xmlsec.c.orig	2022-05-03 14:36:17 UTC
+++ apps/xmlsec.c
@@ -1210,7 +1210,7 @@ int main(int argc, const char **argv) {
        (xmlSecAppCmdLineParamGetInt(&repeatParam, 1) > 0)) {
        
         repeats = xmlSecAppCmdLineParamGetInt(&repeatParam, 1);
-        fprintf(stderr, "Executed %d tests in %ld msec\n", repeats, (1000 * total_time) / CLOCKS_PER_SEC);    
+        fprintf(stderr, "Executed %d tests in %ld msec\n", repeats, (long)(1000 * total_time) / CLOCKS_PER_SEC);    
     }
 
     goto success;

--- src/rpymodule.c
+++ src/rpymodule.c
@@ -1772,8 +1772,10 @@ start_events(void)
 
 void r_finalize(void)
 {
+#if (R_VERSION < R_Version(2,4,0)) 
     unsigned char buf[1024];
     char * tmpdir;
+#endif
 
     R_dot_Last();           
     R_RunExitFinalizers();  

--- src/main.cc.orig	2019-01-08 01:26:24 UTC
+++ src/main.cc
@@ -359,10 +359,6 @@ int main(int argc, char **argv) {
     return EXIT_FAILURE;
   }
 
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
-  kvm_close(kd);
-#endif
-
 #ifdef LEAKFREE_NCURSES
   _nc_free_and_exit(0);  // hide false memleaks
 #endif

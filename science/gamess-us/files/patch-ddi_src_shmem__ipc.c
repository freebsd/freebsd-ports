--- ddi/src/shmem_ipc.c.orig	2018-10-12 06:54:08 UTC
+++ ddi/src/shmem_ipc.c
@@ -292,7 +292,7 @@ int Shmctl(int memid, int cmd, struct sh
     fprintf(stdout,"error value=%i\n",iret);
     fflush(stdout);
     Fatal_error(911);
-    return; /* never returns */
+    /* never returns */
   }
   return iret;
 }

--- src/extensions/shmmodule.c.orig	Sat Mar 10 11:49:38 2007
+++ src/extensions/shmmodule.c	Sat Mar 10 16:59:55 2007
@@ -114,12 +114,13 @@
 
 /* Uncomment the following line if <sys/sem.h> defines "union semun" */
 
-/* #define HAVE_UNION_SEMUN */
+#define HAVE_UNION_SEMUN
 
 /* ------------------------------------------------------------------------- */
 #include "Python.h"
 #include "structmember.h"
 
+#include <machine/param.h>
 #include <sys/types.h>
 #include <sys/ipc.h>		/* for system's IPC_xxx definitions */
 #include <sys/shm.h>		/* for shmget, shmat, shmdt, shmctl */

--- src/sema.c.orig	Sun Jul 21 21:13:59 2002
+++ src/sema.c	Mon Jul 22 19:30:15 2002
@@ -22,6 +22,10 @@
 #  include <config.h>
 #endif
 
+#ifdef HAVE_SYS_PARAM_H
+#  include <sys/param.h>
+#endif
+
 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
@@ -57,6 +61,11 @@
 #include "uaddr.h"
 #include "status.h"
 
+/* interval between busy wait tries measured in microseconds */
+#define MUTEX_BUSY_WAIT_TIME	5000
+
+pthread_mutex_t		*semaphore_mutex = PTHREAD_MUTEX_INITIALIZER;
+
 /***********************************************************************/
 /* the following functions manage the bandwidth upload limit           */
 /* The system is build on 2 semaphores and 1 file                      */
@@ -100,6 +109,8 @@
 
 	int semid;
 
+	lp_mutex_init_(&semaphore_mutex, NULL);
+
 	fd=open(keyfile,O_CREAT|O_WRONLY|O_EXCL,0600);		/* create the file if not exists */
 	if(fd==-1)
 	{
@@ -131,7 +142,11 @@
 			{
 				close(fd);
 				/* a key exist */
+#if !(defined(BSD) && (BSD >= 199103))
 				semid=semget(key,0,IPC_ALLOC);
+#else
+				semid=semget(key,0,IPC_STAT);
+#endif
 				if(semid==-1)
 					goto create_new_sema;
 				printf("current sema found.\n");
@@ -293,8 +308,13 @@
 void check_sema_master(int semid)
 {
 	struct sembuf sb={0,-1,IPC_NOWAIT|SEM_UNDO};			/* master sema */
+	int result;
+
+	(void) lp_mutex_lock_(semaphore_mutex);
+	result = semop(semid,&sb,1);
+	(void) lp_mutex_unlock_(semaphore_mutex);
 
-	if(semop(semid,&sb,1)==0)
+	if (result==0)
 	{
 		/* to get slice, the function checks if the clock thread still runs */
 		create_sema_master(semid);
@@ -308,15 +328,29 @@
 /*******************************************/
 void get_slice(int semid, SPD_SEMA semnum)
 {
+#if !(defined(BSD) && (BSD >= 199103))
+	struct sembuf local={0,-1,0};					/* slave sema */
+#else
+	struct sembuf local={0,-1,0|IPC_NOWAIT};			/* slave sema */
+#endif
+	local.sem_num=semnum;
+
+	(void) lp_mutex_lock_(semaphore_mutex);
 	while(1)
 	{
-		struct sembuf local={0,-1,0};		/* slave sema */
-
-		local.sem_num=semnum;
-		if(semop(semid,&local,1)==0)
-		{
-			/* we have what we want */
-			return;
+		switch (semop(semid,&local,1)) {
+			case 0:	(void) lp_mutex_unlock_(semaphore_mutex);
+						/* we have what we want */
+						return;
+						break;
+			case -1:	switch(errno) {
+						case EAGAIN:			/* triggers busy wait */
+						case EINTR:			/* interrupted by system call, try again */
+									pthread_yield();
+									usleep(MUTEX_BUSY_WAIT_TIME);	/* busy wait with a small time out */
+									continue;
+									break;
+					}
 		}
 	}
 }
@@ -368,9 +402,26 @@
 /******************************/
 void lock_ul_slot_controler(int semid)
 {
+#if !(defined(BSD) && (BSD >= 199103))
 	struct sembuf get_ul_ctrl={UL_SLOT_SEMA,-1,SEM_UNDO};
+#else
+	struct sembuf get_ul_ctrl={UL_SLOT_SEMA,-1,SEM_UNDO|IPC_NOWAIT};
+#endif
+
+	(void) lp_mutex_lock_(semaphore_mutex);
+repeat:
 	/* lock the UL slot controler */
-	semop(semid,&get_ul_ctrl,1);
+	if (semop(semid,&get_ul_ctrl,1)==-1)
+		switch(errno)
+		{
+			case EAGAIN:			/* triggers busy wait */
+			case EINTR:			/* interrupted by system call, try again */
+						pthread_yield();
+						usleep(MUTEX_BUSY_WAIT_TIME);		/* busy wait with a small time out */
+						goto repeat;
+						break;
+		}
+	(void) lp_mutex_unlock_(semaphore_mutex);
 }
 
 /*********************************/
@@ -526,11 +577,28 @@
 			perror("free_one_ul_slot");
 		}
 #else
+#  if !(defined(BSD) && (BSD >= 199103))
 		struct sembuf free_one_ul_slot_op={UL_SLOT_BUSY_SEMA,-1,SEM_UNDO};
-		if(semop(semid,&free_one_ul_slot_op,1)==-1)
-		{
-			perror("free_one_ul_slot");
+#  else
+		struct sembuf free_one_ul_slot_op={UL_SLOT_BUSY_SEMA,-1,SEM_UNDO|IPC_NOWAIT};
+#  endif
+
+		(void) lp_mutex_lock_(semaphore_mutex);
+repeat:
+		if(semop(semid,&free_one_ul_slot_op,1)==-1) {
+			switch(errno) {
+				case EAGAIN:			/* triggers busy wait */
+				case EINTR:			/* interrupted by system call, try again */
+					pthread_yield();
+					usleep(MUTEX_BUSY_WAIT_TIME);          /* busy wait with a small time out */
+					goto repeat;
+					break;
+				default:
+					perror("free_one_ul_slot");
+					break;
+			}
 		}
+		(void) lp_mutex_unlock_(semaphore_mutex);
 #endif
 		nb_local_ul--;
 	}

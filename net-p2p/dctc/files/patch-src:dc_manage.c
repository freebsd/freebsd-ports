--- src/dc_manage.c.orig	Sat Nov 24 08:43:42 2001
+++ src/dc_manage.c	Sat Nov 24 13:17:32 2001
@@ -35,6 +35,11 @@
 #include <fcntl.h>
 #include <pthread.h>
 
+#if (defined(BSD) && (BSD >= 199103))
+#include <signal.h>
+#define MSG_NOSIGNAL 0
+#endif
+
 #include "display.h"
 #include "action.h"
 #include "macro.h"
@@ -189,6 +194,9 @@
 /*************************/
 static int send_file_data(int sck,char *filename, int start_pos, unsigned long file_len,WAIT_ACT *act)
 {
+#if (defined(BSD) && (BSD >= 199103))
+	sigset_t sigset, sigoset;
+#endif
 	unsigned long int i;
 	char buf[8192];			/* must be a multiple of 512 */
 	unsigned long int a=file_len-start_pos;
@@ -220,7 +228,20 @@
 		act->last_touch=time(NULL);
 
 		get_slices(bl_semid,sizeof(buf)/512);							/* obtain upload authorization */
+#if (defined(BSD) && (BSD >= 199103))
+		/* possible race condition since backup and restore
+		are not guaranteed to occur as a single operation */
+
+		/* backup sigmask and block SIGPIPE */
+		sigemptyset(&sigset);
+		sigaddset(&sigset,SIGPIPE);
+		(void) sigprocmask(SIG_BLOCK, &sigset, &sigoset);
+#endif
 		res=send(sck,buf,sizeof(buf),MSG_NOSIGNAL|MSG_WAITALL);
+#if (defined(BSD) && (BSD >= 199103))
+		/* restore sigmask backup */
+		(void)sigprocmask(SIG_SETMASK, &sigoset, NULL);
+#endif
 
 		act->last_touch=time(NULL);
 		if(res!=sizeof(buf))
@@ -240,7 +261,20 @@
 		act->last_touch=time(NULL);
 
 		get_slices(bl_semid,(remain+511)/512);							/* obtain upload authorization */
+#if (defined(BSD) && (BSD >= 199103))
+		/* possible race condition since backup and restore
+		are not guaranteed to occur as a single operation */
+
+		/* backup sigmask and block SIGPIPE */
+		sigemptyset(&sigset);
+		sigaddset(&sigset,SIGPIPE);
+		(void) sigprocmask(SIG_BLOCK, &sigset, &sigoset);
+#endif
 		res=send(sck,buf,remain,MSG_NOSIGNAL|MSG_WAITALL);
+#if (defined(BSD) && (BSD >= 199103))
+		/* restore sigmask backup */
+		(void)sigprocmask(SIG_SETMASK, &sigoset, NULL);
+#endif
 
 		act->last_touch=time(NULL);
 		if(res!=remain)
@@ -259,6 +293,9 @@
 /*************************/
 static int send_array_data(int sck,GByteArray *ba,WAIT_ACT *act)
 {
+#if (defined(BSD) && (BSD >= 199103))
+	sigset_t sigset, sigoset;
+#endif
 	unsigned long int i;
 	unsigned long int nb;
 	int remain;
@@ -274,7 +311,20 @@
 		act->last_touch=time(NULL);
 
 		get_slices(bl_semid,BLOCK_SIZE/512);							/* obtain upload authorization */
+#if (defined(BSD) && (BSD >= 199103))
+		/* possible race condition since backup and restore
+		are not guaranteed to occur as a single operation */
+
+		/* backup sigmask and block SIGPIPE */
+		sigemptyset(&sigset);
+		sigaddset(&sigset,SIGPIPE);
+		(void) sigprocmask(SIG_BLOCK, &sigset, &sigoset);
+#endif
 		res=send(sck,ba->data+cur_pos,BLOCK_SIZE,MSG_NOSIGNAL|MSG_WAITALL);
+#if (defined(BSD) && (BSD >= 199103))
+		/* restore sigmask backup */
+		(void)sigprocmask(SIG_SETMASK, &sigoset, NULL);
+#endif
 
 		act->last_touch=time(NULL);
 		if(res!=BLOCK_SIZE)
@@ -292,7 +342,20 @@
 		act->last_touch=time(NULL);
 
 		get_slices(bl_semid,(remain+511)/512);							/* obtain upload authorization */
+#if (defined(BSD) && (BSD >= 199103))
+		/* possible race condition since backup and restore
+		are not guaranteed to occur as a single operation */
+
+		/* backup sigmask and block SIGPIPE */
+		sigemptyset(&sigset);
+		sigaddset(&sigset,SIGPIPE);
+		(void) sigprocmask(SIG_BLOCK, &sigset, &sigoset);
+#endif
 		res=send(sck,ba->data+cur_pos,remain,MSG_NOSIGNAL|MSG_WAITALL);
+#if (defined(BSD) && (BSD >= 199103))
+		/* restore sigmask backup */
+		(void)sigprocmask(SIG_SETMASK, &sigoset, NULL);
+#endif
 
 		act->last_touch=time(NULL);
 		if(res!=remain)
@@ -326,6 +389,9 @@
 /**************************************************************************/
 static int com_up_get_list_len_process(const char *cmd,WAIT_ACT *act,int sck,GString *input, char *xtra_param)
 {
+#if (defined(BSD) && (BSD >= 199103))
+	sigset_t sigset, sigoset;
+#endif
 	GByteArray *cpy_data;
 	GString *out;
 	int res;
@@ -377,7 +443,20 @@
 
 	disp_msg(DEBUG_MSG,"reply",out->str,NULL);
 
+#if (defined(BSD) && (BSD >= 199103))
+		/* possible race condition since backup and restore
+		are not guaranteed to occur as a single operation */
+
+		/* backup sigmask and block SIGPIPE */
+		sigemptyset(&sigset);
+		sigaddset(&sigset,SIGPIPE);
+		(void) sigprocmask(SIG_BLOCK, &sigset, &sigoset);
+#endif
 	res=send(sck,out->str,out->len,MSG_NOSIGNAL);
+#if (defined(BSD) && (BSD >= 199103))
+		/* restore sigmask backup */
+		(void)sigprocmask(SIG_SETMASK, &sigoset, NULL);
+#endif
 	res=(res!=out->len);
 	g_string_free(out,TRUE);
 	if(res)
@@ -403,7 +482,20 @@
 				g_string_sprintfa(out,"%lu|",(unsigned long)100000+rand()%500000);
 			else
 				g_string_sprintfa(out,"%lu|",(unsigned long)cpy_data->len);
+#if (defined(BSD) && (BSD >= 199103))
+		/* possible race condition since backup and restore
+		are not guaranteed to occur as a single operation */
+
+		/* backup sigmask and block SIGPIPE */
+		sigemptyset(&sigset);
+		sigaddset(&sigset,SIGPIPE);
+		(void) sigprocmask(SIG_BLOCK, &sigset, &sigoset);
+#endif
 			res=send(sck,out->str,out->len,MSG_NOSIGNAL);
+#if (defined(BSD) && (BSD >= 199103))
+		/* restore sigmask backup */
+		(void)sigprocmask(SIG_SETMASK, &sigoset, NULL);
+#endif
 			res=(res!=out->len);
 			g_string_free(out,TRUE);
 			if(res)
@@ -674,6 +766,9 @@
 /*****************************************************************/
 static int copie_fd_to_file(int remote, FILE *local, unsigned long amount,WAIT_ACT *act)
 {
+#if (defined(BSD) && (BSD >= 199103))
+	sigset_t sigset, sigoset;
+#endif
 	while(amount!=0)
 	{
 		char buf[8192];
@@ -684,7 +779,20 @@
 
 		/* touch the action slot to avoid timeout */
 		act->last_touch=time(NULL);
+#if (defined(BSD) && (BSD >= 199103))
+		/* possible race condition since backup and restore
+		are not guaranteed to occur as a single operation */
+
+		/* backup sigmask and block SIGPIPE */
+		sigemptyset(&sigset);
+		sigaddset(&sigset,SIGPIPE);
+		(void) sigprocmask(SIG_BLOCK, &sigset, &sigoset);
+#endif
 		ret=recv(remote,buf,nb,MSG_WAITALL|MSG_NOSIGNAL);
+#if (defined(BSD) && (BSD >= 199103))
+		/* restore sigmask backup */
+		(void)sigprocmask(SIG_SETMASK, &sigoset, NULL);
+#endif
 		act->last_touch=time(NULL);
 		
 		if((ret==-1)||(ret==0))
@@ -1019,6 +1127,9 @@
 /*****************************************************************/
 static int copie_fd_to_bytearray(int remote, GByteArray **ba, unsigned long amount,WAIT_ACT *act)
 {
+#if (defined(BSD) && (BSD >= 199103))
+	sigset_t sigset, sigoset;
+#endif
 	int pos=0;
 	int ret;
 	unsigned long nb;
@@ -1032,12 +1143,25 @@
 
 		/* touch the action slot to avoid timeout */
 		act->last_touch=time(NULL);
+#if (defined(BSD) && (BSD >= 199103))
+		/* possible race condition since backup and restore
+		are not guaranteed to occur as a single operation */
+
+		/* backup sigmask and block SIGPIPE */
+		sigemptyset(&sigset);
+		sigaddset(&sigset,SIGPIPE);
+		(void) sigprocmask(SIG_BLOCK, &sigset, &sigoset);
+#endif
 #if 0
 		ret=recv(remote,(*ba)->data+pos,nb,MSG_WAITALL|MSG_NOSIGNAL);
 #else
 		ret=recv(remote,(*ba)->data+pos,nb,MSG_NOSIGNAL);
 		printf("%d\n",ret);
 #endif
+#if (defined(BSD) && (BSD >= 199103))
+		/* restore sigmask backup */
+		(void)sigprocmask(SIG_SETMASK, &sigoset, NULL);
+#endif
 		act->last_touch=time(NULL);
 		
 		if((ret==-1)||(ret==0))
@@ -2674,10 +2798,26 @@
 /*******************************************************/
 int manage_srch_port(int srch_sck, int sck)
 {
+#if (defined(BSD) && (BSD >= 199103))
+	sigset_t sigset, sigoset;
+#endif
 	char buf[8192];
 	int ret;
 
+#if (defined(BSD) && (BSD >= 199103))
+		/* possible race condition since backup and restore
+		are not guaranteed to occur as a single operation */
+
+		/* backup sigmask and block SIGPIPE */
+		sigemptyset(&sigset);
+		sigaddset(&sigset,SIGPIPE);
+		(void) sigprocmask(SIG_BLOCK, &sigset, &sigoset);
+#endif
 	ret=recv(srch_sck,buf,sizeof(buf),MSG_NOSIGNAL);
+#if (defined(BSD) && (BSD >= 199103))
+		/* restore sigmask backup */
+		(void)sigprocmask(SIG_SETMASK, &sigoset, NULL);
+#endif
 	if(ret!=-1)
 	{
 		int i;


$FreeBSD$

--- channels/chan_zap.c.orig	Sun Feb 17 18:01:44 2002
+++ channels/chan_zap.c	Sun Feb 17 18:03:26 2002
@@ -46,7 +46,9 @@
 #include <sys/signal.h>
 #include <errno.h>
 #include <stdlib.h>
+#ifndef __FreeBSD__
 #include <stdint.h>
+#endif
 #include <unistd.h>
 #include <sys/ioctl.h>
 #ifdef __linux__
@@ -320,7 +322,7 @@
 #define CALLWAITING_REPEAT_SAMPLES	( (10000 * 8) / READ_SIZE) /* 300 ms */
 #define CIDCW_EXPIRE_SAMPLES		( (500 * 8) / READ_SIZE) /* 500 ms */
 #define MIN_MS_SINCE_FLASH			( (2000) )	/* 2000 ms */
-#define RINGT 						( (8000 * 8) / READ_SIZE)
+#define RINGT 						( (8000 * 8) / READ_SIZE) /* 8000 ms */
 
 struct zt_pvt;
 
@@ -535,6 +537,7 @@
 	int cidpos;
 	int cidlen;
 	int ringt;
+	int waitnorings;
 	int stripmsd;
 	int callwaiting;
 	int callwaitcas;
@@ -2134,12 +2137,20 @@
 
 	if (option_debug)
 		ast_log(LOG_DEBUG, "zt_hangup(%s)\n", ast->name);
+
 	if (!ast->pvt->pvt) {
 		ast_log(LOG_WARNING, "Asked to hangup channel not connected\n");
 		return 0;
 	}
 	
 	ast_mutex_lock(&p->lock);
+
+	
+	if((p->sig == SIG_FXSGS) || (p->sig == SIG_FXSKS) || (p->sig == SIG_FXSLS))
+	if((ast->_state == AST_STATE_RING) && (p->ringt > 1))
+	{
+		p->waitnorings = 1;
+	}
 	
 	index = zt_get_index(ast, p, 1);
 
@@ -5717,7 +5728,37 @@
 		ast_setstate(chan, AST_STATE_RING);
 		chan->rings = 1;
 		p->ringt = RINGT;
+		p->waitnorings = 0;
 		res = ast_pbx_run(chan);
+
+		if(p->waitnorings)
+		{
+			p->ringt = RINGT;
+			for(;;)
+			{
+				int i,j=0;
+				i = ZT_IOMUX_SIGEVENT | ZT_IOMUX_NOWAIT;
+				if (ioctl(p->subs[index].zfd, ZT_IOMUX, &i) == -1) 
+					break;
+	
+				if (ioctl(p->subs[index].zfd, ZT_GETEVENT, &j) == -1) 
+					break;
+	
+				if(j == ZT_EVENT_RINGOFFHOOK)
+					p->ringt = RINGT;
+
+				usleep(20000);
+
+				if (p->ringt <= 0)
+					break;
+
+				else if (p->ringt > 0) 
+					p->ringt--;
+			}
+			p->ringt = 0;
+			p->waitnorings = 0;
+		}
+
 		if (res) {
 			ast_hangup(chan);
 			ast_log(LOG_WARNING, "PBX exited non-zero\n");
@@ -6018,7 +6059,7 @@
 		i = iflist;
 		while(i) {
 			if ((i->subs[SUB_REAL].zfd > -1) && i->sig && (!i->radio)) {
-				if (!i->owner && !i->subs[SUB_REAL].owner) {
+				if (!i->owner && !i->subs[SUB_REAL].owner && !i->waitnorings) {
 					/* This needs to be watched, as it lacks an owner */
 					pfds[count].fd = i->subs[SUB_REAL].zfd;
 					pfds[count].events = POLLPRI;


$FreeBSD$

--- channels/chan_zap.c.orig
+++ channels/chan_zap.c
@@ -51,10 +51,10 @@
 #ifdef __linux__
 #include <linux/zaptel.h>
 #else
-#include <zaptel.h>
+#include <zaptel/zaptel.h>
 #endif /* __linux__ */
 #include <math.h>
-#include <tonezone.h>
+#include <zaptel/tonezone.h>
 #include <ctype.h>
 #ifdef ZAPATA_PRI
 #include <libpri.h>
@@ -792,6 +792,7 @@
 	int cidlen;
 	int ringt;
 	int ringt_base;
+	int waitnorings;
 	int stripmsd;
 	int callwaitcas;
 	int callwaitrings;
@@ -2464,6 +2465,19 @@
 	}
 	
 	ast_mutex_lock(&p->lock);
+	switch (p->sig) {
+	case SIG_FXSGS:
+	case SIG_FXSKS:
+	case SIG_FXSLS:
+		if((ast->_state == AST_STATE_RING) && (p->ringt > 1))
+		{
+			p->waitnorings = 1;
+		}
+		break;
+	default:
+		break;
+	};
+
 	
 	index = zt_get_index(ast, p, 1);
 
@@ -6323,7 +6337,37 @@
 		ast_setstate(chan, AST_STATE_RING);
 		chan->rings = 1;
 		p->ringt = p->ringt_base;
+		p->waitnorings = 0;
 		res = ast_pbx_run(chan);
+
+		if(p->waitnorings)
+		{
+			p->ringt = p->ringt_base;
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
+					p->ringt = p->ringt_base;
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
@@ -6628,7 +6672,7 @@
 		i = iflist;
 		while(i) {
 			if ((i->subs[SUB_REAL].zfd > -1) && i->sig && (!i->radio)) {
-				if (!i->owner && !i->subs[SUB_REAL].owner) {
+				if (!i->owner && !i->subs[SUB_REAL].owner && !i->waitnorings) {
 					/* This needs to be watched, as it lacks an owner */
 					pfds[count].fd = i->subs[SUB_REAL].zfd;
 					pfds[count].events = POLLPRI;

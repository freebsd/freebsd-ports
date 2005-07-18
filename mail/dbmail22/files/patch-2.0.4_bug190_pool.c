Index: pool.c
===================================================================
--- pool.c	(revision 1600)
+++ pool.c	(revision 1758)
@@ -73,8 +73,10 @@
 void scoreboard_new(serverConfig_t * conf)
 {
 	int serr;
-	if ((shmid = shmget(IPC_PRIVATE, P_SIZE, 0644 | IPC_CREAT)) == -1)
-		trace(TRACE_FATAL, "%s,%s: shmget failed",__FILE__,__func__);
+	if ((shmid = shmget(IPC_PRIVATE, P_SIZE, 0644 | IPC_CREAT)) == -1) {
+		serr = errno;
+		trace(TRACE_FATAL, "%s,%s: shmget failed [%s]",__FILE__,__func__, strerror(serr));
+	}
 	scoreboard = shmat(shmid, (void *) 0, 0);
 	serr=errno;
 	if (scoreboard == (Scoreboard_t *) (-1)) {
@@ -222,7 +236,7 @@
 	}
 	scoreboard_unlck();
 	trace(TRACE_FATAL,
-	      "%s,%s: pid NOT found on scoreboard [%d]", __FILE__, __FUNCTION__, pid);
+	      "%s,%s: pid NOT found on scoreboard [%d]", __FILE__, __func__, pid);
 	return -1;
 }
 
@@ -238,25 +252,25 @@
 {
 	int i;
 	trace(TRACE_MESSAGE, "%s,%s: register child [%d]",
-		__FILE__, __FUNCTION__, getpid());
+		__FILE__, __func__, getpid());
 	
 	scoreboard_wrlck();
 	for (i = 0; i < scoreboard->conf->maxChildren; i++) {
 		if (scoreboard->child[i].pid == -1)
 			break;
 		if (scoreboard->child[i].pid == getpid()) {
-			trace(TRACE_ERROR,
+			scoreboard_unlck();
+			trace(TRACE_FATAL,
 			      "%s,%s: child already registered.",
-			      __FILE__, __FUNCTION__);
-			scoreboard_unlck();
+			      __FILE__, __func__);
 			return -1;
 		}
 	}
 	if (i == scoreboard->conf->maxChildren) {
+		scoreboard_unlck();
 		trace(TRACE_WARNING,
 		      "%s,%s: no empty slot found",
-		      __FILE__, __FUNCTION__);
-		scoreboard_unlck();
+		      __FILE__, __func__);
 		return -1;
 	}
 	
@@ -264,8 +278,8 @@
 	scoreboard->child[i].status = STATE_IDLE;
 	scoreboard_unlck();
 
-	trace(TRACE_INFO, "%s,%s: initializing child_state [%d] using slot [%d]",
-		__FILE__, __FUNCTION__, getpid(), i);
+	trace(TRACE_MESSAGE, "%s,%s: initializing child_state [%d] using slot [%d]",
+		__FILE__, __func__, getpid(), i);
 	return 0;
 }
 
@@ -281,7 +295,7 @@
 	scoreboard->child[key].status = STATE_CONNECTED;
 	scoreboard_unlck();
 
-	trace(TRACE_DEBUG, "%s,%s: [%d]", __FILE__, __FUNCTION__,
+	trace(TRACE_DEBUG, "%s,%s: [%d]", __FILE__, __func__,
 			getpid());
 }
 
@@ -297,7 +311,7 @@
 	scoreboard->child[key].status = STATE_IDLE;
 	scoreboard_unlck();
 
-	trace(TRACE_DEBUG, "%s,%s: [%d]", __FILE__, __FUNCTION__,
+	trace(TRACE_DEBUG, "%s,%s: [%d]", __FILE__, __func__,
 		getpid());
 }
 
@@ -320,7 +334,7 @@
 	scoreboard_unlck();
 
 	trace(TRACE_MESSAGE,
-	      "%s,%s: child [%d] unregistered", __FILE__, __FUNCTION__,
+	      "%s,%s: child [%d] unregistered", __FILE__, __func__,
 	      getpid());
 }
 
@@ -346,7 +360,7 @@
 			manage_stop_children();
 			trace(TRACE_FATAL,
 			      "%s,%s: could not create children. Fatal.",
-			      __FILE__, __FUNCTION__);
+			      __FILE__, __func__);
 			exit(0);
 		}
 	}
@@ -360,10 +374,17 @@
 		if (chpid == -1)
 			continue;
 		if (waitpid(chpid, NULL, WNOHANG|WUNTRACED) == chpid) {
+			scoreboard_release(chpid);			
 			trace(TRACE_MESSAGE,"%s,%s: child [%d] exited. Restarting...",
-				__FILE__, __FUNCTION__, chpid);
-			scoreboard_release(chpid);			
-			CreateChild(&childinfo);
+				__FILE__, __func__, chpid);
+			if (CreateChild(&childinfo)== -1) {
+				trace(TRACE_ERROR,"%s,%s: createchild failed. Bailout...",
+						__FILE__, __func__);
+				GeneralStopRequested=1;
+				manage_stop_children();
+
+				exit(1);
+			}
 		}
 	}
 	sleep(1);

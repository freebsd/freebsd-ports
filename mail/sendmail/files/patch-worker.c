--- libmilter/worker.c.orig	2007-12-03 23:06:05.000000000 +0100
+++ libmilter/worker.c	2009-06-15 09:46:29.000000000 +0200
@@ -328,6 +328,8 @@
 	int dim_pfd = 0;
 	bool rebuild_set = true;
 	int pcnt = 0; /* error count for poll() failures */
+	time_t lastcheck;
+	int nfd = 0;
 
 	Tskmgr.tm_tid = sthread_get_id();
 	if (pthread_detach(Tskmgr.tm_tid) != 0)
@@ -345,12 +347,12 @@
 	}
 	dim_pfd = PFD_STEP;
 
+	lastcheck = time(NULL);
 	for (;;)
 	{
 		SMFICTX_PTR ctx;
-		int nfd, rfd, i;
+		int rfd, i;
 		time_t now;
-		time_t lastcheck;
 
 		POOL_LEV_DPRINTF(4, ("Let's %s again...", WAITFN));
 
@@ -364,20 +366,20 @@
 		/* check for timed out sessions? */
 		if (lastcheck + DT_CHECK_OLD_SESSIONS < now)
 		{
-			SM_TAILQ_FOREACH(ctx, &WRK_CTX_HEAD, ctx_link)
+			ctx = SM_TAILQ_FIRST(&WRK_CTX_HEAD);
+			while (ctx != SM_TAILQ_END(&WRK_CTX_HEAD))
 			{
+				SMFICTX_PTR ctx_nxt;
+
+				ctx_nxt = SM_TAILQ_NEXT(ctx, ctx_link);
 				if (ctx->ctx_wstate == WKST_WAITING)
 				{
 					if (ctx->ctx_wait == 0)
-					{
 						ctx->ctx_wait = now;
-						continue;
-					}
-
-					/* if session timed out, close it */
-					if (ctx->ctx_wait + OLD_SESSION_TIMEOUT
-					    < now)
+					else if (ctx->ctx_wait + OLD_SESSION_TIMEOUT
+						 < now)
 					{
+						/* if session timed out, close it */
 						sfsistat (*fi_close) __P((SMFICTX *));
 
 						POOL_LEV_DPRINTF(4,
@@ -389,10 +391,9 @@
 							(void) (*fi_close)(ctx);
 
 						mi_close_session(ctx);
-						ctx = SM_TAILQ_FIRST(&WRK_CTX_HEAD);
-						continue;
 					}
 				}
+				ctx = ctx_nxt;
 			}
 			lastcheck = now;
 		}
@@ -465,6 +466,7 @@
 					}
 				}
 			}
+			rebuild_set = false;
 		}
 
 		TASKMGR_UNLOCK();

--- Xext/sync.c.orig	2008-11-05 10:52:17.000000000 -0600
+++ Xext/sync.c	2009-03-08 17:04:38.000000000 -0500
@@ -2533,7 +2533,7 @@
  * IDLETIME implementation
  */
 
-static pointer IdleTimeCounter;
+static SyncCounter *IdleTimeCounter;
 static XSyncValue *pIdleTimeValueLess;
 static XSyncValue *pIdleTimeValueGreater;
 
@@ -2545,38 +2545,69 @@
 }
 
 static void
-IdleTimeBlockHandler (pointer env,
-                      struct timeval **wt,
-                      pointer LastSelectMask)
+IdleTimeBlockHandler(pointer env, struct timeval **wt, pointer LastSelectMask)
 {
-    XSyncValue idle;
+    XSyncValue idle, old_idle;
+    SyncTriggerList *list = IdleTimeCounter->pTriglist;
+    SyncTrigger *trig;
 
     if (!pIdleTimeValueLess && !pIdleTimeValueGreater)
 	return;
 
+    old_idle = IdleTimeCounter->value;
     IdleTimeQueryValue (NULL, &idle);
+    IdleTimeCounter->value = idle; /* push, so CheckTrigger works */
 
     if (pIdleTimeValueLess &&
         XSyncValueLessOrEqual (idle, *pIdleTimeValueLess))
     {
-	AdjustWaitForDelay (wt, 0);
+	/*
+	 * We've been idle for less than the threshold value, and someone
+	 * wants to know about that, but now we need to know whether they
+	 * want level or edge trigger.  Check the trigger list against the
+	 * current idle time, and if any succeed, bomb out of select()
+	 * immediately so we can reschedule.
+	 */
+
+	for (list = IdleTimeCounter->pTriglist; list; list = list->next) {
+	    trig = list->pTrigger;
+	    if (trig->CheckTrigger(trig, old_idle)) {
+		AdjustWaitForDelay(wt, 0);
+		break;
+	    }
+	}
     }
     else if (pIdleTimeValueGreater)
     {
-	unsigned long timeout = 0;
+	/*
+	 * There's a threshold in the positive direction.  If we've been
+	 * idle less than it, schedule a wakeup for sometime in the future.
+	 * If we've been idle more than it, and someone wants to know about
+	 * that level-triggered, schedule an immediate wakeup.
+	 */
+	unsigned long timeout = -1;
 
-	if (XSyncValueLessThan (idle, *pIdleTimeValueGreater))
-	{
+	if (XSyncValueLessThan (idle, *pIdleTimeValueGreater)) {
 	    XSyncValue value;
 	    Bool overflow;
 
 	    XSyncValueSubtract (&value, *pIdleTimeValueGreater,
 	                        idle, &overflow);
-	    timeout = XSyncValueLow32 (value);
+	    timeout = min(timeout, XSyncValueLow32 (value));
+	} else {
+	    for (list = IdleTimeCounter->pTriglist; list; list = list->next) {
+		trig = list->pTrigger;
+		if (trig->CheckTrigger(trig, old_idle)) {
+		    timeout = min(timeout, 0);
+		    break;
+		}
+	    }
 	}
 
 	AdjustWaitForDelay (wt, timeout);
     }
+
+    IdleTimeCounter->value = old_idle; /* pop */
 }
 
 static void

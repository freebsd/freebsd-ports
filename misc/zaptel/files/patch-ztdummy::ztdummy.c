--- ztdummy/ztdummy.c.orig	Mon Jul 30 15:11:25 2007
+++ ztdummy/ztdummy.c	Mon Jul 30 15:11:32 2007
@@ -22,6 +22,10 @@
  * along with this program; if not, write to the Free Software
  * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
  *
+ * Rewritten to use the time of day clock (which should be ntp synced
+ * for this to work perfectly) by David G. Lawrence <dg@dglawrence.com>.
+ * July 27th, 2007.
+ *
  */
 
 #include <sys/cdefs.h>
@@ -45,26 +49,82 @@
 
 MALLOC_DEFINE(M_ZTD, "ztdummy", "ztdummy interface data structures");
 
+#ifndef timersub
+#define timersub(tvp, uvp, vvp)                                         \
+        do {                                                            \
+                (vvp)->tv_sec = (tvp)->tv_sec - (uvp)->tv_sec;          \
+                (vvp)->tv_usec = (tvp)->tv_usec - (uvp)->tv_usec;       \
+                if ((vvp)->tv_usec < 0) {                               \
+                        (vvp)->tv_sec--;                                \
+                        (vvp)->tv_usec += 1000000;                      \
+                }                                                       \
+        } while (0)
+#endif
 
 static struct callout_handle ztdummy_timer_handle = CALLOUT_HANDLE_INITIALIZER(&ztdummy_timer_handle);
 
 static struct ztdummy *ztd;
 
 static int debug = 0;
+static struct timeval basetime, curtime, sleeptime;
 
 static __inline void ztdummy_timer(void* arg )
 {
-	int i,j;
+	int i, ticks;
 
-	j = max(1, 1000/hz);
-	
-	for(i=0; i < j; i++) {
+loop:
+	for (i = 0; i < hz / 100; i++) {
 		zt_receive(&ztd->span);
 		zt_transmit(&ztd->span);
 	}
-	
-	ztdummy_timer_handle = timeout(ztdummy_timer, NULL, hz/1000);
 
+fixtime:
+	microtime(&curtime);
+
+	/*
+	 * Sleep until the next 10ms boundry.
+	 */
+	basetime.tv_usec += 10000;
+	if (basetime.tv_usec >= 1000000) {
+		basetime.tv_sec++;
+		basetime.tv_usec -= 1000000;
+	}
+	timersub(&basetime, &curtime, &sleeptime);
+
+	/*
+	 * Detect if we've gotten behind and need to start our processing
+	 * immediately.
+	 */
+	if (sleeptime.tv_sec < 0 || sleeptime.tv_usec == 0) {
+		/*
+		 * Limit how far we can get behind to something reasonable (1 sec)
+		 * so that we don't go nuts when something (ntp or admin) sets the
+		 * clock forward by a large amount.
+		 */
+		if (sleeptime.tv_sec < -1) {
+			basetime.tv_sec = curtime.tv_sec;
+			basetime.tv_usec = curtime.tv_usec;
+			goto fixtime;
+		}
+		goto loop;
+	}
+	/*
+	 * Detect if something is messing with the system clock by
+	 * checking that the sleep time is no more than 20ms and
+	 * resetting our base time if it is. This case will occur if
+	 * the system clock has been reset to an earlier time.
+	 */
+	if (sleeptime.tv_sec > 0 || sleeptime.tv_usec > 20000) {
+		basetime.tv_sec = curtime.tv_sec;
+		basetime.tv_usec = curtime.tv_usec;
+		goto fixtime;
+	}
+
+	ticks = sleeptime.tv_usec * hz / 1000000;
+	if (ticks == 0)
+		goto loop;
+
+	ztdummy_timer_handle = timeout(ztdummy_timer, NULL, ticks);
 }
 
 static int ztdummy_initialize(struct ztdummy *ztd)
@@ -102,7 +162,8 @@
 		return -ENODEV;
 	}
 
-	ztdummy_timer_handle = timeout(ztdummy_timer, NULL, hz/1000);
+	microtime(&basetime);
+	ztdummy_timer_handle = timeout(ztdummy_timer, NULL, 1);
     
 	if (debug)
 		printf("ztdummy: init() finished\n");

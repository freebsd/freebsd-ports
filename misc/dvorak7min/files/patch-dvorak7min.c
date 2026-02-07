--- dvorak7min.c.orig	Mon Mar 15 20:41:06 2004
+++ dvorak7min.c	Mon Mar 15 20:41:25 2004
@@ -41,7 +41,6 @@
  *  
  */
 
-#include <strings.h>
 #include <string.h>
 #include <stdlib.h>
 #include <ctype.h>
@@ -173,7 +172,8 @@
 /* calculate typing speed in a given interval */
 inline float calcSpeed (time_t timeStart, time_t timeFinish, int hits)
 {
-    return (float) hits / (timeFinish - timeStart);
+    // Use WPS/WPM as better standard, so also divide by 5 
+    return (float) hits / 5 / (timeFinish - timeStart);
 }
 
 
@@ -193,7 +193,7 @@
    
    file = fopen (fileName, "r");
    if (!file) {
-      postmortem = sys_errlist[errno];
+      postmortem = strerror(errno);
       return -1;
    }
    
@@ -220,7 +220,7 @@
    while (1) {
       c = fgetc (file);
       if (errno) {
-	 postmortem = sys_errlist[errno];
+	 postmortem = strerror(errno);
 	 fclose (file);
 	 return -1;
       }
@@ -418,6 +418,7 @@
 	  ++p;
 	  if (!timeStart) {
 	     timeStart = time(0);
+	     hits = 0;
 	  }
        }
        
@@ -431,8 +432,9 @@
 	     float ratio = hits - misses;
 	     ratio = (ratio < 0) ? 0 : (100.0 * ratio / hits);
 	     timeCurrent = time(0);
-	     speed = calcSpeed (timeStart, timeCurrent, hits);
-	     mvprintw (LINES - 1, 0, "CPS %.2f  CPM %.2f Hits: %d Misses: %d Seconds: %d Ratio: %.2f%%", speed, speed * 60, hits, misses, time(0) - timeStart, ratio);
+	     speed = calcSpeed (timeStart, timeCurrent, hits + misses);
+	     // Use WPS/WPM as better standards
+	     mvprintw (LINES - 1, 0, "WPS %.2f  WPM %.2f Hits: %d Misses: %d Seconds: %d Ratio: %.2f%%", speed, speed * 60, hits, misses, time(0) - timeStart, ratio);
 	     clrtoeol();
 	  }
        } while (ch == ERR);
@@ -510,7 +512,7 @@
     }
 
     timeFinish = time(0);
-    speed = calcSpeed(timeStart, timeFinish, hits);
+    speed = calcSpeed(timeStart, timeFinish, hits + misses);
     clear();
     cbreak();
     if (!timeStart) {
@@ -519,8 +521,11 @@
        float ratio = hits - misses;
        ratio = (ratio < 0) ? 0 : (100.0 * ratio / hits);
        mvprintw (0, 0, "Elapsed time: %d seconds", timeFinish - timeStart);
-       mvprintw (1, 0, "Total: %d  Misses: %d  Ratio: %.2f%%", hits, misses, ratio);
-       mvprintw (2, 0, "CPS: %.2f  CPM: %.2f", speed, speed * 60);
+       mvprintw (1, 0, "Total: %d  Misses: %d  Ratio: %.2f%%",
+                 hits + misses, misses,
+		 (float)100*(hits) / (hits + misses));
+       // Use WPM/WPS as better standard
+       mvprintw (2, 0, "WPS: %.2f  WPM: %.2f", speed, speed * 60);
     }
    
    mvprintw (4, 0, "[ ] Press ESCAPE to continue.");

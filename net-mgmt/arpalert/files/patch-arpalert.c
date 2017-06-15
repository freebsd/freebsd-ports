--- arpalert.c.orig	2011-11-08 19:36:51 UTC
+++ arpalert.c
@@ -179,6 +179,12 @@ int main(int argc, char **argv){
 		if(cur_timeout.tv_sec != -1){
 		   time_sous(&cur_timeout, &current_t, &timeout);
 
+			if (0 > timeout.tv_usec) {
+				/* avoid EINVAL (paranoid) */
+				timeout.tv_sec -= (timeout.tv_usec / 1000000) + 1;
+				timeout.tv_usec = (timeout.tv_usec % 1000000) + 1000000;
+			}
+
 			// prevent negative timeout
 			if(timeout.tv_sec < 0){
 				timeout.tv_usec = 0;
@@ -188,6 +194,12 @@ int main(int argc, char **argv){
 			timeout.tv_usec += 10000;
 			tmout = &timeout;
 
+			if (1000000 <= timeout.tv_usec) {
+				/* avoid EINVAL */
+				timeout.tv_sec += timeout.tv_usec / 1000000;
+				timeout.tv_usec %= 1000000;
+			}
+
 		// if no timeout
 		} else {
 			tmout = NULL;

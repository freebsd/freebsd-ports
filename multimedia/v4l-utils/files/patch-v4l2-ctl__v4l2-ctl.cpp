--- v4l2-ctl/v4l2-ctl.cpp.orig	2012-04-14 19:33:44.000000000 +0200
+++ v4l2-ctl/v4l2-ctl.cpp	2015-03-17 21:05:27.176219337 +0100
@@ -21,7 +21,6 @@
  */
 
 #include <unistd.h>
-#include <features.h>		/* Uses _GNU_SOURCE to define getsubopt in stdlib.h */
 #include <stdlib.h>
 #include <stdio.h>
 #include <string.h>
@@ -36,7 +35,6 @@
 #include <sys/time.h>
 #include <dirent.h>
 #include <math.h>
-#include <sys/klog.h>
 
 #include <linux/videodev2.h>
 #include <libv4l2.h>
@@ -1643,10 +1641,31 @@
 		printf("%s\n", iter->second.c_str());
 	}
 }
+int
+my_getsubopt (char **optionp, char *const *tokens, char **valuep)
+{
+          char *endp, *vstart;
+          int cnt;
+
+          if (**optionp == '\0')
+            return -1;
+
+          /* Find end of next token.  */
+          endp = strchrnul (*optionp, ',');
+
+          /* The current suboption does not match any option.  */
+          *valuep = *optionp;
+
+          if (*endp != '\0')
+            *endp++ = '\0';
+          *optionp = endp;
+
+          return -1;
+}
 
 static int parse_subopt(char **subs, const char * const *subopts, char **value)
 {
-	int opt = getsubopt(subs, (char * const *)subopts, value);
+	int opt = my_getsubopt(subs, (char * const *)subopts, value);
 
 	if (opt == -1) {
 		fprintf(stderr, "Invalid suboptions specified\n");
@@ -1667,7 +1686,7 @@
 	static char *const subopts[] = {
 	    NULL
 	};
-	int opt = getsubopt(subs, subopts, value);
+	int opt = my_getsubopt(subs, subopts, value);
 
 	if (value == NULL) {
 		fprintf(stderr, "No value given to suboption <%s>\n",
@@ -3493,6 +3512,7 @@
 		static char buf[40960];
 		int len;
 
+#ifndef __FreeBSD__
 		if (doioctl(fd, VIDIOC_LOG_STATUS, NULL) == 0) {
 			printf("\nStatus Log:\n\n");
 			len = klogctl(3, buf, sizeof(buf) - 1);
@@ -3514,6 +3534,7 @@
 				}
 			}
 		}
+#endif
 	}
 
 	/* List options */

--- v4l2-ctl/v4l2-ctl.cpp.orig
+++ v4l2-ctl/v4l2-ctl.cpp
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
@@ -1644,9 +1642,50 @@ static void list_devices()
 	}
 }
 
+#if __FreeBSD_version < 1000000
+/* from FreeBSD src/lib/libc/string/strchrnul.c: */
+
+char *strchrnul(const char *p, int ch);
+
+char *
+strchrnul(const char *p, int ch)
+{
+	char c;
+
+	c = ch;
+	for (;; ++p) {
+		if (*p == c || *p == '\0')
+			return ((char *)p);
+	}
+	/* NOTREACHED */
+}
+#endif
+
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
+
 static int parse_subopt(char **subs, const char * const *subopts, char **value)
 {
-	int opt = getsubopt(subs, (char * const *)subopts, value);
+	int opt = my_getsubopt(subs, (char * const *)subopts, value);
 
 	if (opt == -1) {
 		fprintf(stderr, "Invalid suboptions specified\n");
@@ -1667,7 +1704,7 @@ static void parse_next_subopt(char **sub
 	static char *const subopts[] = {
 	    NULL
 	};
-	int opt = getsubopt(subs, subopts, value);
+	int opt = my_getsubopt(subs, subopts, value);
 
 	if (value == NULL) {
 		fprintf(stderr, "No value given to suboption <%s>\n",
@@ -3493,6 +3530,7 @@ int main(int argc, char **argv)
 		static char buf[40960];
 		int len;
 
+#ifndef __FreeBSD__
 		if (doioctl(fd, VIDIOC_LOG_STATUS, NULL) == 0) {
 			printf("\nStatus Log:\n\n");
 			len = klogctl(3, buf, sizeof(buf) - 1);
@@ -3514,6 +3552,7 @@ int main(int argc, char **argv)
 				}
 			}
 		}
+#endif
 	}
 
 	/* List options */

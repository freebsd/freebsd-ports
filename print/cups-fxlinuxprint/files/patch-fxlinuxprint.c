--- fxlinuxprint.c.orig	2006-03-06 15:19:54.000000000 +0900
+++ fxlinuxprint.c	2014-05-09 10:28:36.000000000 +0900
@@ -24,7 +24,7 @@
 #include <fcntl.h>
 #define __USE_XOPEN_EXTENDED
 #include <signal.h>
-#include <wait.h>
+#include <sys/wait.h>
 #include <unistd.h>
 #include <cups/cups.h>
 #include <cups/ppd.h>
@@ -517,7 +517,7 @@
 		if (opt->job_type == JOB_SECURITY) {
 			strcat (pjl, PJLSetHoldType);
 			if (opt->hold_key[0] != 0x00) {
-				if (Decode (opt->hold_key, decode_buff, &decode_len)) {
+				if (Decode ((unsigned char *)opt->hold_key, (unsigned char *)decode_buff, &decode_len)) {
    		 			decode_buff[decode_len] = 0;
 				} else {
 					strcpy (decode_buff, opt->hold_key);

--- iobottle.cpp.orig	Fri Aug  6 05:39:19 1999
+++ iobottle.cpp	Fri Oct 25 13:58:58 2002
@@ -1,3 +1,4 @@
+#include <string.h>
 
 extern "C" {
 #include <stdlib.h>
@@ -97,7 +98,7 @@
 }
 /* If buf[len-1] is a null, then a newline should be written */
 size_t
-IObottle:: writeline(char *buf, size_t len = 0) {
+IObottle:: writeline(char *buf, size_t len) {
 	int lenwritten = 0;
 
 	if ( fputs(buf, wfp) >= 0 )
@@ -134,7 +135,7 @@
 	return(0);
 }
 int
-IObottle:: set_time(time_t actime, time_t modtime = 0) {
+IObottle:: set_time(time_t actime, time_t modtime) {
 	struct stat    sb;
 	struct utimbuf ub;
 

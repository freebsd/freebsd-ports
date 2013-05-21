Address the buffer-overflow problem outlined here:
	http://packetstormsecurity.com/files/85687/sa38292.txt
(buffer is of size BUFSIZ, but the check is for 8Mb, which may not be the
same) by not using a buffer at all. Instead we simply mmap the script-file.

The patch also adds closing of the script file at the end and fixes some
compiler warnings (the the -Wall -W levels).

On 32-bit architectures this limits the replayable script-size to 4Gb.

	-mi
--- src/replay.c	2009-11-24 09:54:58.000000000 -0500
+++ src/replay.c	2013-02-12 15:51:31.000000000 -0500
@@ -19,4 +19,6 @@
 #include "super.h"
 #include "struct.h"
+#include <sys/mman.h>
+#include <stdint.h>
 
 #define LL() fprintf(stderr, "[%s, line %i]: ", __FILE__, __LINE__)
@@ -71,5 +73,5 @@
 void show_sessions(void);
 
-int main(int argc, char **argv, char **environ)
+int main(int argc, char *argv[])
 {
 	int c;
@@ -406,14 +408,15 @@
 void replay(const char *time, const char *script, int div, int maxwait)
 {
-	char read_buffer[BUFSIZ];
+	char *read_buffer;
 	char timebuf[BUFSIZ];
 	float ftime = 0;
 	int b = 0;
 	int bInput = 0;
-	int r = 0;
 	int sec, usec;
 	char buffer[BUFSIZ];
 	struct s_file s_time;
 	struct s_file s_script;
+	struct stat sb;
+	off_t offset;
 	struct timeval tv;
 
@@ -432,9 +435,13 @@
 	}
 
-	if ((s_script.fd = open(script, O_RDONLY)) == -1) {
+	if ((s_script.fd = open(script, O_RDONLY)) == -1 ||
+	    fstat(s_script.fd, &sb) ||
+	    (read_buffer = mmap(NULL, sb.st_size, PROT_READ, MAP_NOCORE|MAP_SHARED, s_script.fd, 0))
+	    == MAP_FAILED) {
 		LL();
 		fprintf(stderr, "%s: %s: %s (%i)\n", progname, script, strerror(errno), errno);
 		exit(EXIT_FAILURE);
 	}
+	offset = 0;
 
 	for (s_time.line = 1; fgets(buffer, BUFSIZ - 1, s_time.f); s_time.line++) {
@@ -478,29 +485,22 @@
 		tv.tv_usec = (time_t) usec;
 
-		if (b > 1024 * 1024 * 8) {	/* 8MB */
+		if (b > sb.st_size - offset) {	/* 8MB */
 			LL();
-			fprintf(stderr, "[error]: line %i: wanted to read %i bytes, but the limit is 8MB.\n", s_time.line, b);
-			exit(EXIT_FAILURE);
-		}
-
-		memset(read_buffer, '\0', BUFSIZ);
-		r = read(s_script.fd, read_buffer, (size_t) b);
-
-		if (r != b) {
-			LL();
-			fprintf(stderr, "[failure]: read %i bytes out of %i.\n", r, b);
+			fprintf(stderr, "[error]: line %i: wanted to read %i bytes, but only %jd are "
+			    "left in %s.\n", s_time.line, b, (intmax_t)sb.st_size - offset, script);
 			exit(EXIT_FAILURE);
 		}
 
 		select(0, (fd_set *) 0, (fd_set *) 0, (fd_set *) 0, &tv);
-		fputs(read_buffer, stdout);
+		fwrite(read_buffer + offset, 1, b, stdout); /* Should we check for error here? XXX */
+		offset += b;
 		fflush(stdout);
-		memset(read_buffer, '\0', BUFSIZ);
 	}
+	munmap(read_buffer, sb.st_size);
+	close(s_script.fd);
 	fprintf(stderr, "[info]: EOF\n");
 	fflush(stderr);
 }
 
-
 session *session_malloc(void)
 {
@@ -586,5 +586,5 @@
 session *sort_list(session * list)
 {
-	session *p, *q, *e, *tail, *oldhead;
+	session *p, *q, *e, *tail;
 	int insize, nmerges, psize, qsize, i;
 
@@ -597,5 +597,4 @@
 
 		p = list;
-		oldhead = list;
 		list = (session *) 0;
 		tail = (session *) 0;

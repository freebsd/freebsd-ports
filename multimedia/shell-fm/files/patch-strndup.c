--- src/strndup.c.orig	Sat Dec 16 04:21:22 2006
+++ src/strndup.c	Sat Dec 16 04:20:48 2006
@@ -0,0 +1,17 @@
+#include "strndup.h"
+#include <string.h>
+#include <stdlib.h>
+
+#ifdef __STRNDUP__
+
+char* strndup(const char*  src, size_t len) {
+	char* _tmpStr = (char*)malloc(len + 1);
+	if (_tmpStr) {
+		strncpy(_tmpStr, src, len);
+		_tmpStr[len] = 0;
+	}
+	return _tmpStr;
+}
+
+#endif
+
--- src/include/strndup.h.orig	Sat Dec 16 04:21:27 2006
+++ src/include/strndup.h	Sat Dec 16 04:20:28 2006
@@ -0,0 +1,11 @@
+#if (defined(__unix__) || defined(unix)) && !defined(USG)
+#include <sys/param.h>
+#endif
+
+#if ((defined(__FreeBSD__) || defined(__OpenBSD__)) && !defined(__STRNDUP__))
+#define __STRNDUP__
+
+extern char* strndup(const char*  src, size_t len);
+
+#endif
+
--- src/Makefile.am.orig	Sat Dec 16 04:18:32 2006
+++ src/Makefile.am	Sat Dec 16 04:18:41 2006
@@ -169,6 +169,7 @@
 SUBDIRS = include
 INCLUDES = -I$(srcdir)/include
 shell_fm_SOURCES = \
+strndup.c \
 autoban.c \
 bookmark.c \
 getln.c \
--- src/tag.c.orig	Sat Dec 16 04:25:15 2006
+++ src/tag.c	Sat Dec 16 02:07:49 2006
@@ -22,6 +22,7 @@
 #include "split.h"
 #include "interface.h"
 #include "completion.h"
+#include "strndup.h"
 #include "md5.h"
 #include "feeds.h"

--- src/feeds.c.o	2007-11-19 18:31:19.000000000 +0200
+++ src/feeds.c	2007-11-19 18:31:43.000000000 +0200
@@ -8,6 +8,7 @@
 #include "http.h"
 #include "feeds.h"
 #include "tag.h"
+#include "strndup.h"

 char ** neighbors(const char * user) {
	char * encoded = NULL, feed[128], ** names = NULL;
--- src/playlist.c.o	2007-11-19 18:31:15.000000000 +0200
+++ src/playlist.c	2007-11-19 18:31:31.000000000 +0200
@@ -18,6 +18,7 @@
 #include "http.h"
 #include "settings.h"
 #include "service.h"
+#include "strndup.h"
 
 #include "playlist.h"
 #include "globals.h"

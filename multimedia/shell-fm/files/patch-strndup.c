--- src/strndup.c.orig	Sat Dec 16 04:21:22 2006
+++ src/strndup.c	Sat Dec 16 04:20:48 2006
@@ -0,0 +1,14 @@
+#include "strndup.h"
+#include <string.h>
+#include <stdlib.h>
+
+#ifdef __STRNDUP__
+
+char* strndup(const char*  src, size_t len) {
+	char* _tmpStr = (char*)malloc(len + 1);
+	strncpy(_tmpStr, src, len);
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
@@ -6,6 +6,7 @@
 INCLUDES = -I$(srcdir)/include
 
 shell_fm_SOURCES = \
+strndup.c \
 autoban.c \
 bookmark.c \
 getln.c \
--- src/radio.c.orig	Sat Dec 16 04:25:00 2006
+++ src/radio.c	Sat Dec 16 02:07:30 2006
@@ -35,6 +35,7 @@
 #include "settings.h"
 #include "rl_completion.h"
 #include "strarray.h"
+#include "strndup.h"
 
 #define LASTFM_URL_PREFIX "lastfm://"
 #define LASTFM_URL_MIN_LENGTH 6 // shortest possible: 'user/a'
--- src/strarray.c.orig	Sat Dec 16 04:25:13 2006
+++ src/strarray.c	Sat Dec 16 02:07:39 2006
@@ -22,6 +22,7 @@
 
 #include "compatibility.h"
 #include "strarray.h"
+#include "strndup.h"
 
 void strarray_init (strarray_t *sa) {
 	sa->strings = NULL;
--- src/tag.c.orig	Sat Dec 16 04:25:15 2006
+++ src/tag.c	Sat Dec 16 02:07:49 2006
@@ -23,6 +23,7 @@
 #include "split.h"
 #include "interface.h"
 #include "rl_completion.h"
+#include "strndup.h"
 
 static char ** getPopularTags(char, struct hash);
 static char * getExistingTags(char, struct hash);

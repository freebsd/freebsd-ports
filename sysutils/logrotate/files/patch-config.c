diff --git a/config.c b/config.c
index e6d5d1d..d14d742 100644
--- a/config.c
+++ b/config.c
@@ -1,5 +1,4 @@
 #include <sys/queue.h>
-#include <alloca.h>
 #include <ctype.h>
 #include <dirent.h>
 #include <errno.h>
@@ -19,6 +18,7 @@
 #include <wctype.h>
 #include <fnmatch.h>
 #include <sys/mman.h>
+#include <limits.h>
 
 #include "basenames.h"
 #include "log.h"
@@ -28,6 +28,14 @@
 #define GLOB_ABORTED GLOB_ABEND
 #endif
 
+#if !defined(MAP_POPULATE)
+#define MAP_POPULATE 0
+#endif
+
+#if !defined(MADV_DONTFORK)
+#define MADV_DONTFORK 0
+#endif
+
 #define REALLOC_STEP    10
 
 #if defined(SunOS) 
@@ -100,7 +108,7 @@ static char *readPath(const char *configFile, int lineNum, char *key,
 
 	chptr = start;
 
-	while( (len = mbrtowc(&pwc, chptr, strlen(chptr), NULL)) != 0 ) {
+	while( (len = strlen(chptr)) != 0 && (len = mbrtowc(&pwc, chptr, len, NULL)) != 0 ) {
 		if( len == (size_t)(-1) || len == (size_t)(-2) || !iswprint(pwc) || iswblank(pwc) ) {
 		    message(MESS_ERROR, "%s:%d bad %s path %s\n",
 			    configFile, lineNum, key, start);
@@ -519,12 +527,24 @@ static int readConfigFile(const char *configFile, struct logInfo *defConfig)
        length arrays -- of course, if we aren't run setuid it doesn't
        matter much */
 
+#ifdef __FreeBSD__
+    fd = open(configFile, O_RDONLY);
+#else
     fd = open(configFile, O_RDONLY | O_CLOEXEC);
+#endif
     if (fd < 0) {
 	message(MESS_ERROR, "failed to open config file %s: %s\n",
 		configFile, strerror(errno));
 	return 1;
     }
+#ifdef __FreeBSD__
+    if (fcntl(fd, F_SETFD, fcntl(fd, F_GETFD) & FD_CLOEXEC) == -1) {
+	message(MESS_ERROR, "Could not set close-on-exec for file %s\n",
+		configFile);
+	close(fd);
+	return 1;
+    }
+#endif
 	/* We don't want anybody to change the file while we parse it,
 	 * let's try to lock it for reading. */
 	if (fcntl(fd, F_SETLK, &fd_lock) == -1) {

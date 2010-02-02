--- ./config.h.orig	1993-10-29 05:25:35.000000000 -0400
+++ ./config.h	2010-02-02 14:21:04.000000000 -0500
@@ -35,14 +35,16 @@
  *  files instead.
  *  Note that "~" is not expanded in this directory name.
  */
+#ifndef SYSTEM_DIR
 #define SYSTEM_DIR              "/home/diagnostix3/ida/tompa/pmf-1.13.1/pmfdir/system_dir"
+#endif
 
 /*  These are the names of some files, usually in the system directory
  *  SYSTEM_DIR that is #defined above.
  *  If these names start with a "/" they are considered
  *  relative to the root directory, otherwise to SYSTEM_DIR.
  */
-#define SYSTEM_DEFAULT_INIT_FILE        ".pmfrc.default"
+#define SYSTEM_DEFAULT_INIT_FILE        "pmfrc.default"
 #define SYSTEM_NEWS_FILE                "NEWS"
 #define SYSTEM_HELP_DIR                 "helpfiles"
 #define SYSTEM_SOUND_DIR                "soundfiles"
@@ -63,16 +65,22 @@
 #define X_OUTPUT_PROGRAM	"cat"
 
 /* What system? Define one either BSD or SYSV:*/
+#ifndef BSD
 #define BSD
+#endif
 /* #define SYSV */
 
 /* What ioctl do we use for the ttys? */
-#ifdef BSD
+#if defined(BSD) && !defined(__FreeBSD__)
 #  define USE_TIOCGETP
 #else
 #  define USE_TCGETA
 #endif
 
+#ifdef BSD
+#define _cnt _r
+#endif
+
 /*  The prompt to print after doing a builtin command. 0 means no prompt.
  *  The prompt variable is initially set to the value of DEFAULT_PROMPT,
  *  but it can of course later be changed with the command "set prompt".

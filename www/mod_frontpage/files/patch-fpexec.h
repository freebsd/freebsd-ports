--- fpexec.h.orig	Tue Mar 12 22:07:06 2002
+++ fpexec.h	Thu May 16 11:25:40 2002
@@ -94,7 +94,7 @@
  *                debugging purposes.
  */
 #ifndef FP_LOG_EXEC
-#define FP_LOG_EXEC "/usr/local/apache/logs/cgi.log"	/* Need me? */
+#define FP_LOG_EXEC PREFIX "/apache/logs/cgi.log"	/* Need me? */
 #endif
 
 /*
@@ -102,7 +102,7 @@
  *
  */
 #ifndef FP_SAFE_PATH
-#define FP_SAFE_PATH "/usr/local/bin:/usr/bin:/bin"
+#define FP_SAFE_PATH PREFIX "/bin:/usr/bin:/bin"
 #endif
 
 /*
@@ -111,7 +111,7 @@
  *
  */
 #ifndef FPDIR
-#define FPDIR "/usr/local/frontpage/version5.0/exes"
+#define FPDIR PREFIX "/frontpage/version5.0/exes"
 #endif
 
 /*
@@ -120,7 +120,7 @@
  *
  */
 #ifndef FPBASE
-#define FPBASE "/usr/local/frontpage/version5.0"
+#define FPBASE PREFIX "/frontpage/version5.0"
 #endif
 
 
@@ -165,7 +165,7 @@
  *               that can be used for fpEXEC behavior.
  */
 #ifndef FP_DOC_ROOT
-#define FP_DOC_ROOT "/usr/local/apache/htdocs"
+#define FP_DOC_ROOT PREFIX "/apache/htdocs"
 #endif
 
 /*

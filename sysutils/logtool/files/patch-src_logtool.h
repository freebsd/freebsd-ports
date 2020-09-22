--- src/logtool.h.orig	2003-05-29 22:36:57 UTC
+++ src/logtool.h
@@ -82,7 +82,7 @@ int strncasecmp(const char *s1, const char *s2, size_t
 #endif
 
 /* this is a global variable we use to pass around hostname's */
-char lt_host[LSIZE];
+extern char lt_host[LSIZE];
 
 /*
  * This is the structure each line of syslog file get's parsed into.  
@@ -105,7 +105,7 @@ typedef struct {
 	char pmsg[(LSIZE * 4)];	/* where we store the string we're going to print	*/
 	MOD m;		/* pointer to where we store extra data for mod_* events*/
 } st_event;
-st_event event;
+extern st_event event;
 
 /* Structure for the event color variables */
 typedef struct {
@@ -137,7 +137,7 @@ typedef struct {
 	char unknown[256];	/* \033u	*/
 	char end[256];		/* \033e	*/
 } st_color;
-st_color color;
+extern st_color color;
 
 typedef struct {
 	char configfile[1024];	/* ascii name of our config file			*/
@@ -158,7 +158,7 @@ typedef struct {
 	short int resolv;	/* disable host resolution, even if enabled in cfg file	*/
 } CONFIG;
 
-CONFIG cf;
+extern CONFIG cf;
 
 extern int errno;	/* the error number thing from the errno functions	*/
 
@@ -242,4 +242,4 @@ typedef struct {
 	regex_t include_reg;
 } STRUCTURE_REGEXS;
 
-STRUCTURE_REGEXS reg;
+extern STRUCTURE_REGEXS reg;

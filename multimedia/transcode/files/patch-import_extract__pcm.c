--- import/extract_pcm.c.orig	2011-11-19 16:50:27 UTC
+++ import/extract_pcm.c
@@ -33,7 +33,7 @@
 #include "tc.h"
 
 #define MAX_BUF 4096
-char audio[MAX_BUF];
+static char audio[MAX_BUF];
 
 #define BUFFER_SIZE 262144
 static uint8_t buffer[BUFFER_SIZE];

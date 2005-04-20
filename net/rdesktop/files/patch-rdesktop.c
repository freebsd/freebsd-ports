--- rdesktop.c.orig	2004-11-18 14:18:49.000000000 +0300
+++ rdesktop.c	2004-12-15 12:19:11.263991136 +0300
@@ -28,6 +28,8 @@
 #include <sys/times.h>		/* times */
 #include <ctype.h>		/* toupper */
 #include <errno.h>
+#include <locale.h>
+#include <langinfo.h>
 #include "rdesktop.h"
 
 #ifdef EGD_SOCKET
@@ -39,6 +41,7 @@
 
 char g_title[64] = "";
 char g_username[64];
+char g_codepage[16] = "";
 char g_hostname[16];
 char keymapname[16];
 int g_keylayout = 0x409;	/* Defaults to US keyboard layout */
@@ -112,6 +115,7 @@
 	fprintf(stderr, "   -g: desktop geometry (WxH)\n");
 	fprintf(stderr, "   -f: full-screen mode\n");
 	fprintf(stderr, "   -b: force bitmap updates\n");
+	fprintf(stderr, "   -L: local codepage\n");
 	fprintf(stderr, "   -B: use BackingStore of X-server (if available)\n");
 	fprintf(stderr, "   -e: disable encryption (French TS)\n");
 	fprintf(stderr, "   -E: disable encryption from client to server\n");
@@ -366,7 +370,7 @@
 #endif
 
 	while ((c = getopt(argc, argv,
-			   VNCOPT "u:d:s:c:p:n:k:g:fbBeEmzCDKS:T:NX:a:x:Pr:045h?")) != -1)
+			   VNCOPT "u:L:d:s:c:p:n:k:g:fbBeEmzCDKS:T:NX:a:x:Pr:045h?")) != -1)
 	{
 		switch (c)
 		{
@@ -389,6 +393,10 @@
 				username_option = 1;
 				break;
 
+			case 'L':
+				STRNCPY(g_codepage, optarg, sizeof(g_codepage));
+				break;
+
 			case 'd':
 				STRNCPY(domain, optarg, sizeof(domain));
 				break;
@@ -675,6 +683,18 @@
 		STRNCPY(g_username, pw->pw_name, sizeof(g_username));
 	}
 
+	if (g_codepage[0] == 0)
+	{
+		if (setlocale(LC_CTYPE, ""))
+		{
+			STRNCPY(g_codepage, nl_langinfo(CODESET), sizeof(g_codepage));
+		}
+		else
+		{
+			STRNCPY(g_codepage, DEFAULT_CODEPAGE, sizeof(g_codepage));
+		}
+	}
+ 
 	if (g_hostname[0] == 0)
 	{
 		if (gethostname(fullhostname, sizeof(fullhostname)) == -1)
diff -uNr rdp.c.orig rdp.c

--- argp/argp.h.orig	Tue Jun 10 23:09:27 2003
+++ argp/argp.h	Mon Jul  7 04:31:41 2003
@@ -352,7 +352,7 @@
 #define ARGP_NO_EXIT	0x20
 
 /* Use the gnu getopt `long-only' rules for parsing arguments.  */
-#define ARGP_LONG_ONLY	0x40
+#define ARGP_LONG_ONLY	0x00
 
 /* Turns off any message-printing/exiting options.  */
 #define ARGP_SILENT    (ARGP_NO_EXIT | ARGP_NO_ERRS | ARGP_NO_HELP)

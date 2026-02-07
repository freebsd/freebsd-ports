--- argp/argp.h.orig	2006-05-22 16:49:22 UTC
+++ argp/argp.h
@@ -352,7 +352,7 @@ struct argp_state
 #define ARGP_NO_EXIT	0x20
 
 /* Use the gnu getopt `long-only' rules for parsing arguments.  */
-#define ARGP_LONG_ONLY	0x40
+#define ARGP_LONG_ONLY	0x00
 
 /* Turns off any message-printing/exiting options.  */
 #define ARGP_SILENT    (ARGP_NO_EXIT | ARGP_NO_ERRS | ARGP_NO_HELP)

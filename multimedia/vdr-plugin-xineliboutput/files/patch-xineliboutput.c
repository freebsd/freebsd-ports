--- a/xineliboutput.c.orig	2012-05-11 07:37:27 UTC
+++ b/xineliboutput.c
@@ -104,7 +104,7 @@ const char cmdLineHelp[] =
 "                           fbfe    (framebuffer)\n"
 "                           none    (only remote frontends)\n"
 "  -r PORT   --remote=PORT  Listen PORT for remote clients\n"
-"                           (default "LISTEN_PORT_S")\n"
+"                           (default " LISTEN_PORT_S ")\n"
 "                           none or 0 disables remote mode\n"
 "                           Also local interface address can be specified:\n"
 "                           --remote=<ip>:<port>  (default is all interfaces)\n"

--- inc/na/help.h.orig	Tue Aug 18 18:40:40 1998
+++ inc/na/help.h	Thu Sep 18 20:10:32 2003
@@ -298,14 +298,13 @@
 , "Show the AppleTalk subset of port parameters"
 #endif /* NA */
 },
-#ifndef NA
+/* XXXCDC: was ifndef NA, need this or annex_params[26] is null! */
 {"arpt_kill_timer",	BOX_PARAM,	ARPT_TTKILLC
 #ifdef NA
 , "Time for a temporary created entry in an ARP Table to remain active.\n\t\
 Value in minutes: range 1 to 255, default value is 20 minutes."
 #endif /* NA */
 },
-#endif
 {"arap_v42bis",		PORT_PARAM,	P_ARAP_V42BIS
 #ifdef NA
 , "Allow the enabling of V.42bis compression\n\t\

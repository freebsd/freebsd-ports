--- wminfo.c.orig	Thu Feb 19 21:22:58 2004
+++ wminfo.c	Thu Feb 19 21:24:27 2004
@@ -142,9 +142,11 @@
 	
 	strcpy(plugin_exec,"sh ");
 	strcat(plugin_exec,plugin);
-	strcat(plugin_exec," > wmiout.tmp");
-	strcpy(plugin_out,getenv("PWD"));
-	strcat(plugin_out,"/wmiout.tmp");
+	strcat(plugin_exec," > ");
+	strcat(plugin_exec,plugin);
+	strcat(plugin_exec,".tmp");
+	strcpy(plugin_out,plugin);
+	strcat(plugin_out,".tmp");
 	
 	createXBMfromXPM(wminfo_mask_bits, wminfo_xpm, wminfo_mask_width, wminfo_mask_height);
 	openXwindow(argc, argv, wminfo_xpm, wminfo_mask_bits, wminfo_mask_width, wminfo_mask_height);


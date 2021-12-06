--- portconfig.c.orig	2021-11-29 17:22:25 UTC
+++ portconfig.c
@@ -253,9 +253,6 @@ main(int argc, char *argv[])
 			theme = BSDDIALOG_THEME_DIALOG;
 			newstr = "+";
 		}
-		else if (strcasecmp(env, "magenta") == 0) {
-			theme = BSDDIALOG_THEME_MAGENTA;
-		}
 		else if (strcasecmp(env, "blackwhite") == 0) {
 			theme = BSDDIALOG_THEME_BLACKWHITE;
 		}
@@ -290,10 +287,10 @@ main(int argc, char *argv[])
 	confhelp.title = "HELP";
 	confhelp.hfile = NULL;
 	for (;;) {
-		output = bsddialog_mixedlist(conf, helpmsg, h, w, 0, ngroups,
+		output = bsddialog_mixedlist(&conf, helpmsg, h, w, 0, ngroups,
 		    groups, NULL, NULL);
 		if (output == BSDDIALOG_HELP) {
-			output = bsddialog_textbox(confhelp, conf.hfile, 0, 0);
+			output = bsddialog_textbox(&confhelp, conf.hfile, 0, 0);
 			if(output == BSDDIALOG_ERROR)
 				break;
 		}

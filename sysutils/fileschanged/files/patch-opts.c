--- src/opts.c.orig	Mon Feb 23 01:17:30 2004
+++ src/opts.c	Sun May 23 17:52:10 2004
@@ -19,6 +19,7 @@
 const char filelist_option_explanation[]="Monitor the list of filenames inside FILE";
 const char filechangetimeout_option_explanation[]="Delay showing changed files for N seconds (Def=2)";
 const char showaction_option_explanation[]="Also display action when displaying altered files";
+const char execcmd_option_explanation[]="Execute COMMAND when file altered (COMMAND action filename)";
 
 struct arguments_t arguments;
 static struct argp_option options[] = 
@@ -34,6 +35,7 @@
 	{"filelist", 'l',"FILENAME",0, filelist_option_explanation, 3},
 	{"timeout", 't',"N",0, filechangetimeout_option_explanation, 4},
 	{"prepend-action", 'p',0,0, showaction_option_explanation, 5},
+	{"execcmd", 'x',"COMMAND",0, execcmd_option_explanation, 6},
 	{ 0 }
 };
 
@@ -93,6 +95,9 @@
 			arguments->fileschanged.filechangetimeout=atoi(arg);
 			if (arguments->fileschanged.filechangetimeout<=1)
 				arguments->fileschanged.filechangetimeout=-1;
+			break;
+		case 'x':
+			arguments->fileschanged.exec_command=strdup(arg);
 			break;
 		case ARGP_KEY_INIT:
 			free_arguments();

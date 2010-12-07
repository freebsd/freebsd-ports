--- scponly.c	2008/01/15 06:30:20	1.45
+++ scponly.c	2008/03/08 18:57:48	1.46
@@ -91,16 +91,18 @@
 
 #ifdef RSYNC_COMPAT
 struct option rsync_longopts[] = {
+	/* options we need to know about that are safe */
+	{"server",			0,	0,		(int)'s'},
 	/* I use 'e' for val here because that's what's listed in cmd_arg_t->badarg  */
-	{"rsh", 			1,	0,		(int)'e'},
+	{"rsh", 			1,	0,		(int)'r'},
 	/* the following are disabled because they use daemon mode */
-	{"daemon",			0,	0,		(int)'e'},
-	{"rsync-path",		1,	0,		(int)'e'},
-	{"address",			1,	0,		(int)'e'},
-	{"port",			1,	0,		(int)'e'},
-	{"sockopts",		1,	0,		(int)'e'},
-	{"config",			1,	0,		(int)'e'},
-	{"no-detach",		0,	0,		(int)'e'},
+	{"daemon",			0,	0,		(int)'d'},
+	{"rsync-path",		1,	0,		(int)'d'},
+	{"address",			1,	0,		(int)'d'},
+	{"port",			1,	0,		(int)'d'},
+	{"sockopts",		1,	0,		(int)'d'},
+	{"config",			1,	0,		(int)'d'},
+	{"no-detach",		0,	0,		(int)'d'},
 	{ NULL,				0,	NULL,	0 },
 	};
 #endif
@@ -157,7 +159,7 @@
 	{ PROG_SCP, 		1, 				1,				"SoF",			"dfl:prtvBCc:i:P:q1246S:o:F:", empty_longopts },
 #endif
 #ifdef RSYNC_COMPAT
-	{ PROG_RSYNC, 		1, 				0,				"e",			"e:",			rsync_longopts },
+	{ PROG_RSYNC, 		1, 				0,				"rde",			"e::",			rsync_longopts },
 #endif	
 #ifdef UNISON_COMPAT	
 	{ PROG_UNISON, 		0, 				0,				"-rshcmd",		NULL, 			empty_longopts },

--- src/control.c.old	2011-07-14 21:48:59.000000000 +0200
+++ src/control.c	2011-07-14 21:54:55.000000000 +0200
@@ -395,12 +395,12 @@
 };
 
 static KEY_BINDING tab_log[] = {
-	{ 0, 0,  WCH_CTRL('M'),	cx_pan_home,		0	},
-	{ 1, 0,  KEY_LEFT,		cx_log_left,		0	},
-	{ 1, 0,  KEY_RIGHT,		cx_log_right,		0	},
-	{ 1, 0,  KEY_HOME,		cx_log_home,		0	},
-	{ 0, 0,  L'm',			cx_log_mark,		0	},
-	{ 0, 1,  L'l',			cx_trans_return,	0	},
+	{ 0, 0,  WCH_CTRL('M'),	cx_pan_home,		0			},
+	{ 1, 0,  KEY_LEFT,		cx_log_left,		OPT_NOFILT	},
+	{ 1, 0,  KEY_RIGHT,		cx_log_right,		OPT_NOFILT	},
+	{ 1, 0,  KEY_HOME,		cx_log_home,		OPT_NOFILT	},
+	{ 0, 0,  L'm',			cx_log_mark,		OPT_NOFILT	},
+	{ 0, 1,  L'l',			cx_trans_return,	0			},
 	END_TABLE
 };
 

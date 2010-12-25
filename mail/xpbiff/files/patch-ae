--- xpbiff.c.orig	1994-10-27 15:42:52.000000000 +0900
+++ xpbiff.c	2010-11-17 14:40:26.457077878 +0900
@@ -60,6 +60,7 @@
 
 #include "config.h"
 
+#include <paths.h>	/* _PATH_MAILDIR */
 #include <X11/Intrinsic.h>
 #include <X11/StringDefs.h>
 #include <X11/Shell.h>
@@ -74,6 +75,12 @@
 #endif
 #endif /* SUN_AUDIO */
 
+#ifdef BSD_AUDIO
+#include <sys/soundcard.h>
+#define MAX_SOUND_VOL 95
+#define MIN_SOUND_VOL 05
+#endif
+
 #ifndef X11R3
 #include <X11/Xaw/Box.h>
 #include <X11/Xaw/Label.h>
@@ -116,7 +123,11 @@
 #include <sys/types.h>
 #include <sys/stat.h>
 #include <stdio.h>
+#include <stdlib.h>
 #include <math.h>
+#ifdef HAVE_GETPWUID
+#include <pwd.h>
+#endif /* HAVE_GETPWUID */
 
 #ifdef YOUBIN
 
@@ -149,11 +160,7 @@
 
 #ifndef YOUBIN
 
-#ifdef USG
-#define SPOOLPATH	"/usr/mail/"
-#else
-#define SPOOLPATH	"/usr/spool/mail/"
-#endif
+#define SPOOLPATH	_PATH_MAILDIR
 
 #else /* YOUBIN */
 
@@ -256,34 +263,11 @@
  */
 
 GC		gcArrive, gcNo, gcAnimate, gcAnimateBack;
-#ifdef XPM
-Pixmap		arrivePixmaps[2], noPixmaps[2];
-#define arrivePixmap	arrivePixmaps[0]
-#define noPixmap	noPixmaps[0]
-#else
-Pixmap		arrivePixmap, noPixmap;
-#endif
 Pixmap		workPixmap;
 int		width, height;
 unsigned char	current_status = NO;
 unsigned char	showing_header = 0;
 long		mail_size = 0;
-#ifndef YOUBIN
-XtIntervalId	polling_id;
-#endif
-Pixel		colors[4];
-#ifndef YOUBIN
-char		spool_path[100];
-int		polling_time;
-#endif
-int		popup_time;
-
-Boolean		raise;
-Boolean		stay_raised;
-Boolean		animate;
-Boolean		popup;
-Boolean		bell;
-Boolean		popdown;
 
 unsigned int	Arrive_pixmap_width, Arrive_pixmap_height;
 unsigned int	Arrive_pixmap_depth;
@@ -291,24 +275,11 @@
 unsigned int	No_pixmap_width, No_pixmap_height;
 unsigned int	No_pixmap_depth;
 
-Boolean		mono;
-String		popupGeometry;
-
-#ifndef YOUBIN
-String		prefers;
-
-String		spoolPath;
-#endif
-
-#ifdef MHSCAN
-Boolean		mhscan;
-String		scanCommand;
-String		scanCommandPath;
-#endif
-
-#ifdef SHAPE
-Boolean		shape;
-Pixmap		noPixmapMask, arrivePixmapMask;
+#ifdef YOUBIN
+XtIntervalId	timeout_id;
+#else
+XtIntervalId	polling_id;
+char		spool_path[100];
 #endif
 
 static String		fallback_resources[] = {
@@ -324,86 +295,125 @@
     NULL
 };
 
-#ifdef SUN_AUDIO
-String mail_sndfile;
-int volume;
+typedef struct _appRes {
+#ifdef XPM
+    Pixmap	arrivePixmaps[2];
+    Pixmap	noPixmaps[2];
+#define	arrivePixmap	arrivePixmaps[0]
+#define	noPixmap	noPixmaps[0]
+#else
+    Pixmap	arrivePixmap;
+    Pixmap	noPixmap;
 #endif
-
+    Pixel	colors[4];
+#ifndef YOUBIN
+    String	prefers;
+    int		polling_time;
+    String	spoolPath;
+#endif
+    Boolean	mono;
+    String	popupGeometry;
+    Boolean	raise;
+    Boolean	stay_raised;
+    Boolean	animate;
+    Boolean	popup;
+    int		popup_time;
+    Boolean	bell;
+    Boolean	popdown;
 #ifdef YOUBIN
-Boolean		use_pipe;
-String		server;
-Boolean		preserve;
-XtIntervalId	timeout_id;
+    Boolean	use_pipe;
+    String	server;
+    Boolean	preserve;
+#endif
+#ifdef MHSCAN
+    Boolean	mhscan;
+    String	scanCommand;
+    String	scanCommandPath;
 #endif
+#ifdef SHAPE
+    Boolean	shape;
+    Pixmap	arrivePixmapMask;
+    Pixmap	noPixmapMask;
+#endif
+#if (defined(SUN_AUDIO) || defined(BSD_AUDIO))
+    String	mail_sndfile;
+    int		volume;
+#endif
+} AppResourcesRec, *AppResources;
+
+#define	SetResOffset(n, field)	resources[n].resource_offset = ((char *)&appResources.field - (char *)&appResources)
+#define	offset(field)	XtOffset(struct _appRes *, field)
+
+AppResourcesRec appResources;
 
 static XtResource	resources[] = {
     {"arrivePixmap", "ArrivePixmap", RPixmap2, sizeof(Pixmap2),
-	 (Cardinal)&arrivePixmap, XtRString, "None"},
+     offset(arrivePixmap), XtRString, "None"},
     {"nomailPixmap", "NomailPixmap", RPixmap2, sizeof(Pixmap2),
-	 (Cardinal)&noPixmap, XtRString, "None"},
+     offset(noPixmap), XtRString, "None"},
     {"nomailForeground", "NomailForeground", XtRPixel, sizeof(Pixel),
-	 (Cardinal)&colors[0], XtRString, "black"},
+     offset(colors[0]), XtRString, "black"},
     {"nomailBackground", "NomailBackground", XtRPixel, sizeof(Pixel),
-	 (Cardinal)&colors[1], XtRString, "cyan"},
+     offset(colors[1]), XtRString, "cyan"},
     {"arriveForeground", "ArriveForeground", XtRPixel, sizeof(Pixel),
-	 (Cardinal)&colors[2], XtRString, "yellow"},
+     offset(colors[2]), XtRString, "yellow"},
     {"arriveBackground", "ArriveBackground", XtRPixel, sizeof(Pixel),
-	 (Cardinal)&colors[3], XtRString, "red"},
+     offset(colors[3]), XtRString, "red"},
 #ifndef YOUBIN
     {"pollingTime", "PollingTime", XtRInt, sizeof(int),
-	 (Cardinal)&polling_time, XtRImmediate, (XtPointer)15000},
+     offset(polling_time), XtRImmediate, (XtPointer)15000},
     {"prefer", "Prefer", XtRString, sizeof(String),
-	 (Cardinal)&prefers, XtRString, (XtPointer)"From Subject"},
+     offset(prefers), XtRString, (XtPointer)"From Subject"},
     {"spoolPath", "SpoolPath", XtRString, sizeof(String),
-	 (Cardinal)&spoolPath, XtRString, None},
+     offset(spoolPath), XtRString, None},
 #endif
     {"mono", "Mono", XtRBoolean, sizeof(Boolean),
-	 (Cardinal)&mono, XtRImmediate, (XtPointer)False},
+     offset(mono), XtRImmediate, (XtPointer)False},
     {"popupGeometry", "PopupGeometry", XtRString, sizeof(String),
-	 (Cardinal)&popupGeometry, XtRString, NULL},
+     offset(popupGeometry), XtRString, NULL},
     {"raise", "Raise", XtRBoolean, sizeof(Boolean),
-	 (Cardinal)&raise, XtRImmediate, (XtPointer)True},
+     offset(raise), XtRImmediate, (XtPointer)True},
     {"stayRaised", "StayRaised", XtRBoolean, sizeof(Boolean),
-	 (Cardinal)&stay_raised, XtRImmediate, (XtPointer)False},
+     offset(stay_raised), XtRImmediate, (XtPointer)False},
     {"animate", "Animate", XtRBoolean, sizeof(Boolean),
-	 (Cardinal)&animate, XtRImmediate, (XtPointer)True},
+     offset(animate), XtRImmediate, (XtPointer)True},
     {"popup", "Popup", XtRBoolean, sizeof(Boolean),
-	 (Cardinal)&popup, XtRImmediate, (XtPointer)True},
+     offset(popup), XtRImmediate, (XtPointer)True},
     {"popupTime", "PopupTime", XtRInt, sizeof(int),
-     (Cardinal)&popup_time, XtRImmediate, (XtPointer)15000},
+     offset(popup_time), XtRImmediate, (XtPointer)15000},
     {"bell", "Bell", XtRBoolean, sizeof(Boolean),
-	 (Cardinal)&bell, XtRImmediate, (XtPointer)True},
+     offset(bell), XtRImmediate, (XtPointer)True},
     {"popdown", "Popdown", XtRBoolean, sizeof(Boolean),
-	 (Cardinal)&popdown, XtRImmediate, (XtPointer)True},
+     offset(popdown), XtRImmediate, (XtPointer)True},
 #ifdef YOUBIN
     {"pipe", "Pipe", XtRBoolean, sizeof(Boolean),
-     (Cardinal)&use_pipe, XtRString, "false"},
+     offset(use_pipe), XtRString, "false"},
     {"server", "Server", XtRString, sizeof(String),
-	(Cardinal)&server, XtRString, YOUBIN_DEFAULT_SERVER_HOST},
+     offset(server), XtRString, YOUBIN_DEFAULT_SERVER_HOST},
     {"preserve", "preserve", XtRBoolean, sizeof(Boolean),
-	(Cardinal)&preserve, XtRString, "true"},
+     offset(preserve), XtRString, "true"},
 #endif
 #ifdef MHSCAN
     {"mhscan", "Mhscan", XtRBoolean, sizeof(Boolean),
-	 (Cardinal)&mhscan, XtRImmediate, (XtPointer)False},
+     offset(mhscan), XtRImmediate, (XtPointer)False},
     {"scanCommand", "ScanCommand", XtRString, sizeof(String),
-	 (Cardinal)&scanCommand, XtRString, DEFAULT_SCAN_COMMAND},
+     offset(scanCommand), XtRString, DEFAULT_SCAN_COMMAND},
     {"scanCommandPath", "ScanCommandPath", XtRString, sizeof(String),
-	 (Cardinal)&scanCommandPath, XtRString, DEFAULT_SCAN_COMMAND_PATH},
+     offset(scanCommandPath), XtRString, DEFAULT_SCAN_COMMAND_PATH},
 #endif
 #ifdef SHAPE
     {"shape", "Shape", XtRBoolean, sizeof(Boolean),
-	 (Cardinal)&shape, XtRImmediate, (XtPointer)False},
+     offset(shape), XtRImmediate, (XtPointer)False},
     {"arrivePixmapMask", "ArrivePixmapMask", XtRBitmap, sizeof(Pixmap),
-	 (Cardinal)&arrivePixmapMask, XtRBitmap, None},
+     offset(arrivePixmapMask), XtRBitmap, None},
     {"nomailPixmapMask", "NomailPixmapMask", XtRBitmap, sizeof(Pixmap),
-	 (Cardinal)&noPixmapMask, XtRBitmap, None},
+     offset(noPixmapMask), XtRBitmap, None},
 #endif
-#ifdef SUN_AUDIO
+#if (defined(SUN_AUDIO) || defined(BSD_AUDIO))
     {"mailSndFile", "MailSndFile", XtRString, sizeof(String),
-     (Cardinal)&mail_sndfile, XtRString, None},
+     offset(mail_sndfile), XtRString, None},
     {"volume", "Volume", XtRInt, sizeof(int),
-     (Cardinal)&volume, XtRString, "33"},
+     offset(volume), XtRString, "33"},
 #endif    
 };
 
@@ -445,7 +455,7 @@
     {"-server",		"*server",		XrmoptionSepArg,	NULL},
     {"-preserve",	"*preserve",		XrmoptionNoArg,		"true"},
 #endif /* YOUBIN */
-#ifdef SUN_AUDIO
+#if (defined(SUN_AUDIO) || defined(BSD_AUDIO))
     {"-sndfile",	"*mailSndFile",		XrmoptionSepArg,	NULL},
     {"-volume",		"*volume",		XrmoptionSepArg,	NULL},
 #endif
@@ -461,6 +471,7 @@
 #ifdef JCONVERT
 static Locale_ent	locale_list[] = {
     {"ja_JP.EUC",	EUC},
+    {"ja_JP.eucJP",	EUC},
     {"ja_JP.SJIS",	SJIS},
     {"ja_JP.jis7",	JIS},
     {"ja_JP.jis8",	JIS},
@@ -485,9 +496,9 @@
     XGCValues		values;
     XtTranslations	newTranslations;
     static XtActionsRec redrawActions[] = {
-	{"expose", (XtCallbackProc) redraw_callback},
-	{"select", (XtCallbackProc) popup_again},
-	{"quit", (XtCallbackProc) quit},
+	{"expose", (XtActionProc) redraw_callback},
+	{"select", (XtActionProc) popup_again},
+	{"quit", (XtActionProc) quit},
     };
 
     static char		*overrideTranslations =
@@ -498,6 +509,9 @@
     int			dummy;
     int			i;
 
+#ifdef HAVE_GETPWUID
+    struct passwd	*pw;
+#endif
 #ifdef JCONVERT
     char		*locale_name;
     Locale_ent		*p;
@@ -514,28 +528,40 @@
 #endif /* !YOUBIN */
 
 #ifdef YOUBIN
-	if ((prog_name = strrchr(argv[0], '/')) != NULL) {
-	    prog_name++;
-	} else {
-	    prog_name = argv[0];
-	}
+    if ((prog_name = strrchr(argv[0], '/')) != NULL) {
+	prog_name++;
+    } else {
+	prog_name = argv[0];
+    }
 #else	/* !YOUBIN */
-    if (spoolPath != NULL && spoolPath[0] != '\0')
-	strcpy(spool_path, spoolPath);
-    else
+    if (appResources.spoolPath != NULL && appResources.spoolPath[0] != '\0') {
+	strcpy(spool_path, appResources.spoolPath);
+    } else {
     	strcpy(spool_path, SPOOLPATH);
-    if (spool_path[strlen(spool_path) - 1] != '/')
+    }
+    if (spool_path[strlen(spool_path) - 1] != '/') {
 	strcat(spool_path, "/");
+    }
+
 #ifdef GETENV_MAIL
-    if (getenv("MAIL") != NULL)
+    if (getenv("MAIL") != NULL) {
 	strcpy(spool_path, getenv("MAIL"));
-    else
-#endif
-#ifndef NO_CUSERID
-	strcat(spool_path, cuserid(NULL));
-#else
+    } else {
+#endif /* GETENV_MAIL */
+
+#ifdef HAVE_GETPWUID
+	pw = getpwuid(getuid());
+	strcat(spool_path, pw->pw_name);
+#elif defined(NO_CUSERID)
 	strcat(spool_path, getenv("USER"));
-#endif
+#else
+	strcat(spool_path, (char *)cuserid(NULL));
+#endif /* NO_CUSERID && HAVE_GETPWUID */
+
+#ifdef GETENV_MAIL
+    }
+#endif /* GETENV_MAIL */
+
 #endif /* !YOUBIN */
 
 #ifdef XI18N
@@ -646,7 +672,7 @@
 	    fprintf(stderr, "		[-server host]\n");
 	    fprintf(stderr, "		[-nopreserve]\n");
 #endif
-#ifdef SUN_AUDIO
+#if (defined(SUN_AUDIO) || defined(BSD_AUDIO))
 	    fprintf(stderr, "		[-sndfile audio_file]\n");
 	    fprintf(stderr, "		[-volume percentage]\n");
 #endif
@@ -659,33 +685,33 @@
 		      convertArgs, XtNumber(convertArgs));
 #endif
 
-    XtGetApplicationResources(toplevel, (caddr_t) NULL,
+    XtGetApplicationResources(toplevel, (XtPointer)&appResources,
 			      resources, XtNumber(resources), NULL, 0);
 
-    if (mono == True) {
-	colors[0] = colors[3] = BlackPixelOfScreen(XtScreen(toplevel));
-	colors[1] = colors[2] = WhitePixelOfScreen(XtScreen(toplevel));
+    if (appResources.mono == True) {
+	appResources.colors[0] = appResources.colors[3] = BlackPixelOfScreen(XtScreen(toplevel));
+	appResources.colors[1] = appResources.colors[2] = WhitePixelOfScreen(XtScreen(toplevel));
     }
 
 #ifndef YOUBIN
-    split_prefer(prefers);
+    split_prefer(appResources.prefers);
 #endif
 
 #ifdef XPM
-    if (arrivePixmapMask == None)
-	arrivePixmapMask = arrivePixmaps[1];
-    if (noPixmapMask == None)
-	noPixmapMask = noPixmaps[1];
+    if (appResources.arrivePixmapMask == None)
+	appResources.arrivePixmapMask = appResources.arrivePixmaps[1];
+    if (appResources.noPixmapMask == None)
+	appResources.noPixmapMask = appResources.noPixmaps[1];
 #endif
 
 #ifdef SHAPE
-    if (shape == True
+    if (appResources.shape == True
        && !XShapeQueryExtension(XtDisplay(toplevel), &dummy, &dummy))
-	shape = False;
+	appResources.shape = False;
 #endif
 
-    if (noPixmap == None) {
-	noPixmap = XCreatePixmapFromBitmapData
+    if (appResources.noPixmap == None) {
+	appResources.noPixmap = XCreatePixmapFromBitmapData
 	    (XtDisplay(toplevel), RootWindowOfScreen(XtScreen(toplevel)),
 	     no_bits, no_width, no_height, 1, 0, 1);
 	No_pixmap_width = no_width;
@@ -695,14 +721,14 @@
     else {
 	Window r;
 	unsigned int x, y, bw;
-	XGetGeometry(XtDisplay(toplevel), noPixmap,
+	XGetGeometry(XtDisplay(toplevel), appResources.noPixmap,
 		     &r, &x, &y,
 		     &No_pixmap_width, &No_pixmap_height,
 		     &bw, &No_pixmap_depth);
     }
 
-    if (arrivePixmap == None) {
-	arrivePixmap = XCreatePixmapFromBitmapData
+    if (appResources.arrivePixmap == None) {
+	appResources.arrivePixmap = XCreatePixmapFromBitmapData
 	    (XtDisplay(toplevel), RootWindowOfScreen(XtScreen(toplevel)),
 	     arrive_bits, arrive_width, arrive_height,
 	     1, 0, 1);
@@ -713,7 +739,7 @@
     else {
 	Window r;
 	unsigned int x, y, bw;
-	XGetGeometry(XtDisplay(toplevel), arrivePixmap,
+	XGetGeometry(XtDisplay(toplevel), appResources.arrivePixmap,
 		     &r, &x, &y,
 		     &Arrive_pixmap_width, &Arrive_pixmap_height,
 		     &bw, &Arrive_pixmap_depth);
@@ -741,14 +767,14 @@
 
     /* Get graphic context	 */
 
-    values.foreground	= colors[0];
-    values.background	= colors[1];
+    values.foreground	= appResources.colors[0];
+    values.background	= appResources.colors[1];
     values.graphics_exposures = False;
     gcNo = XtGetGC(toplevel,
 		   GCForeground | GCBackground | GCGraphicsExposures,
 		   &values);
-    values.foreground	= colors[2];
-    values.background	= colors[3];
+    values.foreground	= appResources.colors[2];
+    values.background	= appResources.colors[3];
     values.graphics_exposures = False;
     gcArrive = XtGetGC(toplevel,
 		       GCForeground | GCBackground | GCGraphicsExposures,
@@ -760,13 +786,13 @@
 			       Arrive_pixmap_width, Arrive_pixmap_height,
 			       DefaultDepthOfScreen(XtScreen(toplevel)));
 
-    values.foreground	= colors[2];
+    values.foreground	= appResources.colors[2];
     values.graphics_exposures = False;
     gcAnimate = XtGetGC(toplevel,
 			GCForeground | GCGraphicsExposures,
 			&values);
 
-    values.foreground	= colors[3];
+    values.foreground	= appResources.colors[3];
     values.graphics_exposures = False;
     gcAnimateBack = XtGetGC(toplevel,
 			    GCForeground | GCGraphicsExposures,
@@ -775,11 +801,11 @@
     /* Interval timer start	 */
 #ifndef YOUBIN
     polling_id = XtAppAddTimeOut(app_con,
-				 (unsigned long) polling_time, Polling, NULL);
+				 (unsigned long) appResources.polling_time, (XtTimerCallbackProc) Polling, NULL);
 #else  /* YOUBIN */
-    if (server == NULL) {
+    if (appResources.server == NULL) {
 	gethostname(serv_name, sizeof(serv_name));
-	server = serv_name;
+	appResources.server = serv_name;
     }
 
     /* make new process group */
@@ -789,9 +815,9 @@
 	    exit(EXIT_FAILURE);
 	}
 
-    if (use_pipe == False) {
+    if (appResources.use_pipe == False) {
 	sprintf(child_process, "%s/%s -b -s %s",
-		BINDIR, CHILD_PROGRAM_NAME, server);
+		BINDIR, CHILD_PROGRAM_NAME, appResources.server);
 	if ((pfile = popen(child_process, "r")) == NULL) {
 	    perror("popen");
 	    exit(EXIT_FAILURE);
@@ -831,21 +857,21 @@
 {
     if (current_status == ARRIVE) {
 	if (Arrive_pixmap_depth == 1)
-	    XCopyPlane(XtDisplay(toplevel), arrivePixmap, XtWindow(biff),
+	    XCopyPlane(XtDisplay(toplevel), appResources.arrivePixmap, XtWindow(biff),
 		       gcArrive,
 		       0, 0, Arrive_pixmap_width, Arrive_pixmap_height, 0, 0, 1);
 	else
-	    XCopyArea(XtDisplay(toplevel), arrivePixmap, XtWindow(biff),
+	    XCopyArea(XtDisplay(toplevel), appResources.arrivePixmap, XtWindow(biff),
 		      gcArrive,
 		      0, 0, Arrive_pixmap_width, Arrive_pixmap_height, 0, 0);
     }
     else {
 	if (No_pixmap_depth == 1)
-	    XCopyPlane(XtDisplay(toplevel), noPixmap, XtWindow(biff),
+	    XCopyPlane(XtDisplay(toplevel), appResources.noPixmap, XtWindow(biff),
 		       gcNo,
 		       0, 0, No_pixmap_width, No_pixmap_height, 0, 0, 1);
 	else
-	    XCopyArea(XtDisplay(toplevel), noPixmap, XtWindow(biff),
+	    XCopyArea(XtDisplay(toplevel), appResources.noPixmap, XtWindow(biff),
 		      gcNo, 0, 0, No_pixmap_width, No_pixmap_height, 0, 0);
     }
 }
@@ -853,9 +879,9 @@
 #ifdef SHAPE
 void shape_window()
 {
-    if (shape == True) {
+    if (appResources.shape == True) {
 	if (current_status == ARRIVE) {
-	    if (arrivePixmapMask == None) {
+	    if (appResources.arrivePixmapMask == None) {
 		XRectangle	rect;
 		rect.x = rect.y = 0;
 		rect.width = Arrive_pixmap_width;
@@ -866,11 +892,11 @@
 	    }
 	    else
 		XShapeCombineMask(XtDisplay(toplevel), XtWindow(toplevel),
-				  ShapeBounding, 0, 0, arrivePixmapMask,
+				  ShapeBounding, 0, 0, appResources.arrivePixmapMask,
 				  ShapeSet);
 	}
 	else {
-	    if (noPixmapMask == None) {
+	    if (appResources.noPixmapMask == None) {
 		XRectangle	rect;
 		rect.x = rect.y = 0;
 		rect.width = No_pixmap_width;
@@ -881,7 +907,7 @@
 	    }
 	    else
 		XShapeCombineMask(XtDisplay(toplevel), XtWindow(toplevel),
-				  ShapeBounding, 0, 0, noPixmapMask,
+				  ShapeBounding, 0, 0, appResources.noPixmapMask,
 				  ShapeSet);
 	}
     }
@@ -915,53 +941,54 @@
 	    /* NEW mail !! */
 	    current_status = ARRIVE;
 	    mail_size = file_stat.st_size;
-	    if (popup == True)
+	    if (appResources.popup == True)
 		mail_header = GetMailHeader();
 	    XtResizeWidget(toplevel, Arrive_pixmap_width, Arrive_pixmap_height, 1);
 	    XtResizeWidget(biff,  Arrive_pixmap_width, Arrive_pixmap_height, 0);
-	    if (raise == True)
+	    if (appResources.raise == True)
 		XRaiseWindow(XtDisplay(toplevel), XtWindow(toplevel));
-	    if (animate == True)
+	    if (appResources.animate == True)
 		AnimateBiff();
 	    redraw_window();
 #ifdef SHAPE
 	    shape_window();
 #endif
-	    if (popup == True)
+	    if (appResources.popup == True)
 		PopupMailHeader(mail_header);
 	    XSync(XtDisplay(toplevel), 0);
-	    if (bell == True)
-		beep(XtDisplay(toplevel), 0);
+	    if (appResources.bell == True)
+		beep(XtDisplay(toplevel));
 	    /*	XBell(XtDisplay(toplevel), 0); */
 	}
 	else if (file_stat.st_size > mail_size) {
 	    mail_size = file_stat.st_size;
-	    if (popup == True)
+	    if (appResources.popup == True)
 		mail_header = GetMailHeader();
 	    /* more come! only ringing bell. */
-	    if (popup == True)
+	    if (appResources.popup == True)
 		BreakPopup(toplevel, (XtPointer) NULL, (XtPointer) NULL);
 	    XtResizeWidget(toplevel,  Arrive_pixmap_width, Arrive_pixmap_height, 1);
 	    XtResizeWidget(biff,  Arrive_pixmap_width, Arrive_pixmap_height, 0);
-	    if (raise == True)
+	    if (appResources.raise == True)
 		XRaiseWindow(XtDisplay(toplevel), XtWindow(toplevel));
-	    if (animate == True)
+	    if (appResources.animate == True)
 		AnimateBiff();
 	    redraw_window();
 #ifdef SHAPE
 	    shape_window();
 #endif
-	    if (popup == True)
+	    if (appResources.popup == True)
 		PopupMailHeader(mail_header);
 	    XSync(XtDisplay(toplevel), 0);
-	    if (bell == True)
-		XBell(XtDisplay(toplevel), 0);
+	    if (appResources.bell == True)
+		beep(XtDisplay(toplevel));
+	    /*	XBell(XtDisplay(toplevel), 0); */
 	}
 	else {
 	    mail_size = file_stat.st_size;
-	    if (raise == True && stay_raised == False)
+	    if (appResources.raise == True && appResources.stay_raised == False)
 		XLowerWindow(XtDisplay(toplevel), XtWindow(toplevel));
-	    if (popup == True)
+	    if (appResources.popup == True)
 		BreakPopup(toplevel, (XtPointer) NULL, (XtPointer) NULL);
 	}
     } else
@@ -974,15 +1001,15 @@
 #ifdef SHAPE
 	    shape_window();
 #endif
-	    if (raise == True && stay_raised == False)
+	    if (appResources.raise == True && appResources.stay_raised == False)
 		XLowerWindow(XtDisplay(toplevel), XtWindow(toplevel));
-	    if (popup == True)
+	    if (appResources.popup == True)
 		BreakPopup(toplevel, (XtPointer) NULL, (XtPointer) NULL);
 	}
     /* No arrive */
 
     polling_id = XtAppAddTimeOut(XtWidgetToApplicationContext(toplevel),
-				 (unsigned long) polling_time, Polling, NULL);
+				 (unsigned long) appResources.polling_time, (XtTimerCallbackProc) Polling, NULL);
 
 }
 #endif /* !YOUBIN */
@@ -995,7 +1022,7 @@
     double	    r, angle, t1, t2, t3, t4;
 
 #ifdef SHAPE
-    if(shape == True) {
+    if(appResources.shape == True) {
 	XRectangle	rect;
 	rect.x = rect.y = 0;
 	rect.width = Arrive_pixmap_width;
@@ -1038,9 +1065,9 @@
 
     /* Create Popup Shell */
 
-    if (popupGeometry != NULL) {
+    if (appResources.popupGeometry != NULL) {
 	arg_count = 0;
-	XtSetArg(args[arg_count], XtNgeometry, popupGeometry);
+	XtSetArg(args[arg_count], XtNgeometry, appResources.popupGeometry);
 	arg_count++;
     }
     else {
@@ -1068,10 +1095,10 @@
     info_base = XtCreateManagedWidget("info_base", boxWidgetClass, header, args,
 				      arg_count);
 
-    if (popdown == True) {
+    if (appResources.popdown == True) {
 	popdown_button = XtCreateManagedWidget("popdown_button", commandWidgetClass, info_base, NULL,
 					       ZERO);
-	XtAddCallback(popdown_button, XtNcallback, BreakPopup, (XtPointer) NULL);
+	XtAddCallback(popdown_button, XtNcallback, (XtCallbackProc) BreakPopup, (XtPointer) NULL);
     }
     arg_count = 0;
     XtSetArg(args[arg_count], XtNlabel, head);
@@ -1131,37 +1158,38 @@
 	    /* the click catchs new mail */
 	    current_status = ARRIVE;
 	    mail_size = file_stat.st_size;
-	    if (popup == True)
+	    if (appResources.popup == True)
 		mail_header = GetMailHeader();
 	    XtResizeWidget(toplevel, Arrive_pixmap_width, Arrive_pixmap_height, 1);
 	    XtResizeWidget(biff, Arrive_pixmap_width, Arrive_pixmap_height, 0);
-	    if (raise == True)
+	    if (appResources.raise == True)
 		XRaiseWindow(XtDisplay(toplevel), XtWindow(toplevel));
-	    if (animate == True)
+	    if (appResources.animate == True)
 		AnimateBiff();
 	    redraw_window();
 #ifdef SHAPE
 	    shape_window();
 #endif
-	    if (popup == True)
+	    if (appResources.popup == True)
 		PopupMailHeader(mail_header);
 	    XSync(XtDisplay(toplevel), 0);
-	    if (bell == True)
-		XBell(XtDisplay(toplevel), 0);
+	    if (appResources.bell == True)
+		beep(XtDisplay(toplevel));
+	    /*	XBell(XtDisplay(toplevel), 0); */
 	}
 	else {
 	    mail_size = file_stat.st_size;
-	    if (popup == True)
+	    if (appResources.popup == True)
 		mail_header = GetMailHeader();
-	    if (popup == True && showing_header)
+	    if (appResources.popup == True && showing_header)
 		BreakPopup(toplevel, (XtPointer) NULL, (XtPointer) NULL);
-	    if (raise == True)
+	    if (appResources.raise == True)
 		XRaiseWindow(XtDisplay(toplevel), XtWindow(toplevel));
 	    redraw_window();
 #ifdef SHAPE
 	    shape_window();
 #endif
-	    if (popup == True)
+	    if (appResources.popup == True)
 		PopupMailHeader(mail_header);
 	    XSync(XtDisplay(toplevel), 0);
 	}
@@ -1169,7 +1197,7 @@
 
     XtRemoveTimeOut(polling_id);
     polling_id = XtAppAddTimeOut(XtWidgetToApplicationContext(toplevel),
-				 (unsigned long) polling_time, Polling, NULL);
+				 (unsigned long) appResources.polling_time, (XtTimerCallbackProc) Polling, NULL);
 }
 #endif /* !YOUBIN */
 
@@ -1749,14 +1777,23 @@
 static void beep (display)
     Display *display; 
 {
-#ifdef SUN_AUDIO
+#if defined(SUN_AUDIO) || defined(BSD_AUDIO)
     int		audiofd, filefd;
-    int		rn, wn, len;
+    int		rn;
+#ifdef SUN_AUDIO
+    int		wn, len;
     unsigned char	buf[256];
     Audio_filehdr	*au_hdr;
     audio_info_t 	ais;
-
-    if (mail_sndfile) {
+#elif defined(BSD_AUDIO)
+    int mixerfd, mixerid, supported;
+    static int bsize;
+    static char *buf;
+    struct stat sbuf;
+    int level, level_tmp;
+#endif
+	
+    if (appResources.mail_sndfile) {
 	audiofd = open( "/dev/audio", O_WRONLY | O_NDELAY ); 
 	if (audiofd < 0)
 	    {
@@ -1766,6 +1803,7 @@
 		return;
 	    }
 
+#ifdef SUN_AUDIO
 	if( ioctl( audiofd, AUDIO_GETINFO, &ais ) )
 	    {
 		fprintf(stderr, "%s: Problem retrieving /dev/audio info.\n",
@@ -1782,15 +1820,34 @@
 	    return;
 	}
 
-	filefd = open(mail_sndfile, O_RDONLY);
+#elif defined(BSD_AUDIO)
+	/* Open the mixer device */
+	mixerfd = open ("/dev/mixer", O_RDWR, 0);
+	if (mixerfd > 0)
+	    {
+		if (appResources.volume > MAX_SOUND_VOL)
+			appResources.volume = MAX_SOUND_VOL;
+		else if (appResources.volume < MIN_SOUND_VOL)
+			appResources.volume = MIN_SOUND_VOL;
+		mixerid = SOUND_MIXER_PCM;
+		    /* storing volume level */
+		ioctl(mixerfd,MIXER_READ(mixerid),&level_tmp);
+
+		level = (appResources.volume << 8) | appResources.volume;
+		ioctl(mixerfd,MIXER_WRITE(mixerid),&level);
+	}
+#endif
+
+	filefd = open(appResources.mail_sndfile, O_RDONLY);
 	if (filefd < 0)
 	    {
 		fprintf(stderr, "%s: Couldn't play file \"%s\"\n", 
-			"Mailbox widget", mail_sndfile);
+			"Mailbox widget", appResources.mail_sndfile);
 		close(audiofd);
 		return;
 	    }
 
+#ifdef SUN_AUDIO
 	/* Read in the audio header */
 	rn = read(filefd, buf, sizeof(Audio_filehdr)); 
 
@@ -1841,12 +1898,28 @@
 		    usleep(1000);
 		}
 	    }
-	close(audiofd);
+#elif defined(BSD_AUDIO)
+	ioctl(audiofd, SNDCTL_DSP_RESET, 0);
+	fstat(filefd, &sbuf);
+	bsize = sbuf.st_size;
+	buf = malloc((u_int)bsize);
+	if ( (rn = read(filefd, buf, bsize)) > 0)
+	    write(audiofd, buf, rn);
+	ioctl(audiofd, SNDCTL_DSP_SYNC, 0);
+	free(buf);
+	if (mixerfd > 0)
+	    {
+		    /* restoring volume level */
+		ioctl(mixerfd,MIXER_WRITE(mixerid),&level_tmp);
+		close(mixerfd);
+	    }
+#endif
+	close(audiofd); 
 	close(filefd);
     }
     else
-    XBell (display, volume);
-#else  /* !SUN_AUDIO */
+    XBell (display, 0);
+#else  /* !SUN_AUDIO && !BSD_AUDIO */
     XBell (display, 0);
 #endif /* SUN_AUDIO */
     return;
@@ -1888,7 +1961,7 @@
 
     if (mail_size > saved_mail_size) {
 	/* NEW mail */
-	if (popup == True || *cp == ' ') {
+	if (appResources.popup == True || *cp == ' ') {
 	    date = strtol(cp, &cp2, 10);
 	    if (*cp2 == '\0' || isspace(*cp2)) {
 		get_mail_header((*cp2 == '\0') ? NULL : (cp2 + 1));
@@ -1898,31 +1971,31 @@
 	current_status = ARRIVE;
 	XtResizeWidget(toplevel, Arrive_pixmap_width, Arrive_pixmap_height, 1);
 	XtResizeWidget(biff, Arrive_pixmap_width, Arrive_pixmap_height, 0);
-	if (popup == True) {
+	if (appResources.popup == True) {
 	    BreakPopup(toplevel, (XtPointer) NULL, (XtPointer) NULL);
 	}
-	if (raise == True) {
+	if (appResources.raise == True) {
 	    XRaiseWindow(XtDisplay(toplevel), XtWindow(toplevel));
 	}
-	if (animate == True && mail_header != NULL) {
+	if (appResources.animate == True && mail_header != NULL) {
 	    AnimateBiff();
 	}
 	redraw_window();
 #ifdef SHAPE
 	shape_window();
 #endif
-	if (popup == True) {
+	if (appResources.popup == True) {
 	    if (mail_header != NULL) {
 		PopupMailHeader(mail_header);
 
-		if (popup_time)
+		if (appResources.popup_time)
 		    XtAppAddTimeOut(XtWidgetToApplicationContext(toplevel),
-				    (unsigned long) popup_time, BreakPopup, NULL);
+				    (unsigned long) appResources.popup_time, (XtTimerCallbackProc) BreakPopup, NULL);
 	    }
 	}
 	XSync(XtDisplay(toplevel), 0);
-	if (bell == True) {
-	    beep(XtDisplay(toplevel), 0);
+	if (appResources.bell == True) {
+	    beep(XtDisplay(toplevel));
 	}
     } else if (mail_size < saved_mail_size){
 	/* No mail */
@@ -1934,10 +2007,10 @@
 #ifdef SHAPE
 	shape_window();
 #endif
-	if (popup == True) {
+	if (appResources.popup == True) {
 	    BreakPopup(toplevel, (XtPointer) NULL, (XtPointer) NULL);
 	}
-	if (raise == True && stay_raised == False) {
+	if (appResources.raise == True && appResources.stay_raised == False) {
 	    XLowerWindow(XtDisplay(toplevel), XtWindow(toplevel));
 	}
 	free(mail_header);
@@ -1974,7 +2047,7 @@
 	if (header_count > 1 || *cp == '\0')	break;
 	cp = strtok(NULL, "\n");
     }
-    if (preserve == False) {
+    if (appResources.preserve == False) {
 	free(mail_header);
 	mail_header = NULL;
     }
@@ -2024,16 +2097,16 @@
     if (current_status == ARRIVE) {
 	redraw_window();
 
-	if (popup == True) {
+	if (appResources.popup == True) {
 	    BreakPopup(toplevel, (XtPointer) NULL, (XtPointer) NULL);
 	    if (mail_header != NULL) {
 		PopupMailHeader(mail_header);
 	    }
-	    if (popup_time)
+	    if (appResources.popup_time)
 		XtAppAddTimeOut(XtWidgetToApplicationContext(toplevel),
-				(unsigned long) popup_time, BreakPopup, NULL);
+				(unsigned long) appResources.popup_time, (XtTimerCallbackProc) BreakPopup, NULL);
 	}
-	if (raise == True) {
+	if (appResources.raise == True) {
 	    XRaiseWindow(XtDisplay(toplevel), XtWindow(toplevel));
 	}
 #ifdef SHAPE

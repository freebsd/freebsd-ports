--- coolmail-1.3/system/X11/display_list.c.orig	1996-01-11 19:14:30.000000000 +0100
+++ coolmail-1.3/system/X11/display_list.c	2009-04-08 09:14:08.000000000 +0200
@@ -41,9 +41,9 @@
 extern char mailfile_str[]; /* to obtain the command and mail file.    */
 extern unsigned int frames;
 
+extern int  cool_vol;	
 #ifdef AUDIO
 extern char *sndfile; /* same hack as above */
-extern int  cool_vol;	
 void audio_beep(void);
 #endif
 
@@ -156,9 +156,9 @@
 #ifdef AUDIO
    XtResource soundfile  = {"soundFile", "SoundFile", XtRString,
                             sizeof(str), 0, XtRString, sndfile};
+#endif
    XtResource volume   = {"volume", "Volume", XtRInt,
                           sizeof(cool_vol), 0, XtRInt, &cool_vol};
-#endif
 
    XtGetApplicationResources(toplevel, &str, &mailcmd, 1, NULL, 0);
    strcpy(command_str, str);
@@ -175,11 +175,11 @@
    XtGetApplicationResources(toplevel, &str, &soundfile, 1, NULL, 0);
    if(str)
       sndfile = (char *)strdup(str);
+#endif
 
    XtGetApplicationResources(toplevel, &cool_vol, &volume, 1, NULL, 0);
    if      (cool_vol < 0)   cool_vol = 0;
    else if (cool_vol > 100) cool_vol = 100;
-#endif
 
 }
 
@@ -308,7 +308,7 @@
    else	/* no sound file chosen then use system bell */
       XBell(XtDisplay(main_gfx_w), cool_vol);
 #else
-   XBell(XtDisplay(main_gfx_w), 50);
+   XBell(XtDisplay(main_gfx_w), cool_vol);
 #endif
 }
 

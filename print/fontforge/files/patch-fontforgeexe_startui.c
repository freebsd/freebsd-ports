--- fontforgeexe/startui.c.orig	2019-08-01 08:28:36 UTC
+++ fontforgeexe/startui.c
@@ -1099,10 +1099,6 @@ int fontforge_main( int argc, char **argv ) {
     CheckIsScript(argc,argv); /* Will run the script and exit if it is a script */
 					/* If there is no UI, there is always a script */
 			                /*  and we will never return from the above */
-#ifdef FONTFORGE_CAN_USE_GDK
-    gdk_init(&argc, &argv);
-    gdk_set_allowed_backends("win32,quartz,x11");
-#endif
     if ( load_prefs==NULL ||
 	    (strcasecmp(load_prefs,"Always")!=0 &&	/* Already loaded */
 	     strcasecmp(load_prefs,"Never")!=0 ))
@@ -1185,7 +1181,10 @@ int fontforge_main( int argc, char **argv ) {
 	}
 #endif
     }
-
+#ifdef FONTFORGE_CAN_USE_GDK
+    gdk_init(&argc, &argv);
+    gdk_set_allowed_backends("win32,quartz,x11");
+#endif
     ensureDotFontForgeIsSetup();
 #if defined(__MINGW32__) && !defined(_NO_LIBCAIRO)
     //Load any custom fonts for the user interface

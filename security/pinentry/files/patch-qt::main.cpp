--- qt/main.cpp.orig	Thu Jan 30 09:25:31 2003
+++ qt/main.cpp	Thu Jan 30 09:26:10 2003
@@ -157,6 +157,12 @@
 #ifdef FALLBACK_CURSES
   if( pinentry_have_display (argc, argv) ) {
 #endif
+	// Work around non-standard handling of DISPLAY
+	for( int i = 1; i < argc; ++i ) {
+    	if( !strcmp( "--display", argv[i] ) ) {
+        	argv[i] = "-display";
+    	}
+  	}
     return qt_main( argc, argv );
 #ifdef FALLBACK_CURSES
   } else {

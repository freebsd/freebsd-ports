--- src/main.cpp	2026-09-07 18:54:34 UTC
+++ src/main.cpp
@@ -50,6 +50,12 @@
 
 	lyx::support::os::init(argc, &argv);
 
+	// LyX handles all text as UTF-8 internally, including the
+	// translated messages. Make the console output follow the
+	// encoding of the user's locale.
+	lyx::transcodeToLocale(cout);
+	lyx::transcodeToLocale(cerr);
+
 	lyx::LyX the_lyx_instance;
 
 	return the_lyx_instance.exec(argc, argv);

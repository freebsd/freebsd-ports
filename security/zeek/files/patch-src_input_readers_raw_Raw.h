--- src/input/readers/raw/Raw.h.orig	2022-07-05 21:28:35 UTC
+++ src/input/readers/raw/Raw.h
@@ -55,6 +55,7 @@ class Raw : public ReaderBackend (private)
 	bool firstrun;
 	time_t mtime;
 	ino_t ino;
+	dev_t dev;
 
 	// options set from the script-level.
 	std::string separator;

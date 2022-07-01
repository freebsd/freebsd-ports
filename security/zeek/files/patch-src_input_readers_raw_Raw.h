--- src/input/readers/raw/Raw.h.orig	2022-07-01 20:33:23 UTC
+++ src/input/readers/raw/Raw.h
@@ -52,6 +52,7 @@ class Raw : public ReaderBackend { (private)
 	bool firstrun;
 	time_t mtime;
 	ino_t ino;
+	dev_t dev;
 
 	// options set from the script-level.
 	std::string separator;

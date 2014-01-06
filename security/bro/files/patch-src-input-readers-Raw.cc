--- src/input/readers/Raw.cc.orig	2014-01-06 21:04:06.000000000 +0200
+++ src/input/readers/Raw.cc	2014-01-06 21:04:13.000000000 +0200
@@ -352,7 +352,7 @@
 		fname = source.substr(0, fname.length() - 1);
 		}
 
-	map<const char*, const char*>::const_iterator it = info.config.find("stdin"); // data that is sent to the child process
+	ReaderInfo::config_map::const_iterator it = info.config.find("stdin"); // data that is sent to the child process
 	if ( it != info.config.end() )
 		{
 		stdin_string = it->second;

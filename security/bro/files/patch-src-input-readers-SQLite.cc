--- src/input/readers/SQLite.cc.orig	2014-01-06 21:07:44.000000000 +0200
+++ src/input/readers/SQLite.cc	2014-01-06 21:08:00.000000000 +0200
@@ -85,7 +85,7 @@
 	fullpath.append(".sqlite");
 
 	string query;
-	map<const char*, const char*>::const_iterator it = info.config.find("query");
+	ReaderInfo::config_map::const_iterator it = info.config.find("query");
 	if ( it == info.config.end() )
 		{
 		Error(Fmt("No query specified when setting up SQLite data source. Aborting.", info.source));

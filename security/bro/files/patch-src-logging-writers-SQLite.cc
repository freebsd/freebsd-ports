--- src/logging/writers/SQLite.cc.orig	2014-01-06 21:08:34.000000000 +0200
+++ src/logging/writers/SQLite.cc	2014-01-06 21:08:45.000000000 +0200
@@ -126,7 +126,7 @@
 	fullpath.append(".sqlite");
 	string tablename;
 
-	map<const char*, const char*>::const_iterator it = info.config.find("tablename");
+	WriterInfo::config_map::const_iterator it = info.config.find("tablename");
 	if ( it == info.config.end() )
 		{
 		MsgThread::Info(Fmt("tablename configuration option not found. Defaulting to path %s", info.path));

--- logfile.cc.orig	Wed Oct  2 22:41:50 2002
+++ logfile.cc	Wed Oct  2 22:42:09 2002
@@ -58,12 +58,13 @@
 {
 	/* open the file */
 	umask(077);
-	logfile = new std::fstream(filename, std::ios::out|std::ios::app, 0644);
+	logfile = new std::fstream(filename, std::ios::out|std::ios::app);
 	if(logfile == NULL)
 	{
 		std::cerr << "Error: LogFile::Open:open(): " << strerror(errno) <<"\n";
 		exit(-1);
 	}
+	chmod(filename, 0644);
 }
 
 

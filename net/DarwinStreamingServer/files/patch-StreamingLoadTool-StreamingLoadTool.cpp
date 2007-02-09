--- StreamingLoadTool/StreamingLoadTool.cpp.orig	Thu May 26 12:36:32 2005
+++ StreamingLoadTool/StreamingLoadTool.cpp	Sat Feb 10 04:01:06 2007
@@ -191,7 +191,7 @@
 	UInt32* theURLIndexArray = NEW UInt32[theURLIndexArraySize];
 	UInt32 theNumURLs = 0;
     char* controlID = NULL;
-	char			ch = 0;
+	int			ch = 0;
 	//
 	// Read our command line options
 	while( (ch = getopt(argc, argv, "vf:c:i:d")) != -1 )

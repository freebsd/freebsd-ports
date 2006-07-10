--- src/main.cpp	Sun Jun 25 12:48:31 2006
+++ src/main.cpp.port	Mon Jul 10 14:08:33 2006
@@ -682,7 +682,7 @@
 
 		setup_file.replace_escape_sequences = true;
 
-		try{  setup_file.read( DATA_DIR "/ump.conf" );  }
+		try{  setup_file.read( "%%PREFIX%%/etc/ump.conf" );  }
 		catch(...) { }
 
 		snprintf(filename,100,"%s/.ump",getenv("HOME"));

--- src/main.cpp	Sat Apr 22 01:10:27 2006
+++ src/main.cpp.port	Wed May  3 15:13:45 2006
@@ -692,7 +692,7 @@
 		
 		setup_file.replace_escape_sequences = true;
 
-		try{  setup_file.read( DATA_DIR "/ump.conf" );  }
+		try{  setup_file.read( "%%PREFIX%%/etc/ump.conf" );  }
 		catch(...) { }
 
 		snprintf(filename,100,"%s/.ump",getenv("HOME"));

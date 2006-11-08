--- src/main.cpp	Mon Oct  2 11:05:33 2006
+++ src/main.cpp.port	Tue Nov  7 22:17:00 2006
@@ -695,7 +695,7 @@
 
 		setup_file.replace_escape_sequences = true;
 
-		try{  setup_file.read( DATA_DIR "/ump.conf" );  }
+		try{  setup_file.read( "%%PREFIX%%/etc/ump.conf" );  }
 		catch(...) { std_settings = false; }
 
 		snprintf(filename,100,"%s/.ump",getenv("HOME"));

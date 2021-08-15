--- Input_std.c.orig	2018-09-12 02:18:32 UTC
+++ Input_std.c
@@ -85,7 +85,7 @@ void Input_std(char *file)
 
   input_string("System.CurrrentDirectory",filepath,"./");
   input_string("System.Name",filename,"default");
-  input_string("DATA.PATH",DFT_DATA_PATH,"../DFT_DATA13");
+  //input_string("DATA.PATH",DFT_DATA_PATH,"../DFT_DATA13");
   input_int("level.of.stdout", &level_stdout,1);
   input_int("level.of.fileout",&level_fileout,1);
   input_logical("memory.usage.fileout",&memoryusage_fileout,0); /* default=off */

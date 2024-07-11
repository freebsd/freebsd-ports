--- Input_std.c.orig	2021-08-12 15:44:59 UTC
+++ Input_std.c
@@ -97,7 +97,7 @@ void Input_std(char *file)
   sprintf(filepath,"%s/",filepath);
 
   input_string("System.Name",filename,"default");
-  input_string("DATA.PATH",DFT_DATA_PATH,"../DFT_DATA19");
+  //input_string("DATA.PATH",DFT_DATA_PATH,"../DFT_DATA19");
   input_int("level.of.stdout", &level_stdout,1);
   input_int("level.of.fileout",&level_fileout,1);
   input_logical("memory.usage.fileout",&memoryusage_fileout,0); /* default=off */

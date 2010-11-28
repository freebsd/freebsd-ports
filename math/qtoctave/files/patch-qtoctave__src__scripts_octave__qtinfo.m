--- ./qtoctave/src/scripts_octave/qtinfo.m.orig	2010-01-25 16:19:50.000000000 +0300
+++ ./qtoctave/src/scripts_octave/qtinfo.m	2010-11-28 19:09:57.670497066 +0300
@@ -1,5 +1,5 @@
 function qtinfo()
-	command=sprintf("qtinfo %s > /dev/null", info_file);
+	command=sprintf("qtoctave_info %s > /dev/null", info_file);
 	printf("Starting info: %s\n", command);
 	system(command, 1, "async");
-endfunction
\ No newline at end of file
+endfunction

--- ./qtoctave/src/scripts_octave/qtinfo.m.orig	2011-01-06 21:48:08.000000000 +0000
+++ ./qtoctave/src/scripts_octave/qtinfo.m	2012-12-15 22:23:03.542899718 +0000
@@ -1,5 +1,5 @@
 function qtinfo()
 	command=sprintf("qtoctave-info-reader %s > /dev/null", info_file);
 	printf("Starting info: %s\n", command);
-	system(command, 1, "async");
+	system(command, "async");
 endfunction

--- bsdbktr_tvtune.c.orig	Sun Jan  4 23:43:58 2004
+++ bsdbktr_tvtune.c	Mon Jan  5 21:19:01 2004
@@ -159,35 +159,35 @@
  * Shows propper utility usage then exits
  */
 void show_usage(char *programname) {
-	printf("
-			
-Usage:
-	%s [-d TVTUNERDEVICE] [-s CHANNELSET] -c CHANNEL
-	%s -h
-	%s -l
-	%s -v
-
-Where:
-
-	-c
-		The channel to tune to
-
-	-d
-		The device to open for tuning.  If unspecified defaults to /dev/tuner0
-
-	-h
-		This help you're seeing
-
-	-l
-		List all valid CHANNELSETs you could pass to the -s option
-
-	-s
-		The channel set configuration to use.  If unspecified defaults to NABCST
-
-	-v
-		Show program version
-
-", programname, programname, programname, programname);
+	printf("\n"\
+"			\n"\
+"Usage:\n"\
+"	%s [-d TVTUNERDEVICE] [-s CHANNELSET] -c CHANNEL\n"\
+"	%s -h\n"\
+"	%s -l\n"\
+"	%s -v\n"\
+"\n"\
+"Where:\n"\
+"\n"\
+"	-c\n"\
+"		The channel to tune to\n"\
+"\n"\
+"	-d\n"\
+"		The device to open for tuning.  If unspecified defaults to /dev/tuner0\n"\
+"\n"\
+"	-h\n"\
+"		This help you're seeing\n"\
+"\n"\
+"	-l\n"\
+"		List all valid CHANNELSETs you could pass to the -s option\n"\
+"\n"\
+"	-s\n"\
+"		The channel set configuration to use.  If unspecified defaults to NABCST\n"\
+"\n"\
+"	-v\n"\
+"		Show program version\n"\
+"\n"\
+"\n", programname, programname, programname, programname);
 	exit(1);
 }
 

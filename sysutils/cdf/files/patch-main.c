--- src/main.c.orig	Fri Oct 22 19:18:32 2004
+++ src/main.c	Fri Oct 22 19:18:43 2004
@@ -38,6 +38,8 @@
 	
 	
 	blocksize = 1048576;
+
+	read_config_file(expand_filename("~/.cdfrc"));
 	
      	while ((ch = getopt(argc, argv, "gkmt:v")) != -1)
         	switch (ch) {

--- cmdwatch.c.orig	2009-06-04 01:07:21.000000000 -0700
+++ cmdwatch.c	2009-06-04 01:11:52.000000000 -0700
@@ -163,12 +163,11 @@
   command_length = strlen(command);
   for (;optind<argc;optind++)
     {
-      int s = strlen(argv[optind]);
-      char *endp = &command[command_length];
-      *endp = ' ';
-      command_length += s + 1;
-      command = realloc(command, command_length+1);
-      strcpy(endp+1, argv[optind]);
+      int nlen = command_length + 1 + strlen(argv[optind]);
+      command = realloc(command, nlen + 1);
+      command[command_length] = ' ';
+      strcpy(command + command_length + 1, argv[optind]);
+      command_length = nlen;
     }
 
   get_terminal_size();

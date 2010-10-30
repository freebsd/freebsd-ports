--- src/exec.c.orig	2010-10-27 20:19:48.000000000 +0300
+++ src/exec.c	2010-10-27 20:19:52.000000000 +0300
@@ -93,6 +93,7 @@
 		} else {
 			close(1);
 		}
+		close(parentend);
 		dup(childend);	//by dupping childend, the returned fd will have close-on-exec turned off
 		execl("/bin/sh", "sh", "-c", command, (char *) NULL);
 		_exit(EXIT_FAILURE); //child should die here, (normally execl will take care of this but it can fail)
@@ -156,7 +157,7 @@
 		int length;
 
 		length = fread(buf, 1, size, fp);
-		pclose(fp);
+		fclose(fp);
 		buf[length] = '\0';
 		if (length > 0 && buf[length - 1] == '\n') {
 			buf[length - 1] = '\0';
@@ -320,7 +321,7 @@
 			ed->buffer = malloc(text_buffer_size);
 
 		length = fread(ed->buffer, 1, text_buffer_size, fp);
-		pclose(fp);
+		fclose(fp);
 
 		output = ed->buffer;
 		output[length] = '\0';

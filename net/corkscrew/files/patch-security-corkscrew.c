--- corkscrew.c.orig	2001-08-23 20:27:32.000000000 +0200
+++ corkscrew.c	2010-08-21 10:26:23.000000000 +0200
@@ -201,9 +201,8 @@
 				fprintf(stderr, "Error opening %s: %s\n", argv[5], strerror(errno));
 				exit(-1);
 			} else {
-				char line[4096];
-				fscanf(fp, "%s", line);
-				up = malloc(sizeof(line));
+				char line[1024];
+				fscanf(fp, "%1023s", line);
 				up = line;
 				fclose(fp);
 			}
@@ -249,11 +248,12 @@
 		/* there's probably a better way to do this */
 		if (setup == 0) {
 			if (FD_ISSET(csock, &rfd)) {
-				len = read(csock, buffer, sizeof(buffer));
+				len = read(csock, buffer, sizeof(buffer) -1);
 				if (len<=0)
 					break;
 				else {
-					sscanf(buffer,"%s%d%[^\n]",version,&code,descr);
+					buffer[len] = '\0';
+					sscanf(buffer,"%256s%3d%[^\n]",version,&code,descr);
 					if ((strncmp(version,"HTTP/",5) == 0) && (code >= 200) && (code < 300))
 						setup = 1;
 					else {

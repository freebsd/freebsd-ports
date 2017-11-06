--- src/safecopy.c.orig	2017-02-07 19:49:05 UTC
+++ src/safecopy.c
@@ -900,7 +900,7 @@ int main(int argc, char ** argv) {
 		fprintf(stdout, "File size: %llu\n", (long long) statusvars->filesize );
 	} else {
 		fprintf(stderr, "Filesize not reported by stat(), trying seek().\n");
-		statusvars->source = open(configvars->sourcefile, O_RDONLY | O_RSYNC);
+		statusvars->source = open(configvars->sourcefile, O_RDONLY | O_SYNC);
 		if (statusvars->source) {
 			statusvars->filesize = lseek(statusvars->source, 0, SEEK_END);
 			close(statusvars->source);
@@ -1691,7 +1691,7 @@ int main(int argc, char ** argv) {
 			for ( statusvars->cseeks = 0; statusvars->cseeks < statusvars->seeks ; statusvars->cseeks ++) {
 				debug(DEBUG_SEEK, "debug: forced head realignment\n");
 				// note. must use O_RSYNC since with O_DIRECT / raw devices, lseek to end of file might not work
-				statusvars->source = open(configvars->sourcefile, O_RDONLY | O_NONBLOCK | O_RSYNC );
+				statusvars->source = open(configvars->sourcefile, O_RDONLY | O_NONBLOCK | O_SYNC );
 				if (statusvars->source) {
 					lseek(statusvars->source, 0, SEEK_SET);
 					select_for_reading(statusvars->source, configvars, statusvars);
@@ -1699,7 +1699,7 @@ int main(int argc, char ** argv) {
 					read(statusvars->source, statusvars->databuffer , statusvars->blocksize );
 					close(statusvars->source);
 				}
-				statusvars->source = open(configvars->sourcefile, O_RDONLY | O_NONBLOCK | O_RSYNC );
+				statusvars->source = open(configvars->sourcefile, O_RDONLY | O_NONBLOCK | O_SYNC );
 				if (statusvars->source) {
 					lseek(statusvars->source,- statusvars->blocksize , SEEK_END);
 					select_for_reading(statusvars->source, configvars, statusvars);

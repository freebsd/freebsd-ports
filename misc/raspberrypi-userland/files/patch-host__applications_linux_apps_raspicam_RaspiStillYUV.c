--- host_applications/linux/apps/raspicam/RaspiStillYUV.c.orig	2022-06-28 11:40:06 UTC
+++ host_applications/linux/apps/raspicam/RaspiStillYUV.c
@@ -46,9 +46,7 @@ SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH D
  * We use the RaspiPreview code to handle the generic preview
  */
 
-// We use some GNU extensions (basename)
-#define _GNU_SOURCE
-
+#include <libgen.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
@@ -287,7 +285,7 @@ static void dump_status(RASPISTILLYUV_STATE *state)
  * @param state Pointer to state structure to assign any discovered parameters to
  * @return non-0 if failed for some reason, 0 otherwise
  */
-static int parse_cmdline(int argc, const char **argv, RASPISTILLYUV_STATE *state)
+static int parse_cmdline(int argc, char **argv, RASPISTILLYUV_STATE *state)
 {
    // Parse the command line arguments.
    // We are looking for --<something> or -<abbreviation of something>
@@ -1186,7 +1184,7 @@ static void rename_file(RASPISTILLYUV_STATE *state, FI
 /**
  * main
  */
-int main(int argc, const char **argv)
+int main(int argc, char **argv)
 {
    // Our main data storage vessel..
    RASPISTILLYUV_STATE state;

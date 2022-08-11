--- host_applications/linux/apps/raspicam/RaspiStill.c.orig	2022-06-28 11:46:30 UTC
+++ host_applications/linux/apps/raspicam/RaspiStill.c
@@ -46,9 +46,7 @@ SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH D
  * We use the RaspiCamControl code to handle the specific camera settings.
  */
 
-// We use some GNU extensions (asprintf, basename)
-#define _GNU_SOURCE
-
+#include <libgen.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <ctype.h>
@@ -445,7 +443,7 @@ static void dump_status(RASPISTILL_STATE *state)
  * @param state Pointer to state structure to assign any discovered parameters to
  * @return non-0 if failed for some reason, 0 otherwise
  */
-static int parse_cmdline(int argc, const char **argv, RASPISTILL_STATE *state)
+static int parse_cmdline(int argc, char **argv, RASPISTILL_STATE *state)
 {
    // Parse the command line arguments.
    // We are looking for --<something> or -<abbreviation of something>
@@ -1756,7 +1754,7 @@ static void rename_file(RASPISTILL_STATE *state, FILE 
 /**
  * main
  */
-int main(int argc, const char **argv)
+int main(int argc, char **argv)
 {
    // Our main data storage vessel..
    RASPISTILL_STATE state;

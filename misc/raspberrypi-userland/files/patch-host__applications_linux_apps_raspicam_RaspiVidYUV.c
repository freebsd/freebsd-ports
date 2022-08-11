--- host_applications/linux/apps/raspicam/RaspiVidYUV.c.orig	2022-06-28 11:42:24 UTC
+++ host_applications/linux/apps/raspicam/RaspiVidYUV.c
@@ -49,9 +49,7 @@ SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH D
  * We use the RaspiPreview code to handle the generic preview
 */
 
-// We use some GNU extensions (basename)
-#define _GNU_SOURCE
-
+#include <libgen.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
@@ -325,7 +323,7 @@ static void dump_status(RASPIVIDYUV_STATE *state)
  * @param state Pointer to state structure to assign any discovered parameters to
  * @return Non-0 if failed for some reason, 0 otherwise
  */
-static int parse_cmdline(int argc, const char **argv, RASPIVIDYUV_STATE *state)
+static int parse_cmdline(int argc, char **argv, RASPIVIDYUV_STATE *state)
 {
    // Parse the command line arguments.
    // We are looking for --<something> or -<abbreviation of something>
@@ -1210,7 +1208,7 @@ static int wait_for_next_change(RASPIVIDYUV_STATE *sta
 /**
  * main
  */
-int main(int argc, const char **argv)
+int main(int argc, char **argv)
 {
    // Our main data storage vessel..
    RASPIVIDYUV_STATE state;

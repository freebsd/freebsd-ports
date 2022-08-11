--- host_applications/linux/apps/raspicam/RaspiVid.c.orig	2022-06-28 11:41:40 UTC
+++ host_applications/linux/apps/raspicam/RaspiVid.c
@@ -47,9 +47,7 @@ SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH D
  * We use the RaspiPreview code to handle the (generic) preview window
  */
 
-// We use some GNU extensions (basename)
-#define _GNU_SOURCE
-
+#include <libgen.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
@@ -449,7 +447,7 @@ static void dump_status(RASPIVID_STATE *state)
  * @param state Pointer to state structure to assign any discovered parameters to
  * @return Non-0 if failed for some reason, 0 otherwise
  */
-static int parse_cmdline(int argc, const char **argv, RASPIVID_STATE *state)
+static int parse_cmdline(int argc, char **argv, RASPIVID_STATE *state)
 {
    // Parse the command line arguments.
    // We are looking for --<something> or -<abbreviation of something>
@@ -2034,7 +2032,7 @@ static int wait_for_next_change(RASPIVID_STATE *state)
 /**
  * main
  */
-int main(int argc, const char **argv)
+int main(int argc, char **argv)
 {
    // Our main data storage vessel..
    RASPIVID_STATE state;

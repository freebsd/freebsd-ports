--- tags.c.orig	2011-09-08 01:02:56.000000000 +0800
+++ tags.c	2011-09-08 01:25:14.000000000 +0800
@@ -42,7 +42,7 @@ static const char rcsid[] =
 #endif /* not lint */
 
 #include <sys/types.h>
-#include <sys/queue.h>
+#include "queue.h"
 
 #include <ctype.h>
 #include <stdio.h>
@@ -67,6 +67,7 @@ static ctagsearch(), gtagsearch();
  * loading the file named by tagfile, tagsearch() should be called to
  * set the current position to the tag.
  */
+void
 findtag(tag)
 	char *tag;	/* The tag to load */
 {
@@ -143,6 +144,7 @@ prevtag(number)
  * succesfully passed to findtag() or chosen with nexttag() and prevtag().
  * An error message will be printed if unsuccessful.
  */
+void
 tagsearch()
 {
 	switch(tagstyle) {
@@ -426,7 +428,7 @@ findgtag(tag)
 	/* Get our data from global(1) */
 	snprintf(command, sizeof(command),
 	    "(global -x '%s'; global -xr '%s') 2>/dev/null", tag, tag);
-	if (fp = popen(command, "r")) {
+	if ((fp = popen(command, "r"))) {
 		while (fgets(buf, sizeof(buf), fp)) {
 			char *name, *file, *line;
 

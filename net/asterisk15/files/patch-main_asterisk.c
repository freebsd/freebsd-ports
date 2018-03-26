--- main/asterisk.c.orig	2018-03-15 16:31:26 UTC
+++ main/asterisk.c
@@ -3991,7 +3991,7 @@ int main(int argc, char *argv[])
 	 *
 	 * \todo Document these options
 	 */
-	optind = 0;
+	optind = 1;
 	while ((c = getopt(argc, argv, getopt_settings)) != -1) {
 		/*!\note Please keep the ordering here to alphabetical, capital letters
 		 * first.  This will make it easier in the future to select unused

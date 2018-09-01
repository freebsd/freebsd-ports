--- src/query.cc.orig	2018-09-01 10:32:12 UTC
+++ src/query.cc
@@ -56,7 +56,7 @@ queryCmd()
 	if (!find_hint_and_def(hint, def)) {
 		return false;
 	}
-	def_word[0] = '\0';
+	def_word[0] = NULL;
 	chop_into_words(def, def_word, &def_words, NCHAR);
 	// Strip off double-quotes form list of defaults
 	for (unsigned int i = 0; i < def_words; i++) {

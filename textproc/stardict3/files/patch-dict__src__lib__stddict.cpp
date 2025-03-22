--- dict/src/lib/stddict.cpp.orig	2014-06-23 01:27:19 UTC
+++ dict/src/lib/stddict.cpp
@@ -32,6 +32,7 @@
 #include <glib.h>
 #include <glib/gi18n.h>
 #include <glib/gstdio.h>
+#include <stdlib.h>
 #include <algorithm>
 #include <memory>

@@ -2532,12 +2533,12 @@ bool Libs::LookupSynonymSimilarWord(const gchar* sWord
 		}
 		// Upper the first character and lower others.
 		if (!bFound) {
-			gchar *nextchar = g_utf8_next_char(sWord);
+			const gchar *nextchar = g_utf8_next_char(sWord);
 			gchar *firstchar = g_utf8_strup(sWord, nextchar - sWord);
-			nextchar = g_utf8_strdown(nextchar, -1);
-			casestr = g_strdup_printf("%s%s", firstchar, nextchar);
+			gchar *nextDownchar = g_utf8_strdown(nextchar, -1);
+			casestr = g_strdup_printf("%s%s", firstchar, nextDownchar);
 			g_free(firstchar);
-			g_free(nextchar);
+			g_free(nextDownchar);
 			if (strcmp(casestr, sWord)) {
 				bLookup = oLib[iLib]->LookupSynonym(casestr, iIndex, iIndex_suggest, CollationLevel, servercollatefunc);
 				if(bLookup)
@@ -2642,12 +2643,12 @@ bool Libs::LookupSimilarWord(const gchar* sWord, glong
 		}
 		// Upper the first character and lower others.
 		if (!bFound) {
-			gchar *nextchar = g_utf8_next_char(sWord);
+			const gchar *nextchar = g_utf8_next_char(sWord);
 			gchar *firstchar = g_utf8_strup(sWord, nextchar - sWord);
-			nextchar = g_utf8_strdown(nextchar, -1);
-			casestr = g_strdup_printf("%s%s", firstchar, nextchar);
+			gchar *nextDownchar = g_utf8_strdown(nextchar, -1);
+			casestr = g_strdup_printf("%s%s", firstchar, nextDownchar);
 			g_free(firstchar);
-			g_free(nextchar);
+			g_free(nextDownchar);
 			if (strcmp(casestr, sWord)) {
 				if(LookupSimilarWordTryWord(casestr, sWord, servercollatefunc, iLib, iIndex, idx_suggest, best_match))
 					bFound=true;

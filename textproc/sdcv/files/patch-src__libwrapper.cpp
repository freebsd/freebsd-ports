--- src/libwrapper.cpp.orig
+++ src/libwrapper.cpp
@@ -24,6 +24,7 @@
 
 #include <glib/gi18n.h>
 #include <map>
+#include <cstring>
 
 #include "utils.hpp"
 
@@ -117,7 +118,6 @@
 		switch (*p++) {
 		case 'm':
 		case 'l': //need more work...
-		case 'g':
 			sec_size = strlen(p);
 			if (sec_size) {
 				res+="\n";
@@ -127,6 +127,7 @@
 			}
 			sec_size++;
 			break;
+		case 'g':
 		case 'x':
 			sec_size = strlen(p);
 			if (sec_size) {
@@ -208,6 +209,15 @@
 
 void Library::LookupData(const string &str, TSearchResultList& res_list)
 {
+#if defined(_LIBCPP_VERSION)
+	std::vector<std::vector<gchar *> > drl(ndicts());
+	if (!Libs::LookupData(str.c_str(), &drl[0]))
+		return;
+	for (int idict=0; idict<ndicts(); ++idict)
+		for (gchar *res : drl[idict]) {
+			SimpleLookup(res, res_list);
+			g_free(res);
+#else
 	std::vector<gchar *> drl[ndicts()];
 	if (!Libs::LookupData(str.c_str(), drl))
 		return;
@@ -215,6 +225,7 @@
 		for (std::vector<gchar *>::size_type j=0; j<drl[idict].size(); ++j) {
 			SimpleLookup(drl[idict][j], res_list);
 			g_free(drl[idict][j]);
+#endif
 		}
 }
 

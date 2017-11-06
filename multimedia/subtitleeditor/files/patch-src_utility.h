--- src/utility.h.orig	2014-02-12 22:03:00 UTC
+++ src/utility.h
@@ -72,7 +72,7 @@ bool from_string(const std::string &src,
 	std::istringstream s(src);
 	// return s >> dest != 0;
 
-	bool state = s >> dest != 0;
+	bool state = static_cast<bool>(s >> dest);
 
 	if(!state)
 		se_debug_message(SE_DEBUG_UTILITY, "string:'%s'failed.", src.c_str());
@@ -92,7 +92,7 @@ bool from_string(const Glib::ustring &sr
 	std::istringstream s(src);
 	// return s >> dest != 0;
 
-	bool state = s >> dest != 0;
+	bool state = static_cast<bool>(s >> dest);
 
 	if(!state)
 		se_debug_message(SE_DEBUG_UTILITY, "string:'%s'failed.", src.c_str());

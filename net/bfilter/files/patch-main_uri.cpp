
$FreeBSD$

--- main/uri.cpp.orig	Sat Jul 17 12:40:25 2004
+++ main/uri.cpp	Sat Jul 17 12:41:06 2004
@@ -122,29 +122,29 @@
 		m_is_relative_path = false;
 		std::string::size_type pos = base.m_raw_path.rfind('/');
 		if (pos == std::string::npos) {
-			m_raw_path = relative.m_raw_path;
+			//m_raw_path = "";
 		} else {
 			m_raw_path = base.m_raw_path.substr(0, pos+1);
 			// pos+1 is for including the trailing slash
-			std::string rel_path = relative.m_raw_path;
-			while (true) {
-				if (rel_path.substr(0, 2) == "./") {
-					rel_path.erase(0, 2);
-				} else if (rel_path.substr(0, 3) == "../") {
-					rel_path.erase(0, 3);
-					std::string::size_type pos1 = m_raw_path.rfind('/', m_raw_path.length()-2);
-					// length()-2 is needed to skip the trailing slash
-					if (pos1 == std::string::npos) {
-						m_raw_path.erase();
-					} else {
-						m_raw_path.erase(pos1+1);
-					}
+		}
+		std::string rel_path = relative.m_raw_path;
+		while (true) {
+			if (rel_path.substr(0, 2) == "./") {
+				rel_path.erase(0, 2);
+			} else if (rel_path.substr(0, 3) == "../") {
+				rel_path.erase(0, 3);
+				std::string::size_type pos1 = m_raw_path.rfind('/', m_raw_path.length()-2);
+				// length()-2 is needed to skip the trailing slash
+				if (pos1 == std::string::npos) {
+					m_raw_path.erase();
 				} else {
-					break;
+					m_raw_path.erase(pos1+1);
 				}
+			} else {
+				break;
 			}
-			m_raw_path += rel_path;
 		}
+		m_raw_path += rel_path;
 	}
 	m_has_query = relative.m_has_query;
 	m_raw_query = relative.m_raw_query;

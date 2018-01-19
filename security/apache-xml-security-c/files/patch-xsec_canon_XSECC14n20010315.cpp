Index: xsec/canon/XSECC14n20010315.cpp
===================================================================
--- xsec/canon/XSECC14n20010315.cpp	(revision 1821687)
+++ xsec/canon/XSECC14n20010315.cpp	(working copy)
@@ -1148,7 +1148,7 @@
 						// Is this the default?
 						if (currentName.sbStrcmp("xmlns") == 0 &&
 							(!m_XPathSelection || m_XPathMap.hasNode(tmpAtts->item(i))) &&
-							!currentValue.sbStrcmp("") == 0)
+							currentValue.sbStrcmp("") != 0)
 							xmlnsFound = true;
 
 						// A namespace node - See if we need to output
@@ -1297,7 +1297,7 @@
 				// Is this the default?
 				if (currentName.sbStrcmp("xmlns") == 0 &&
 					(!m_XPathSelection || m_XPathMap.hasNode(nsnode)) &&
-					!currentValue.sbStrcmp("") == 0)
+					currentValue.sbStrcmp("") != 0)
 					xmlnsFound = true;
 
 				// A namespace node - See if we need to output

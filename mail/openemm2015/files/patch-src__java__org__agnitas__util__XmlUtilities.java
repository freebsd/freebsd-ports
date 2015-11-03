--- src/java/org/agnitas/util/XmlUtilities.java.orig	2015-10-24 14:59:57 UTC
+++ src/java/org/agnitas/util/XmlUtilities.java
@@ -278,7 +278,7 @@ public class XmlUtilities {
 			logger.error(e.getClass().getSimpleName(), e);
 			throw new Exception("ErrorConstException.XML_PROCESSING " + e.getClass().getSimpleName() + " " + e.getMessage(), e);
 		} catch (IOException e) {
-			logger.error(e.getClass().getSimpleName() + " während der XML-Verarbeitung", e);
+			logger.error(e.getClass().getSimpleName() + " w\u00e4hrend der XML-Verarbeitung", e);
 			throw new Exception("ErrorConstException.XML_PROCESSING " + e.getClass().getSimpleName() + " " + e.getMessage(), e);
 		}
 	}

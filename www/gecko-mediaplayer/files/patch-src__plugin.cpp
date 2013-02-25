Index: src/plugin.cpp
===================================================================
--- src/plugin.cpp	(revision 516)
+++ src/plugin.cpp	(revision 517)
@@ -250,12 +250,16 @@
     case NPERR_STREAM_NOT_SEEKABLE:
         return "Stream Not Seekable";
         break;
+#ifdef NPERR_TIME_RANGE_NOT_SUPPORTED    
     case NPERR_TIME_RANGE_NOT_SUPPORTED:
         return "Time Range Not Supported";
         break;
+#endif
+#ifdef NPERR_MALFORMED_SITE       
     case NPERR_MALFORMED_SITE:
         return "Malformed Site";
         break;
+#endif            
     default:
         return "Unknown NPError Code";
         break;

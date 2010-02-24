--- content/html/document/src/nsHTMLContentSink.cpp.orig	2010-02-23 09:57:05.000000000 +0000
+++ content/html/document/src/nsHTMLContentSink.cpp	2010-02-23 09:57:43.000000000 +0000
@@ -1630,12 +1630,6 @@
 
       DidAddContent(node, PR_FALSE);
 
-#ifdef DEBUG
-      if (mPreAppend &&
-          SINK_LOG_TEST(gSinkLogModuleInfo, SINK_ALWAYS_REFLOW)) {
-        mSink->ForceReflow();
-      }
-#endif /* DEBUG */
       return rv;
     }
   }

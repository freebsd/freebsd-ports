--- src/ThreadTasks.cpp.orig	2011-11-20 19:08:59.000000000 +0100
+++ src/ThreadTasks.cpp	2012-10-13 12:33:01.000000000 +0200
@@ -193,6 +193,9 @@
 						% m_filename );
 			}
 		}
+		// Backported from r10793
+		// delete hashset now to free memory
+		AICHHashSet->FreeHashSet();
 	}
 
 	if ((m_toHash == EH_AICH) && !TestDestroy()) {

--- src/HLServerList.cpp.orig	2007-08-03 13:52:50.000000000 +0200
+++ src/HLServerList.cpp	2007-08-03 13:53:27.000000000 +0200
@@ -73,7 +73,7 @@
 	m_nSkipRequests = 0;
 
 	// initialize challenge number (should be random)
-	m_nChallengeSeed    = (int) &m_pHeadDummyItem;
+	m_nChallengeSeed    = (intptr_t) &m_pHeadDummyItem;
 }
 
 
@@ -604,7 +604,7 @@
 		if(pItem != NULL)
 		{
 			// get a fresh, random id
-			pItem->m_nChallengeId = GetRandomChallenge((int)&pItem, (int)nTimestamp);
+			pItem->m_nChallengeId = GetRandomChallenge((intptr_t)&pItem, (int)nTimestamp);
 		}
 	}
 

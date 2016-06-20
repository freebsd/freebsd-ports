--- src/HLServerList.cpp.orig	2016-06-20 15:57:45 UTC
+++ src/HLServerList.cpp
@@ -73,7 +73,7 @@ HLServerList::HLServerList(int nMaxItems
 	m_nSkipRequests = 0;
 
 	// initialize challenge number (should be random)
-	m_nChallengeSeed    = (int) &m_pHeadDummyItem;
+	m_nChallengeSeed    = (intptr_t) &m_pHeadDummyItem;
 }
 
 
@@ -604,7 +604,7 @@ HLServerListItem* HLServerList::HeartBea
 		if(pItem != NULL)
 		{
 			// get a fresh, random id
-			pItem->m_nChallengeId = GetRandomChallenge((int)&pItem, (int)nTimestamp);
+			pItem->m_nChallengeId = GetRandomChallenge((intptr_t)&pItem, (int)nTimestamp);
 		}
 	}
 

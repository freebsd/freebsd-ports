--- src/sphinxrt.cpp.orig	2018-02-03 10:48:40 UTC
+++ src/sphinxrt.cpp
@@ -4796,7 +4796,7 @@ int RtIndex_t::DebugCheck ( FILE * fp )
 			if ( !tWord.m_uDocs || !tWord.m_uHits || tWord.m_uHits<tWord.m_uDocs )
 			{
 				sWord[sizeof(sWord)-1] = '\0';
-				LOC_FAIL(( fp, "invalid docs/hits (segment=%d, word=%d, read_wordid="UINT64_FMT
+				LOC_FAIL(( fp, "invalid docs/hits (segment=%d, word=%d, read_wordid=" UINT64_FMT
 					", read_word=%s, docs=%u, hits=%u)",
 					iSegment, nWordsRead, (uint64_t)tWord.m_uWordID,
 					sWord+1, tWord.m_uDocs, tWord.m_uHits ));

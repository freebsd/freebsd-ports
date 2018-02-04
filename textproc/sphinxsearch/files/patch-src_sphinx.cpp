--- src/sphinx.cpp.orig	2018-02-03 10:17:51 UTC
+++ src/sphinx.cpp
@@ -8346,8 +8346,8 @@ void CSphReader::ResetError()
 #if PARANOID
 
 #define SPH_VARINT_DECODE(_type,_getexpr) \
-	register DWORD b = 0; \
-	register _type v = 0; \
+	DWORD b = 0; \
+	_type v = 0; \
 	int it = 0; \
 	do { b = _getexpr; v = ( v<<7 ) + ( b&0x7f ); it++; } while ( b&0x80 ); \
 	assert ( (it-1)*7<=sizeof(_type)*8 ); \
@@ -8356,8 +8356,8 @@ void CSphReader::ResetError()
 #else
 
 #define SPH_VARINT_DECODE(_type,_getexpr) \
-	register DWORD b = _getexpr; \
-	register _type res = 0; \
+	DWORD b = _getexpr; \
+	_type res = 0; \
 	while ( b & 0x80 ) \
 	{ \
 		res = ( res<<7 ) + ( b & 0x7f ); \
@@ -8722,8 +8722,8 @@ SphWordID_t CSphBin::ReadVLB ()
 
 DWORD CSphBin::UnzipInt ()
 {
-	register int b = 0;
-	register DWORD v = 0;
+	int b = 0;
+	DWORD v = 0;
 	do
 	{
 		b = ReadByte();
@@ -8736,8 +8736,8 @@ DWORD CSphBin::UnzipInt ()
 
 SphOffset_t CSphBin::UnzipOffset ()
 {
-	register int b = 0;
-	register SphOffset_t v = 0;
+	int b = 0;
+	SphOffset_t v = 0;
 	do
 	{
 		b = ReadByte();
@@ -11536,8 +11536,8 @@ bool CSphHitBuilder::cidxDone ( int iMemLimit, int iMi
 
 inline int encodeVLB ( BYTE * buf, DWORD v )
 {
-	register BYTE b;
-	register int n = 0;
+	BYTE b;
+	int n = 0;
 
 	do
 	{
@@ -23566,9 +23566,9 @@ SphWordID_t CSphDictKeywords::HitblockGetID ( const ch
 		}
 
 		// crc matches, check keyword
-		register int iWordLen = iLen;
-		register const char * a = pEntry->m_pKeyword;
-		register const char * b = sWord;
+		int iWordLen = iLen;
+		const char * a = pEntry->m_pKeyword;
+		const char * b = sWord;
 		while ( *a==*b && iWordLen-- )
 		{
 			if ( !*a || !iWordLen )
@@ -24874,7 +24874,7 @@ static inline DWORD HtmlEntityHash ( const BYTE * str,
 		421, 421, 421, 421, 421, 421, 421
 	};
 
-	register int hval = len;
+	int hval = len;
 	switch ( hval )
 	{
 		default:	hval += asso_values [ str[4] ];
@@ -25257,11 +25257,11 @@ static inline int HtmlEntityLookup ( const BYTE * str,
 
 	if ( len<=MAX_WORD_LENGTH && len>=MIN_WORD_LENGTH )
 	{
-		register int key = HtmlEntityHash ( str, len );
+		int key = HtmlEntityHash ( str, len );
 		if ( key<=MAX_HASH_VALUE && key>=0 )
 			if ( len==lengthtable[key] )
 		{
-			register const char * s = wordlist[key].m_sName;
+			const char * s = wordlist[key].m_sName;
 			if ( *str==*s && !memcmp ( str+1, s+1, len-1 ) )
 				return wordlist[key].m_iCode;
 		}
@@ -27817,7 +27817,7 @@ const char * CSphSource_SQL::SqlUnpackColumn ( int iFi
 				{
 					m_bUnpackFailed = true;
 					sphWarn ( "failed to unpack '%s', invalid column size (size=%d), "
-						"docid="DOCID_FMT, SqlFieldName(iIndex), iPackedLen, m_tDocInfo.m_uDocID );
+						"docid=" DOCID_FMT, SqlFieldName(iIndex), iPackedLen, m_tDocInfo.m_uDocID );
 				}
 				return NULL;
 			}
@@ -27833,7 +27833,7 @@ const char * CSphSource_SQL::SqlUnpackColumn ( int iFi
 				{
 					m_bUnpackOverflow = true;
 					sphWarn ( "failed to unpack '%s', column size limit exceeded (size=%d),"
-						" docid="DOCID_FMT, SqlFieldName(iIndex), (int)uSize, m_tDocInfo.m_uDocID );
+						" docid=" DOCID_FMT, SqlFieldName(iIndex), (int)uSize, m_tDocInfo.m_uDocID );
 				}
 				return NULL;
 			}

--- libs/pfl/common/classes/StPGPRefs.h.orig	1999-08-05 01:22:16.000000000 -0700
+++ libs/pfl/common/classes/StPGPRefs.h	2008-08-31 01:11:35.000000000 -0700
@@ -64,27 +64,27 @@ protected:
 
 #ifdef Included_pgpKeys_h
 	typedef StPGPRef<PGPKeySetRef>	StPGPKeySetRef;
-	inline void StPGPKeySetRef::Dispose() { PGPFreeKeySet(mRef); }
+	template <> inline void StPGPKeySetRef::Dispose() { PGPFreeKeySet(mRef); }
 
 	typedef StPGPRef<PGPKeyListRef>	StPGPKeyListRef;
-	inline void StPGPKeyListRef::Dispose() { PGPFreeKeyList(mRef); }
+	template <> inline void StPGPKeyListRef::Dispose() { PGPFreeKeyList(mRef); }
 
 	typedef StPGPRef<PGPKeyIterRef>	StPGPKeyIterRef;
-	inline void StPGPKeyIterRef::Dispose() { PGPFreeKeyIter(mRef); }
+	template <> inline void StPGPKeyIterRef::Dispose() { PGPFreeKeyIter(mRef); }
 #endif
 
 #ifdef Included_pgpHashing_h
 	typedef StPGPRef<PGPHashContextRef>	StPGPHashContextRef;
-	inline void StPGPHashContextRef::Dispose() { PGPFreeHashContext(mRef); }
+	template <> inline void StPGPHashContextRef::Dispose() { PGPFreeHashContext(mRef); }
 #endif
 
 #ifdef Included_PGPtls_h
 	typedef StPGPRef<PGPtlsSessionRef>	StPGPtlsSessionRef;
-	inline void StPGPtlsSessionRef::Dispose() { PGPFreeTLSSession(mRef); }
+	template <> inline void StPGPtlsSessionRef::Dispose() { PGPFreeTLSSession(mRef); }
 #endif
 
 #ifdef Included_pgpMemoryMgr_h
-	inline void StPGPRef<PGPByte *>::Dispose() { PGPFreeData(mRef); }
+	template <> inline void StPGPRef<PGPByte *>::Dispose() { PGPFreeData(mRef); }
 	class StPGPDataRef	:	public StPGPRef<PGPByte *> {
 	public:
 						StPGPDataRef() { }
@@ -104,22 +104,22 @@ protected:
 	};
 
 	typedef StPGPRef<PGPMemoryMgrRef>	StPGPMemoryMgrRef;
-	inline void StPGPMemoryMgrRef::Dispose() { PGPFreeMemoryMgr(mRef); }
+	template <> inline void StPGPMemoryMgrRef::Dispose() { PGPFreeMemoryMgr(mRef); }
 #endif
 
 #ifdef Included_pgpSockets_h
 	typedef StPGPRef<PGPSocketRef>	StPGPSocketRef;
-	inline void StPGPSocketRef::Dispose() { PGPCloseSocket(mRef); }
+	template <> inline void StPGPSocketRef::Dispose() { PGPCloseSocket(mRef); }
 #endif
 
 #ifdef Included_pflPrefs_h
 	typedef StPGPRef<PGPPrefRef>	StPGPPrefRef;
-	inline void StPGPPrefRef::Dispose() { PGPClosePrefFile(mRef); }
+	template <> inline void StPGPPrefRef::Dispose() { PGPClosePrefFile(mRef); }
 #endif
 
 #ifdef Included_pgpIO_h
 	typedef StPGPRef<PGPIORef>	StPGPIORef;
-	inline void StPGPIORef::Dispose() { PGPFreeIO(mRef); }
+	template <> inline void StPGPIORef::Dispose() { PGPFreeIO(mRef); }
 #endif
 
 #undef STATIC_CAST

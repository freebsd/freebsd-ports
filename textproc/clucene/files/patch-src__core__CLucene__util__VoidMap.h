--- src/core/CLucene/util/VoidMap.h.orig	2011-03-16 20:21:07.000000000 -0400
+++ src/core/CLucene/util/VoidMap.h	2014-06-24 18:48:01.000000000 -0400
@@ -11,8 +11,13 @@
 #include "CLucene/LuceneThreads.h"
 
 #if defined(_CL_HAVE_TR1_UNORDERED_MAP) && defined(_CL_HAVE_TR1_UNORDERED_SET)
+#if defined(_LIBCPP_VERSION)
+	#include <unordered_map>
+	#include <unordered_set>
+#else
 	#include <tr1/unordered_map>
 	#include <tr1/unordered_set>
+#endif
 #elif defined(_CL_HAVE_HASH_MAP) && defined(_CL_HAVE_HASH_SET)
 	//hashing is all or nothing!
 	#include <hash_map>
@@ -83,7 +88,7 @@
 	_vt get( _kt k) const {
 		const_iterator itr = base::find(k);
 		if ( itr==base::end() )
-			return (_vt)NULL;
+			return static_cast<_vt>(0);
 		else
 			return itr->second;
 	}
@@ -316,6 +321,7 @@
 		if ( _this::dk || _this::dv )
 			_this::remove(k);
 
+		(*this)[k] = v;;
 	}
 };
 

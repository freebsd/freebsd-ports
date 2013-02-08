--- src/core/CLucene/util/VoidMap.h.orig	2011-03-16 20:21:07.000000000 -0400
+++ src/core/CLucene/util/VoidMap.h	2013-01-08 17:37:43.000000000 -0500
@@ -83,7 +83,7 @@
 	_vt get( _kt k) const {
 		const_iterator itr = base::find(k);
 		if ( itr==base::end() )
-			return (_vt)NULL;
+			return static_cast<_vt>(0);
 		else
 			return itr->second;
 	}
@@ -316,6 +316,7 @@
 		if ( _this::dk || _this::dv )
 			_this::remove(k);
 
+		(*this)[k] = v;;
 	}
 };
 

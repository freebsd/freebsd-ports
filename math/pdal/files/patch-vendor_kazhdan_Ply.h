--- vendor/kazhdan/Ply.h.orig	2024-06-29 01:37:43 UTC
+++ vendor/kazhdan/Ply.h
@@ -317,7 +317,7 @@ class PlyOrientedVertex (public)
 	PlyOrientedVertex( void ) { ; }
 	PlyOrientedVertex( Point3D< Real > p , Point3D< Real > n ) : point(p) , normal(n) { ; }
   	PlyOrientedVertex operator + ( PlyOrientedVertex p ) const { return PlyOrientedVertex( point+p.point , normal+p.normal ); }
-	PlyOrientedVertex operator - ( PlyOrientedVertex p ) const { return PlyOrientedVertex( point-p.value , normal-p.normal ); }
+	PlyOrientedVertex operator - ( PlyOrientedVertex p ) const { return PlyOrientedVertex( point-p.point , normal-p.normal ); }
 	template< class _Real > PlyOrientedVertex operator * ( _Real s ) const { return PlyOrientedVertex( point*s , normal*s ); }
 	template< class _Real > PlyOrientedVertex operator / ( _Real s ) const { return PlyOrientedVertex( point/s , normal/s ); }
 	PlyOrientedVertex& operator += ( PlyOrientedVertex p ) { point += p.point , normal += p.normal ; return *this; }
@@ -363,7 +363,7 @@ class PlyColorVertex (public)
 		}
 
 	  	_PlyColorVertex operator + ( _PlyColorVertex p ) const { return _PlyColorVertex( point+p.point , color+p.color ); }
-		_PlyColorVertex operator - ( _PlyColorVertex p ) const { return _PlyColorVertex( point-p.value , color-p.color ); }
+		_PlyColorVertex operator - ( _PlyColorVertex p ) const { return _PlyColorVertex( point-p.point , color-p.color ); }
 		template< class _Real > _PlyColorVertex operator * ( _Real s ) const { return _PlyColorVertex( point*s , color*s ); }
 		template< class _Real > _PlyColorVertex operator / ( _Real s ) const { return _PlyColorVertex( point/s , color/s ); }
 		_PlyColorVertex& operator += ( _PlyColorVertex p ) { point += p.point , color += p.color ; return *this; }

--- src/lib/geogram/third_party/PoissonRecon/PlyVertexMini.h.orig	2024-06-14 05:04:18 UTC
+++ src/lib/geogram/third_party/PoissonRecon/PlyVertexMini.h
@@ -44,7 +44,7 @@ class PlyValueVertex (public)
         PlyValueVertex( void ) : value( Real(0) ) { ; }
         PlyValueVertex( Point3D< Real > p , Real v ) : point(p) , value(v) { ; }
         PlyValueVertex operator + ( PlyValueVertex p ) const { return PlyValueVertex( point+p.point , value+p.value ); }
-        PlyValueVertex operator - ( PlyValueVertex p ) const { return PlyValueVertex( point-p.value , value-p.value ); }
+        PlyValueVertex operator - ( PlyValueVertex p ) const { return PlyValueVertex( point-p.point , value-p.value ); }
         template< class _Real > PlyValueVertex operator * ( _Real s ) const { return PlyValueVertex( point*s , Real(value*s) ); }
         template< class _Real > PlyValueVertex operator / ( _Real s ) const { return PlyValueVertex( point/s , Real(value/s) ); }
         PlyValueVertex& operator += ( PlyValueVertex p ) { point += p.point , value += p.value ; return *this; }
@@ -68,7 +68,7 @@ class PlyOrientedVertex (public)
         PlyOrientedVertex( void ) { ; }
         PlyOrientedVertex( Point3D< Real > p , Point3D< Real > n ) : point(p) , normal(n) { ; }
         PlyOrientedVertex operator + ( PlyOrientedVertex p ) const { return PlyOrientedVertex( point+p.point , normal+p.normal ); }
-        PlyOrientedVertex operator - ( PlyOrientedVertex p ) const { return PlyOrientedVertex( point-p.value , normal-p.normal ); }
+        PlyOrientedVertex operator - ( PlyOrientedVertex p ) const { return PlyOrientedVertex( point-p.point , normal-p.normal ); }
         template< class _Real > PlyOrientedVertex operator * ( _Real s ) const { return PlyOrientedVertex( point*s , normal*s ); }
         template< class _Real > PlyOrientedVertex operator / ( _Real s ) const { return PlyOrientedVertex( point/s , normal/s ); }
         PlyOrientedVertex& operator += ( PlyOrientedVertex p ) { point += p.point , normal += p.normal ; return *this; }
@@ -97,7 +97,7 @@ class PlyColorVertex (public)
                 }
 
                 _PlyColorVertex operator + ( _PlyColorVertex p ) const { return _PlyColorVertex( point+p.point , color+p.color ); }
-                _PlyColorVertex operator - ( _PlyColorVertex p ) const { return _PlyColorVertex( point-p.value , color-p.color ); }
+                _PlyColorVertex operator - ( _PlyColorVertex p ) const { return _PlyColorVertex( point-p.point , color-p.color ); }
                 template< class _Real > _PlyColorVertex operator * ( _Real s ) const { return _PlyColorVertex( point*s , color*s ); }
                 template< class _Real > _PlyColorVertex operator / ( _Real s ) const { return _PlyColorVertex( point/s , color/s ); }
                 _PlyColorVertex& operator += ( _PlyColorVertex p ) { point += p.point , color += p.color ; return *this; }
@@ -143,7 +143,7 @@ class PlyColorAndValueVertex (public)
                 }
 
                 _PlyColorAndValueVertex operator + ( _PlyColorAndValueVertex p ) const { return _PlyColorAndValueVertex( point+p.point , color+p.color , value+p.value ); }
-                _PlyColorAndValueVertex operator - ( _PlyColorAndValueVertex p ) const { return _PlyColorAndValueVertex( point-p.value , color-p.color , value+p.value ); }
+                _PlyColorAndValueVertex operator - ( _PlyColorAndValueVertex p ) const { return _PlyColorAndValueVertex( point-p.point , color-p.color , value+p.value ); }
                 template< class _Real > _PlyColorAndValueVertex operator * ( _Real s ) const { return _PlyColorAndValueVertex( point*s , color*s , value*s ); }
                 template< class _Real > _PlyColorAndValueVertex operator / ( _Real s ) const { return _PlyColorAndValueVertex( point/s , color/s , value/s ); }
                 _PlyColorAndValueVertex& operator += ( _PlyColorAndValueVertex p ) { point += p.point , color += p.color , value += p.value ; return *this; }

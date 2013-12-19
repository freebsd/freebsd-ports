--- my_set.h.orig
+++ my_set.h
@@ -47,7 +47,7 @@
 //*****************************************************************************
 {
 public:
-	bool contains( T const &s ) const { return find( s ) != this->end(); }
+	bool contains( T const &s ) const { return this->find( s ) != this->end(); }
 };
 
 //*****************************************************************************

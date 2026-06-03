--- dune/fem/space/common/auxiliarydofs.hh	2026-03-31 03:29:46.764720000 -0700
+++ dune/fem/space/common/auxiliarydofs.hh	2026-03-31 03:31:34.215124000 -0700
@@ -89,23 +89,23 @@
         ConstIterator &operator++ () { ++index_; return *this; }
         ConstIterator operator++ ( int ) { ConstIterator copy( *this ); ++(*this); return copy; }
 
-        ThisType &operator-- () noexcept { --index_; return *this; }
-        ThisType operator-- ( int ) noexcept { ThisType copy( *this ); --(*this); return copy; }
+        ConstIterator &operator-- () noexcept { --index_; return *this; }
+        ConstIterator operator-- ( int ) noexcept { ConstIterator copy( *this ); --(*this); return copy; }
 
-        ThisType &operator+= ( IndexType n ) noexcept { index_ += n; return *this; }
-        ThisType &operator-= ( IndexType n ) noexcept { index_ -= n; return *this; }
+        ConstIterator &operator+= ( IndexType n ) noexcept { index_ += n; return *this; }
+        ConstIterator &operator-= ( IndexType n ) noexcept { index_ -= n; return *this; }
 
-        ThisType operator+ ( IndexType n ) const noexcept { return ThisType( index_ + n ); }
-        ThisType operator- ( IndexType n ) const noexcept { return ThisType( index_ - n ); }
+        ConstIterator operator+ ( IndexType n ) const noexcept { return ConstIterator( index_ + n ); }
+        ConstIterator operator- ( IndexType n ) const noexcept { return ConstIterator( index_ - n ); }
 
-        friend ThisType operator+ ( IndexType n, const ThisType &i ) noexcept { return i + n; }
+        friend ConstIterator operator+ ( IndexType n, const ConstIterator &i ) noexcept { return i + n; }
 
-        IndexType operator- ( const ThisType &other ) const noexcept { return (index_ - other.index_); }
+        IndexType operator- ( const ConstIterator &other ) const noexcept { return (index_ - other.index_); }
 
-        bool operator< ( const ThisType &other ) const noexcept { return (index_ < other.index_); }
-        bool operator<= ( const ThisType &other ) const noexcept { return (index_ <= other.index_); }
-        bool operator>= ( const ThisType &other ) const noexcept { return (index_ >= other.index_); }
-        bool operator> ( const ThisType &other ) const noexcept { return (index_ > other.index_); }
+        bool operator< ( const ConstIterator &other ) const noexcept { return (index_ < other.index_); }
+        bool operator<= ( const ConstIterator &other ) const noexcept { return (index_ <= other.index_); }
+        bool operator>= ( const ConstIterator &other ) const noexcept { return (index_ >= other.index_); }
+        bool operator> ( const ConstIterator &other ) const noexcept { return (index_ > other.index_); }
 
       private:
         const IndexMapType *auxiliarys_ = nullptr;

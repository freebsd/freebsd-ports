--- Telegram/ThirdParty/rlottie/src/lottie/rapidjson/document.h.orig	2020-01-23 12:47:53 UTC
+++ Telegram/ThirdParty/rlottie/src/lottie/rapidjson/document.h
@@ -24,6 +24,9 @@
 #include "encodedstream.h"
 #include <new>      // placement new
 #include <limits>
+#ifdef __cpp_impl_three_way_comparison
+#include <compare>
+#endif
 
 RAPIDJSON_DIAG_PUSH
 #ifdef __clang__
@@ -175,12 +178,17 @@ class GenericMemberIterator { (public)
 
     //! @name relations
     //@{
+#ifdef __cpp_impl_three_way_comparison
+    template <bool Const_> bool operator==(const GenericMemberIterator<Const_,Encoding,Allocator>& that) const { return ptr_ == that.ptr_; }
+    template <bool Const_> std::strong_ordering operator<=>(const GenericMemberIterator<Const_,Encoding,Allocator>& that) const { return ptr_ <=> that.ptr_; }
+#else
     bool operator==(ConstIterator that) const { return ptr_ == that.ptr_; }
     bool operator!=(ConstIterator that) const { return ptr_ != that.ptr_; }
     bool operator<=(ConstIterator that) const { return ptr_ <= that.ptr_; }
     bool operator>=(ConstIterator that) const { return ptr_ >= that.ptr_; }
     bool operator< (ConstIterator that) const { return ptr_ < that.ptr_; }
     bool operator> (ConstIterator that) const { return ptr_ > that.ptr_; }
+#endif
     //@}
 
     //! @name dereference

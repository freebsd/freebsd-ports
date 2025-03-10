--- elec/lazy_array.hh.orig	2024-11-03 18:57:59 UTC
+++ elec/lazy_array.hh
@@ -244,6 +244,7 @@ class lazy_array
          }
       }
    }   
+#if 0 // fix build with clang-19, see https://github.com/LLNL/cardioid/issues/19
    friend inline void swap(lazy_array<TTT>& first, lazy_array<TTT>& second)
    {
       using std::swap;
@@ -255,6 +256,7 @@ class lazy_array
          swap(first.isValid_[ispace],second.isValid_[ispace]);
       }
    }
+#endif
    lazy_array<TTT>& operator=(lazy_array<TTT> other)
    {
       swap(*this,other);

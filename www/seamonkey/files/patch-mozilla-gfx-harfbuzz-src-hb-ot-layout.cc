--- mozilla/gfx/harfbuzz/src/hb-ot-layout.cc.orig	2012-06-24 22:14:46.463741874 -0400
+++ mozilla/gfx/harfbuzz/src/hb-ot-layout.cc	2012-06-24 22:15:06.784770042 -0400
@@ -540,4 +540,8 @@
   GPOS::position_finish (buffer);
 }
 
+template int SortedArrayOf<Record<LangSys> >::search<unsigned int>(unsigned int const &) const;
+template int SortedArrayOf<Record<Script> >::search<unsigned int>(unsigned int const &) const;
+template int SortedArrayOf<IntType<unsigned short> >::search<unsigned int>(unsigned int const &) const;
+template int SortedArrayOf<RangeRecord>::search<unsigned int>(unsigned int const &) const;
 

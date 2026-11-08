--- src/MicroScf/CtDftGrid.cpp.orig	2026-09-03 10:55:14 UTC
+++ src/MicroScf/CtDftGrid.cpp
@@ -974,7 +974,7 @@ void FDftGridGenerator::Create()
    {
       ct::FMemoryStackArray MemStacks(Mem);
       #pragma omp parallel for schedule(dynamic)
-      for (int iAtom = 0; size_t(iAtom) < Atoms.size(); ++ iAtom) {
+      for (int iAtom = 0; iAtom < int(Atoms.size()); ++ iAtom) {
          FMemoryStack &Mem_ = MemStacks.GetStackOfThread();
          Mem_.Align(32);
          FPointList

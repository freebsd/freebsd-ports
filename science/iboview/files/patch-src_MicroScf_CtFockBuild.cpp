--- src/MicroScf/CtFockBuild.cpp.orig	2026-09-03 10:55:14 UTC
+++ src/MicroScf/CtFockBuild.cpp
@@ -762,7 +762,7 @@ void FormIntMNF_ContractF(FMatrixView Out, ir::FIntegr
 
    FMemoryStackArray MemStacks(Mem_);
    #pragma omp parallel for schedule(dynamic)
-   for (int iShB__ = 0; size_t(iShB__) < pOrbBasis->Shells.size(); ++ iShB__ ){
+   for (int iShB__ = 0; iShB__ < int(pOrbBasis->Shells.size()); ++ iShB__ ){
       size_t iShB = size_t(iShB__);
       FMemoryStack &Mem = MemStacks.GetStackOfThread();
 

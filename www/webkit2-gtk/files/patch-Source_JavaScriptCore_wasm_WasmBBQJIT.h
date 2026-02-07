Excerpt from https://github.com/WebKit/WebKit/commit/406449de0ae5f7558bbcec552b8207ef3e7e6cff

FAILED: Source/JavaScriptCore/CMakeFiles/JavaScriptCore.dir/wasm/WasmBBQJIT.cpp.o
/usr/ports/www/webkit2-gtk/work-60/webkitgtk-2.46.6/Source/JavaScriptCore/wasm/WasmBBQJIT.cpp:4545:9: error: use of undeclared identifier 'shouldFuseBranchCompare'
 4545 |     if (shouldFuseBranchCompare && isCompareOpType(m_prevOpcode)
      |         ^
1 error generated.

--- Source/JavaScriptCore/wasm/WasmBBQJIT.h.orig	2025-02-05 09:13:05 UTC
+++ Source/JavaScriptCore/wasm/WasmBBQJIT.h
@@ -846,6 +846,9 @@ class BBQJIT { (public)
 #define LOG_DEDENT() do { if (UNLIKELY(Options::verboseBBQJITInstructions())) { m_loggingIndent -= 2; } } while (false);
 
 public:
+    // FIXME: Support fused branch compare on 32-bit platforms.
+    static constexpr bool shouldFuseBranchCompare = is64Bit();
+
     static constexpr bool tierSupportsSIMD = true;
 
     BBQJIT(CCallHelpers& jit, const TypeDefinition& signature, BBQCallee& callee, const FunctionData& function, uint32_t functionIndex, const ModuleInformation& info, Vector<UnlinkedWasmToWasmCall>& unlinkedWasmToWasmCalls, MemoryMode mode, InternalFunction* compilation, std::optional<bool> hasExceptionHandlers, unsigned loopIndexForOSREntry, TierUpCount* tierUp);

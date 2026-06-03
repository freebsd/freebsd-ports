Revert upstream commit fd862d43b ("Remove redundant quick return").

That commit removed an unconditional `if ((args.m == 0) || (args.n == 0))
return;` from interface/trsm.c on the assumption that it had been made
redundant by an earlier-added quick-return (commit 74486799b). The
assumption holds for the ARM64-SME direct-kernel path but NOT for the
x86_64 DYNAMIC_ARCH path: SMP block-fanout in level3_thread.c can
produce per-block bm=0 even when the caller passed a non-zero args.m,
and the late return was the only thing protecting the
strsm_kernel_RT_BARCELONA prologue from being entered with degenerate
dimensions. The BARCELONA prologue then walks %r8 off 16-byte alignment
(r8 += bn*bk*4 with bn=7, bk=7 = 196 bytes, mod 16 = 4) and the tail
loop SIGBUSes on `movaps (%r8),%xmm3`.

Reproducer: math/openblas 0.3.33 with DYNAMIC_ARCH on AMD64 fails the
`sblat3` test driver in the STRSM block, killed by SIGBUS.

Upstream report: https://github.com/OpenMathLib/OpenBLAS/issues/<TBD>

--- interface/trsm.c.orig	2026-04-23 13:50:46 UTC
+++ interface/trsm.c
@@ -383,6 +383,8 @@ if (strcmp(gotoblas_corename(), "armv9sme") == 0

 #endif

+  if ((args.m == 0) || (args.n == 0)) return;
+
   IDEBUG_START;

   FUNCTION_PROFILE_START();

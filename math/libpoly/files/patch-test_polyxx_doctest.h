--- test/polyxx/doctest.h.orig	2023-12-02 21:09:53 UTC
+++ test/polyxx/doctest.h
@@ -459,7 +459,7 @@ namespace doctest { namespace detail {
 // Break at the location of the failing check if possible
 #define DOCTEST_BREAK_INTO_DEBUGGER() __asm__("int $3\n" : :) // NOLINT(hicpp-no-assembler)
 #elif defined(__ppc__) || defined(__ppc64__)
-#define DOCTEST_BREAK_INTO_DEBUGGER() __asm__("li r0, 20\nsc\nnop\nli r0, 37\nli r4, 2\nsc\nnop\n" : : : "memory","r0","r3","r4" ) /* NOLINT */
+#define DOCTEST_BREAK_INTO_DEBUGGER() __asm__("li 0, 20\nsc\nnop\nli 0, 37\nli 4, 2\nsc\nnop\n" : : : "memory","0","3","4" ) /* NOLINT */
 #else
 #include <signal.h>
 #define DOCTEST_BREAK_INTO_DEBUGGER() raise(SIGTRAP)

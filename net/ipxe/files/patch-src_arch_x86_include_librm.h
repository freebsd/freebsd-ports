From 08caa8be3a143d6f33782f398b7937efb39ff283 Mon Sep 17 00:00:00 2001
From: Justin Cano <5184128+jstncno@users.noreply.github.com>
Date: Thu, 3 Aug 2023 09:58:11 -0700
Subject: [PATCH] Use the right sized register for the push operand based on
 the size of the value being pushed

Fixes https://github.com/ipxe/ipxe/issues/997
---
 src/arch/x86/include/librm.h | 6 ++++--
 1 file changed, 4 insertions(+), 2 deletions(-)

diff --git src/arch/x86/include/librm.h src/arch/x86/include/librm.h
index 5196d390..d9e748ad 100644
--- arch/x86/include/librm.h
+++ arch/x86/include/librm.h
@@ -250,8 +250,10 @@ extern void remove_user_from_rm_stack ( userptr_t data, size_t size );
 /* CODE_DEFAULT: restore default .code32/.code64 directive */
 #ifdef __x86_64__
 #define CODE_DEFAULT ".code64"
+#define PUSH "pushq"
 #else
 #define CODE_DEFAULT ".code32"
+#define PUSH "pushl"
 #endif
 
 /* LINE_SYMBOL: declare a symbol for the current source code line */
@@ -268,7 +270,7 @@ extern void remove_user_from_rm_stack ( userptr_t data, size_t size );
 
 /* REAL_CODE: declare a fragment of code that executes in real mode */
 #define REAL_CODE( asm_code_str )			\
-	"push $1f\n\t"					\
+	PUSH " $1f\n\t"					\
 	"call real_call\n\t"				\
 	TEXT16_CODE ( "\n1:\n\t"			\
 		      asm_code_str			\
@@ -277,7 +279,7 @@ extern void remove_user_from_rm_stack ( userptr_t data, size_t size );
 
 /* PHYS_CODE: declare a fragment of code that executes in flat physical mode */
 #define PHYS_CODE( asm_code_str )			\
-	"push $1f\n\t"					\
+	PUSH " $1f\n\t"					\
 	"call phys_call\n\t"				\
 	".section \".text.phys\", \"ax\", @progbits\n\t"\
 	"\n" LINE_SYMBOL "\n\t"				\
-- 
2.41.0


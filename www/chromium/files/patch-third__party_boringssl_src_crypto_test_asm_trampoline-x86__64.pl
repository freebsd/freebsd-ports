--- third_party/boringssl/src/crypto/test/asm/trampoline-x86_64.pl.orig	2023-07-16 15:47:57 UTC
+++ third_party/boringssl/src/crypto/test/asm/trampoline-x86_64.pl
@@ -141,6 +141,7 @@ my $code = <<____;
 abi_test_trampoline:
 .cfi_startproc
 .seh_startproc
+	_CET_ENDBR
 	# Stack layout:
 	#   8 bytes - align
 	#   $caller_state_size bytes - saved caller registers
@@ -307,6 +308,7 @@ foreach ("ax", "bx", "cx", "dx", "di", "si", "bp", 8..
 .globl	abi_test_clobber_r$_
 .align	16
 abi_test_clobber_r$_:
+	_CET_ENDBR
 	xorq	%r$_, %r$_
 	ret
 .size	abi_test_clobber_r$_,.-abi_test_clobber_r$_
@@ -319,6 +321,7 @@ foreach (0..15) {
 .globl	abi_test_clobber_xmm$_
 .align	16
 abi_test_clobber_xmm$_:
+	_CET_ENDBR
 	pxor	%xmm$_, %xmm$_
 	ret
 .size	abi_test_clobber_xmm$_,.-abi_test_clobber_xmm$_
@@ -335,6 +338,7 @@ $code .= <<____;
 abi_test_bad_unwind_wrong_register:
 .cfi_startproc
 .seh_startproc
+	_CET_ENDBR
 	pushq	%r12
 .cfi_push	%r13	# This should be %r13
 .seh_pushreg	%r13	# This should be %r13
@@ -358,6 +362,7 @@ abi_test_bad_unwind_wrong_register:
 abi_test_bad_unwind_temporary:
 .cfi_startproc
 .seh_startproc
+	_CET_ENDBR
 	pushq	%r12
 .cfi_push	%r12
 .seh_pushreg	%r12
@@ -384,6 +389,7 @@ abi_test_bad_unwind_temporary:
 .type	abi_test_set_direction_flag, \@abi-omnipotent
 .globl	abi_test_get_and_clear_direction_flag
 abi_test_get_and_clear_direction_flag:
+	_CET_ENDBR
 	pushfq
 	popq	%rax
 	andq	\$0x400, %rax
@@ -397,6 +403,7 @@ abi_test_get_and_clear_direction_flag:
 .type	abi_test_set_direction_flag, \@abi-omnipotent
 .globl	abi_test_set_direction_flag
 abi_test_set_direction_flag:
+	_CET_ENDBR
 	std
 	ret
 .size abi_test_set_direction_flag,.-abi_test_set_direction_flag

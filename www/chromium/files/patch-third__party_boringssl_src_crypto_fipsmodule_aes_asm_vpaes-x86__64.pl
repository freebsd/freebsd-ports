--- third_party/boringssl/src/crypto/fipsmodule/aes/asm/vpaes-x86_64.pl.orig	2023-07-16 15:47:57 UTC
+++ third_party/boringssl/src/crypto/fipsmodule/aes/asm/vpaes-x86_64.pl
@@ -871,6 +871,7 @@ _vpaes_schedule_mangle:
 .align	16
 ${PREFIX}_set_encrypt_key:
 .cfi_startproc
+	_CET_ENDBR
 #ifdef BORINGSSL_DISPATCH_TEST
 .extern        BORINGSSL_function_hit
        movb \$1, BORINGSSL_function_hit+5(%rip)
@@ -926,6 +927,7 @@ $code.=<<___;
 .align	16
 ${PREFIX}_set_decrypt_key:
 .cfi_startproc
+	_CET_ENDBR
 ___
 $code.=<<___ if ($win64);
 	lea	-0xb8(%rsp),%rsp
@@ -981,6 +983,7 @@ $code.=<<___;
 .align	16
 ${PREFIX}_encrypt:
 .cfi_startproc
+	_CET_ENDBR
 #ifdef BORINGSSL_DISPATCH_TEST
 .extern        BORINGSSL_function_hit
        movb \$1, BORINGSSL_function_hit+4(%rip)
@@ -1030,6 +1033,7 @@ $code.=<<___;
 .align	16
 ${PREFIX}_decrypt:
 .cfi_startproc
+	_CET_ENDBR
 ___
 $code.=<<___ if ($win64);
 	lea	-0xb8(%rsp),%rsp
@@ -1081,6 +1085,7 @@ $code.=<<___;
 .align	16
 ${PREFIX}_cbc_encrypt:
 .cfi_startproc
+	_CET_ENDBR
 	xchg	$key,$len
 ___
 ($len,$key)=($key,$len);
@@ -1166,6 +1171,7 @@ $code.=<<___;
 .align	16
 ${PREFIX}_ctr32_encrypt_blocks:
 .cfi_startproc
+	_CET_ENDBR
 	# _vpaes_encrypt_core and _vpaes_encrypt_core_2x expect the key in %rdx.
 	xchg	$key, $blocks
 ___

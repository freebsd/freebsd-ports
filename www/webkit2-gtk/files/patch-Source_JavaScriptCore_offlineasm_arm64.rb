--- Source/JavaScriptCore/offlineasm/arm64.rb.orig	2025-02-15 11:33:50 UTC
+++ Source/JavaScriptCore/offlineasm/arm64.rb
@@ -1368,8 +1368,8 @@ class Instruction
             $asm.puts "Ljsc_llint_loh_ldr_#{uid}:"
             $asm.puts "ldr #{operands[1].arm64Operand(:quad)}, [#{operands[1].arm64Operand(:quad)}, #{operands[0].asmLabel}@GOTPAGEOFF]"
 
-            # On Linux, use ELF GOT relocation specifiers.
-            $asm.putStr("#elif OS(LINUX)")
+            # On Linux and FreeBSD, use ELF GOT relocation specifiers.
+            $asm.putStr("#elif OS(LINUX) || OS(FREEBSD)")
             $asm.puts "adrp #{operands[1].arm64Operand(:quad)}, :got:#{operands[0].asmLabel}"
             $asm.puts "ldr #{operands[1].arm64Operand(:quad)}, [#{operands[1].arm64Operand(:quad)}, :got_lo12:#{operands[0].asmLabel}]"
 

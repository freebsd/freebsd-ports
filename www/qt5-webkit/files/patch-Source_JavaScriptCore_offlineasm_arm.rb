armv6/v7:
Don't emit ARMv7 instructions (movw, movt) for ARMv6 targets.

See PR 222612

--- Source/JavaScriptCore/offlineasm/arm.rb.orig	2017-08-24 10:30:41 UTC
+++ Source/JavaScriptCore/offlineasm/arm.rb
@@ -502,8 +502,12 @@ class Instruction
                 $asm.puts "mov #{armFlippedOperands(operands)}"
             end
         when "mvlbl"
+            if isARMv7 or isARMv7Traditional
                 $asm.puts "movw #{operands[1].armOperand}, \#:lower16:#{operands[0].value}"
                 $asm.puts "movt #{operands[1].armOperand}, \#:upper16:#{operands[0].value}"
+            else
+                $asm.puts "ldr #{operands[1].armOperand}, =#{operands[0].value}"
+            end
         when "nop"
             $asm.puts "nop"
         when "bieq", "bpeq", "bbeq"

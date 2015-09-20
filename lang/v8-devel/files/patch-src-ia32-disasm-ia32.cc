--- src/ia32/disasm-ia32.cc.orig	2014-06-03 08:52:11 UTC
+++ src/ia32/disasm-ia32.cc
@@ -1743,7 +1743,7 @@ int Disassembler::ConstantPoolSizeAt(byt
     buffer[0] = '\0';
     byte* prev_pc = pc;
     pc += d.InstructionDecode(buffer, pc);
-    fprintf(f, "%p", prev_pc);
+    fprintf(f, "%p", reinterpret_cast<void*>(prev_pc));
     fprintf(f, "    ");
 
     for (byte* bp = prev_pc; bp < pc; bp++) {

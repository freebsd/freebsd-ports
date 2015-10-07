--- src/ia32/disasm-ia32.cc.orig	2013-05-01 12:56:29 UTC
+++ src/ia32/disasm-ia32.cc
@@ -1707,7 +1707,7 @@ int Disassembler::ConstantPoolSizeAt(byt
     buffer[0] = '\0';
     byte* prev_pc = pc;
     pc += d.InstructionDecode(buffer, pc);
-    fprintf(f, "%p", prev_pc);
+    fprintf(f, "%p", reinterpret_cast<void*>(prev_pc));
     fprintf(f, "    ");
 
     for (byte* bp = prev_pc; bp < pc; bp++) {

--- src/x64/disasm-x64.cc.orig	2013-05-01 12:56:28 UTC
+++ src/x64/disasm-x64.cc
@@ -1851,7 +1851,7 @@ void Disassembler::Disassemble(FILE* f, 
     buffer[0] = '\0';
     byte* prev_pc = pc;
     pc += d.InstructionDecode(buffer, pc);
-    fprintf(f, "%p", prev_pc);
+    fprintf(f, "%p", reinterpret_cast<void*>(prev_pc));
     fprintf(f, "    ");
 
     for (byte* bp = prev_pc; bp < pc; bp++) {

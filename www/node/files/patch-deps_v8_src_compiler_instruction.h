--- deps/v8/src/compiler/instruction.h.orig	2016-03-16 21:22:58.000000000 +0100
+++ deps/v8/src/compiler/instruction.h	2016-03-24 23:27:23.004854000 +0100
@@ -1011,7 +1011,7 @@ class InstructionBlock final : public Zo
 
 typedef ZoneDeque<Constant> ConstantDeque;
 typedef std::map<int, Constant, std::less<int>,
-                 zone_allocator<std::pair<int, Constant> > > ConstantMap;
+                 zone_allocator<std::pair<const int, Constant> > > ConstantMap;
 
 typedef ZoneDeque<Instruction*> InstructionDeque;
 typedef ZoneDeque<ReferenceMap*> ReferenceMapDeque;

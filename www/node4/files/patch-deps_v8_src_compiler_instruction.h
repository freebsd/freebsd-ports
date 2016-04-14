--- deps/v8/src/compiler/instruction.h.orig	2016-04-01 00:47:45 UTC
+++ deps/v8/src/compiler/instruction.h
@@ -1011,7 +1011,7 @@ class InstructionBlock final : public Zo
 
 typedef ZoneDeque<Constant> ConstantDeque;
 typedef std::map<int, Constant, std::less<int>,
-                 zone_allocator<std::pair<int, Constant> > > ConstantMap;
+                 zone_allocator<std::pair<const int, Constant> > > ConstantMap;
 
 typedef ZoneDeque<Instruction*> InstructionDeque;
 typedef ZoneDeque<ReferenceMap*> ReferenceMapDeque;

--- deps/v8/src/compiler/instruction.h.orig	2016-03-31 23:26:45 UTC
+++ deps/v8/src/compiler/instruction.h
@@ -722,7 +722,7 @@ OStream& operator<<(OStream& os, const C
 
 typedef std::deque<Constant, zone_allocator<Constant> > ConstantDeque;
 typedef std::map<int, Constant, std::less<int>,
-                 zone_allocator<std::pair<int, Constant> > > ConstantMap;
+                 zone_allocator<std::pair<const int, Constant> > > ConstantMap;
 
 
 typedef std::deque<Instruction*, zone_allocator<Instruction*> >

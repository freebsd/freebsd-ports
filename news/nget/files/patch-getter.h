https://github.com/Optware/Optware-ng/commit/cf5b5050c989fb4e969167d20e6b135ff2608a87

--- getter.h.orig	2017-10-14 02:48:48 UTC
+++ getter.h
@@ -35,7 +35,7 @@ class MemGetter {
 template <class RetType, class ClassType>
 class MemfuncGetter {
 	private:
-		typedef RetType (ClassType::*member_t)(void);
+		typedef RetType (ClassType::*member_t)(void) const;
 		member_t member;		
 	public:
 		typedef RetType T;

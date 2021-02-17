--- io.h.orig	2013-08-10 02:01:58 UTC
+++ io.h
@@ -31,7 +31,7 @@
  */
 
 #define __OUT1(s,x) \
-extern inline void __out##s(unsigned x value, unsigned short port) {
+static inline void __out##s(unsigned x value, unsigned short port) {
 
 #define __OUT2(s,s1,s2) \
 __asm__ __volatile__ ("out" #s " %" s1 "0,%" s2 "1"
@@ -43,7 +43,7 @@ __OUT1(s##_p,x) __OUT2(s,s1,"w") : : "a" (value), "d" 
 __OUT1(s##c_p,x) __OUT2(s,s1,"") : : "a" (value), "id" (port)); SLOW_DOWN_IO; }
 
 #define __IN1(s) \
-extern inline RETURN_TYPE __in##s(unsigned short port) { RETURN_TYPE _v;
+static inline RETURN_TYPE __in##s(unsigned short port) { RETURN_TYPE _v;
 
 #define __IN2(s,s1,s2) \
 __asm__ __volatile__ ("in" #s " %" s2 "1,%" s1 "0"
@@ -55,7 +55,7 @@ __IN1(s##_p) __IN2(s,s1,"w") : "=a" (_v) : "d" (port) 
 __IN1(s##c_p) __IN2(s,s1,"") : "=a" (_v) : "id" (port) ,##i ); SLOW_DOWN_IO; return _v; }
 
 #define __OUTS(s) \
-extern inline void outs##s(unsigned short port, const void * addr, unsigned long count) \
+static inline void outs##s(unsigned short port, const void * addr, unsigned long count) \
 { __asm__ __volatile__ ("cld ; rep ; outs" #s \
 : "=S" (addr), "=c" (count) : "d" (port),"0" (addr),"1" (count)); }
 

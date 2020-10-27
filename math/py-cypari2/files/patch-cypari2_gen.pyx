--- cypari2/gen.pyx.orig	2019-04-23 10:57:51 UTC
+++ cypari2/gen.pyx
@@ -4109,7 +4109,7 @@ cdef class Gen(Gen_base):
         non-constant polynomial, or False if f is reducible or constant.
         """
         sig_on()
-        t = isirreducible(self.g)
+        t = polisirreducible(self.g)
         clear_stack()
         return t != 0
 

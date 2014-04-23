--- src/libgambit/integer.h.orig	2014-04-23 14:09:42.000000000 +0200
+++ src/libgambit/integer.h	2014-04-23 14:10:50.000000000 +0200
@@ -224,8 +224,8 @@
   long		  as_long() const { return Itolong(rep); }
   double	  as_double() const { return Itodouble(rep); }
 
-  friend std::string    Itoa(const Integer& x, int base = 10, int width = 0);
-  friend Integer  atoI(const char* s, int base = 10);
+  friend std::string    Itoa(const Integer& x, int base /*= 10*/, int width /*= 0*/);
+  friend Integer  atoI(const char* s, int base /*= 10*/);
   
   friend std::istream &operator>>(std::istream &s, Integer& y);
   friend std::ostream &operator<<(std::ostream &s, const Integer& y);

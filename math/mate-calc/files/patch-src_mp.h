--- src/mp.h.orig	2021-10-09 19:59:01 UTC
+++ src/mp.h
@@ -69,7 +69,7 @@ void        mperr(const char *format, ...) __attribute
 /* Returns initialized MPNumber object */
 MPNumber    mp_new(void);
 
-MPNumber    mp_new_from_unsigned_integer(ulong x);
+MPNumber    mp_new_from_unsigned_integer(unsigned long x);
 
 MPNumber*   mp_new_ptr(void);
 
@@ -236,7 +236,7 @@ void   mp_set_from_double(double x, MPNumber *z);
 void   mp_set_from_integer(long x, MPNumber *z);
 
 /* Sets z = x */
-void   mp_set_from_unsigned_integer(ulong x, MPNumber *z);
+void   mp_set_from_unsigned_integer(unsigned long x, MPNumber *z);
 
 /* Sets z = numerator ÷ denominator */
 void   mp_set_from_fraction(long numerator, long denominator, MPNumber *z);
@@ -265,7 +265,7 @@ double mp_to_double(const MPNumber *x);
 long mp_to_integer(const MPNumber *x);
 
 /* Returns x as a native unsigned integer */
-ulong mp_to_unsigned_integer(const MPNumber *x);
+unsigned long mp_to_unsigned_integer(const MPNumber *x);
 
 /* Sets z = sin x */
 void   mp_sin(const MPNumber *x, MPAngleUnit unit, MPNumber *z);

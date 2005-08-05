
$FreeBSD$

--- engine/Z.c.orig
+++ engine/Z.c
@@ -2,19 +2,11 @@
 #include "base.h"
 #include "inline.h"
 
-#if defined(__GNUC__)
-#define INLINE inline
-#elif defined(VISUAL)
-#define INLINE __inline
-#else
-#define INLINE
-#endif
-
-INLINE void _addz(Z n1,Z n2,Z nr);
-INLINE void _subz(Z n1,Z n2,Z nr);
-INLINE void _mulz(Z n1,Z n2,Z nr);
-INLINE int _addz_main(unsigned int *m1,int d1,unsigned int *m2,int d2,unsigned int *mr);
-INLINE int _subz_main(unsigned int *m1,int d1,unsigned int *m2,int d2,unsigned int *mr);
+void _addz(Z n1,Z n2,Z nr);
+void _subz(Z n1,Z n2,Z nr);
+void _mulz(Z n1,Z n2,Z nr);
+int _addz_main(unsigned int *m1,int d1,unsigned int *m2,int d2,unsigned int *mr);
+int _subz_main(unsigned int *m1,int d1,unsigned int *m2,int d2,unsigned int *mr);
 
 /* immediate int -> Z */
 #define UTOZ(c,n) (n)=(!((unsigned int)(c))?0:(((unsigned int)(c))<=IMM_MAX?((Z)((((unsigned int)(c))<<1)|1)):utoz((unsigned int)(c))))

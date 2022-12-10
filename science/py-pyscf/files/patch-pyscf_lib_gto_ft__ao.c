- wprkaropund for compilation failure on armv7
- #include <stdint.h> for int8_t, see https://github.com/pyscf/pyscf/issues/1535

--- pyscf/lib/gto/ft_ao.c.orig	2022-12-10 07:40:03 UTC
+++ pyscf/lib/gto/ft_ao.c
@@ -44,6 +44,7 @@
 
 #include <stdlib.h>
 #include <stdio.h>
+#include <stdint.h>
 #include <math.h>
 #include <assert.h>
 #include <complex.h>

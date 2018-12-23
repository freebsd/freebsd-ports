--- src/H5detect.c.orig	2018-12-12 22:50:50 UTC
+++ src/H5detect.c
@@ -1360,8 +1360,8 @@ bit.\n";
  *
  *-------------------------------------------------------------------------
  */
-static void
-detect_C89_integers(void) HDF_NO_UBSAN
+static void HDF_NO_UBSAN
+detect_C89_integers(void)
 {
     DETECT_BYTE(signed char,      SCHAR,        d_g[nd_g]); nd_g++;
     DETECT_BYTE(unsigned char,      UCHAR,        d_g[nd_g]); nd_g++;
@@ -1388,8 +1388,8 @@ detect_C89_integers(void) HDF_NO_UBSAN
  *
  *-------------------------------------------------------------------------
  */
-static void
-detect_C89_floats(void) HDF_NO_UBSAN
+static void HDF_NO_UBSAN
+detect_C89_floats(void)
 {
     DETECT_F(float,     FLOAT,      d_g[nd_g]); nd_g++;
     DETECT_F(double,    DOUBLE,     d_g[nd_g]); nd_g++;
@@ -1410,8 +1410,8 @@ detect_C89_floats(void) HDF_NO_UBSAN
  *
  *-------------------------------------------------------------------------
  */
-static void
-detect_C99_integers8(void) HDF_NO_UBSAN
+static void HDF_NO_UBSAN
+detect_C99_integers8(void)
 {
 #if H5_SIZEOF_INT8_T>0
   #if H5_SIZEOF_INT8_T==1
@@ -1472,8 +1472,8 @@ detect_C99_integers8(void) HDF_NO_UBSAN
  *
  *-------------------------------------------------------------------------
  */
-static void
-detect_C99_integers16(void) HDF_NO_UBSAN
+static void HDF_NO_UBSAN
+detect_C99_integers16(void)
 {
 #if H5_SIZEOF_INT16_T>0
     DETECT_I(int16_t,           INT16,        d_g[nd_g]); nd_g++;
@@ -1510,8 +1510,8 @@ detect_C99_integers16(void) HDF_NO_UBSAN
  *
  *-------------------------------------------------------------------------
  */
-static void
-detect_C99_integers32(void) HDF_NO_UBSAN
+static void HDF_NO_UBSAN
+detect_C99_integers32(void)
 {
 #if H5_SIZEOF_INT32_T>0
     DETECT_I(int32_t,           INT32,        d_g[nd_g]); nd_g++;
@@ -1548,8 +1548,8 @@ detect_C99_integers32(void) HDF_NO_UBSAN
  *
  *-------------------------------------------------------------------------
  */
-static void
-detect_C99_integers64(void) HDF_NO_UBSAN
+static void HDF_NO_UBSAN
+detect_C99_integers64(void)
 {
 #if H5_SIZEOF_INT64_T>0
     DETECT_I(int64_t,           INT64,        d_g[nd_g]); nd_g++;
@@ -1599,8 +1599,8 @@ detect_C99_integers64(void) HDF_NO_UBSAN
  *
  *-------------------------------------------------------------------------
  */
-static void
-detect_C99_integers(void) HDF_NO_UBSAN
+static void HDF_NO_UBSAN
+detect_C99_integers(void)
 {
     /* break it down to more subroutines so that each module subroutine */
     /* is smaller and takes less time to compile with optimization on.  */
@@ -1625,8 +1625,8 @@ detect_C99_integers(void) HDF_NO_UBSAN
  *
  *-------------------------------------------------------------------------
  */
-static void
-detect_C99_floats(void) HDF_NO_UBSAN
+static void HDF_NO_UBSAN
+detect_C99_floats(void)
 {
 #if H5_SIZEOF_DOUBLE == H5_SIZEOF_LONG_DOUBLE
     /*
@@ -1656,8 +1656,8 @@ detect_C99_floats(void) HDF_NO_UBSAN
  *
  *-------------------------------------------------------------------------
  */
-static void
-detect_alignments(void) HDF_NO_UBSAN
+static void HDF_NO_UBSAN
+detect_alignments(void)
 {
     /* Detect structure alignment for pointers, hvl_t, hobj_ref_t, hdset_reg_ref_t */
     DETECT_M(void *,              POINTER,      m_g[na_g]); na_g++;
@@ -1744,8 +1744,8 @@ static int verify_signal_handlers(int signum, void (*h
  *
  *-------------------------------------------------------------------------
  */
-int
-main(void) HDF_NO_UBSAN
+int HDF_NO_UBSAN
+main(void)
 {
 
 #if defined(H5_HAVE_SETSYSINFO) && defined(SSI_NVPAIRS)

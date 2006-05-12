--- mpn/generic/addsub_n.c.orig	Fri May 12 09:31:03 2006
+++ mpn/generic/addsub_n.c	Fri May 12 09:32:06 2006
@@ -58,13 +58,13 @@
       for (off = 0; off < n; off += PART_SIZE)
 	{
 	  this_n = MIN (n - off, PART_SIZE);
-#if HAVE_NATIVE_mpn_add_nc || !HAVE_NATIVE_mpn_add_n
+#if HAVE_NATIVE_mpn_add_nc
 	  acyo = mpn_add_nc (r1p + off, s1p + off, s2p + off, this_n, acyo);
 #else
 	  acyn = mpn_add_n (r1p + off, s1p + off, s2p + off, this_n);
 	  acyo = acyn + mpn_add_1 (r1p + off, r1p + off, this_n, acyo);
 #endif
-#if HAVE_NATIVE_mpn_sub_nc || !HAVE_NATIVE_mpn_sub_n
+#if HAVE_NATIVE_mpn_sub_nc
 	  scyo = mpn_sub_nc (r2p + off, s1p + off, s2p + off, this_n, scyo);
 #else
 	  scyn = mpn_sub_n (r2p + off, s1p + off, s2p + off, this_n);
@@ -81,13 +81,13 @@
       for (off = 0; off < n; off += PART_SIZE)
 	{
 	  this_n = MIN (n - off, PART_SIZE);
-#if HAVE_NATIVE_mpn_sub_nc || !HAVE_NATIVE_mpn_sub_n
+#if HAVE_NATIVE_mpn_sub_nc
 	  scyo = mpn_sub_nc (r2p + off, s1p + off, s2p + off, this_n, scyo);
 #else
 	  scyn = mpn_sub_n (r2p + off, s1p + off, s2p + off, this_n);
 	  scyo = scyn + mpn_sub_1 (r2p + off, r2p + off, this_n, scyo);
 #endif
-#if HAVE_NATIVE_mpn_add_nc || !HAVE_NATIVE_mpn_add_n
+#if HAVE_NATIVE_mpn_add_nc
 	  acyo = mpn_add_nc (r1p + off, s1p + off, s2p + off, this_n, acyo);
 #else
 	  acyn = mpn_add_n (r1p + off, s1p + off, s2p + off, this_n);
@@ -105,13 +105,13 @@
       for (off = 0; off < n; off += PART_SIZE)
 	{
 	  this_n = MIN (n - off, PART_SIZE);
-#if HAVE_NATIVE_mpn_add_nc || !HAVE_NATIVE_mpn_add_n
+#if HAVE_NATIVE_mpn_add_nc
 	  acyo = mpn_add_nc (tp, s1p + off, s2p + off, this_n, acyo);
 #else
 	  acyn = mpn_add_n (tp, s1p + off, s2p + off, this_n);
 	  acyo = acyn + mpn_add_1 (tp, tp, this_n, acyo);
 #endif
-#if HAVE_NATIVE_mpn_sub_nc || !HAVE_NATIVE_mpn_sub_n
+#if HAVE_NATIVE_mpn_sub_nc
 	  scyo = mpn_sub_nc (r2p + off, s1p + off, s2p + off, this_n, scyo);
 #else
 	  scyn = mpn_sub_n (r2p + off, s1p + off, s2p + off, this_n);

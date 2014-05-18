--- fastlscomplex.cc.orig	2012-08-16 21:00:23.000000000 +0000
+++ fastlscomplex.cc	2014-05-18 17:56:32.000000000 +0000
@@ -372,8 +372,7 @@
 
                             --tpra;
                             h = *tpra * *exp_ptr;
-                            record_current->power_series[p].real() -= h.imag();
-                            record_current->power_series[p].imag() += h.real();
+                            record_current->power_series[p] += std::complex<double>(-h.imag(), h.real());
 
                             if (++exp_ptr >= exp_pse_ptr )
                               break;
@@ -386,8 +385,7 @@
 
                             --tpra;
                             h = -*tpra * *exp_ptr;
-                            record_current->power_series[p].real() -= h.imag();
-                            record_current->power_series[p].imag() += h.real();
+                            record_current->power_series[p] += std::complex<double>(-h.imag(), h.real());
 
                             if (++exp_ptr >= exp_pse_ptr)
                               break;
@@ -422,8 +420,7 @@
 
                                   tprb -= 2;
                                   h = *tprb * *exp_ptr;
-                                  record_current->power_series[p].real() -= h.imag();
-                                  record_current->power_series[p].imag() += h.real();
+                                  record_current->power_series[p] += std::complex<double>(-h.imag(), h.real());
 
                                   if ( ++exp_ptr >= exp_pse_ptr )
                                     break;
@@ -436,8 +433,7 @@
 
                                   tprb -= 2;
                                   h = - *tprb * *exp_ptr;
-                                  record_current->power_series[p].real() -= h.imag();
-                                  record_current->power_series[p].imag() += h.real();
+                                  record_current->power_series[p] += std::complex<double>(-h.imag(), h.real());
 
                                   if (++exp_ptr >= exp_pse_ptr)
                                     break;
@@ -467,8 +463,7 @@
 
                                   --tpra;
                                   h = *tpra * *exp_ptr;
-                                  record_next->power_series[q].real() -= h.imag();
-                                  record_next->power_series[q].imag() += h.real();
+                                  record_current->power_series[q] += std::complex<double>(-h.imag(), h.real());
 
                                   if (++exp_ptr >= exp_pse_ptr)
                                     break;
@@ -481,8 +476,7 @@
 
                                   --tpra;
                                   h = -*tpra * *exp_ptr;
-                                  record_next->power_series[q].real() -= h.imag();
-                                  record_next->power_series[q].imag() += h.real();
+                                  record_current->power_series[q] += std::complex<double>(-h.imag(), h.real());
 
                                   if (++exp_ptr >= exp_pse_ptr)
                                     break;

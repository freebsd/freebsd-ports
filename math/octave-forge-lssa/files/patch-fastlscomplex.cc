--- fastlscomplex.cc-orig	2014-05-17 13:56:21.000000000 -0500
+++ fastlscomplex.cc	2014-05-17 14:06:47.000000000 -0500
@@ -372,8 +372,9 @@
 
                             --tpra;
                             h = *tpra * *exp_ptr;
-                            record_current->power_series[p].real() -= h.imag();
-                            record_current->power_series[p].imag() += h.real();
+                            // record_current->power_series[p].real() -= h.imag();
+                            // record_current->power_series[p].imag() += h.real();
+                            record_current->power_series[p] = std::complex<double>(record_current->power_series[p].real() - h.imag(), record_current->power_series[p].imag() + h.real());
 
                             if (++exp_ptr >= exp_pse_ptr )
                               break;
@@ -386,8 +387,9 @@
 
                             --tpra;
                             h = -*tpra * *exp_ptr;
-                            record_current->power_series[p].real() -= h.imag();
-                            record_current->power_series[p].imag() += h.real();
+                            // record_current->power_series[p].real() -= h.imag();
+                            // record_current->power_series[p].imag() += h.real();
+                            record_current->power_series[p] = std::complex<double>(record_current->power_series[p].real() - h.imag(), record_current->power_series[p].imag() + h.real());
 
                             if (++exp_ptr >= exp_pse_ptr)
                               break;
@@ -422,8 +424,9 @@
 
                                   tprb -= 2;
                                   h = *tprb * *exp_ptr;
-                                  record_current->power_series[p].real() -= h.imag();
-                                  record_current->power_series[p].imag() += h.real();
+                                  // record_current->power_series[p].real() -= h.imag();
+                                  // record_current->power_series[p].imag() += h.real();
+                                  record_current->power_series[p] = std::complex<double>(record_current->power_series[p].real() - h.imag(), record_current->power_series[p].imag() + h.real());
 
                                   if ( ++exp_ptr >= exp_pse_ptr )
                                     break;
@@ -436,8 +439,9 @@
 
                                   tprb -= 2;
                                   h = - *tprb * *exp_ptr;
-                                  record_current->power_series[p].real() -= h.imag();
-                                  record_current->power_series[p].imag() += h.real();
+                                  // record_current->power_series[p].real() -= h.imag();
+                                  // record_current->power_series[p].imag() += h.real();
+                                  record_current->power_series[p] = std::complex<double>(record_current->power_series[p].real() - h.imag(), record_current->power_series[p].imag() + h.real());
 
                                   if (++exp_ptr >= exp_pse_ptr)
                                     break;
@@ -467,8 +471,9 @@
 
                                   --tpra;
                                   h = *tpra * *exp_ptr;
-                                  record_next->power_series[q].real() -= h.imag();
-                                  record_next->power_series[q].imag() += h.real();
+                                  // record_current->power_series[q].real() -= h.imag();
+                                  // record_current->power_series[q].imag() += h.real();
+                                  record_current->power_series[q] = std::complex<double>(record_current->power_series[q].real() - h.imag(), record_current->power_series[q].imag() + h.real());
 
                                   if (++exp_ptr >= exp_pse_ptr)
                                     break;
@@ -481,8 +486,9 @@
 
                                   --tpra;
                                   h = -*tpra * *exp_ptr;
-                                  record_next->power_series[q].real() -= h.imag();
-                                  record_next->power_series[q].imag() += h.real();
+                                  // record_current->power_series[q].real() -= h.imag();
+                                  // record_current->power_series[q].imag() += h.real();
+                                  record_current->power_series[q] = std::complex<double>(record_current->power_series[q].real() - h.imag(), record_current->power_series[q].imag() + h.real());
 
                                   if (++exp_ptr >= exp_pse_ptr)
                                     break;

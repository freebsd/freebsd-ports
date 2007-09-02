--- Lib/fftpack/setup.py.orig	2007-08-20 21:43:51.000000000 -0500
+++ Lib/fftpack/setup.py	2007-08-27 18:24:34.000000000 -0500
@@ -30,7 +30,7 @@
     config.add_extension('_fftpack',
                          sources=sources,
                          libraries=['dfftpack'],
-                         extra_info = fft_opt_info
+                         extra_info = [fft_opt_info, djbfft_info],
                          )
 
     config.add_extension('convolve',

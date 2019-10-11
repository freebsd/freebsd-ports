--- src/libtfhe/fft_processors/nayuki/fft_processor_nayuki.cpp.orig	2019-10-11 03:07:51 UTC
+++ src/libtfhe/fft_processors/nayuki/fft_processor_nayuki.cpp
@@ -12,7 +12,7 @@ FFT_Processor_nayuki::FFT_Processor_nayuki(const int32
     tables_reverse = fft_init_reverse(_2N);
     omegaxminus1 = (cplx*) malloc(sizeof(cplx) * _2N);
     for (int32_t x=0; x<_2N; x++) {
-	omegaxminus1[x]=cos(x*M_PI/N)-1. + sin(x*M_PI/N) * 1i; 
+	omegaxminus1[x]=std::complex<double>(cos(x*M_PI/N)-1., sin(x*M_PI/N)); 
 	//exp(i.x.pi/N)-1
     }
 }

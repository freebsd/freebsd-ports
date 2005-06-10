*** src/ffh263codec.cxx.orig	Fri Aug  8 01:52:14 2003
--- src/ffh263codec.cxx	Mon Jun  6 15:28:05 2005
***************
*** 140,146 ****
  #define  MSVC_OPENH323 1
  
  extern "C" {
! #include <avcodec.h>
  };
  
  
--- 140,146 ----
  #define  MSVC_OPENH323 1
  
  extern "C" {
! #include <ffmpeg/avcodec.h>
  };
  
  

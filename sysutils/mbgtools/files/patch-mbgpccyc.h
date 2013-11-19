*** mbglib/common/mbgpccyc.h	2013-06-26 12:37:50.000000000 -0400
--- mbglib/common/mbgpccyc.h	2013-11-18 13:24:31.653569000 -0500
***************
*** 39,44 ****
--- 39,45 ----
  #if defined( MBG_TGT_FREEBSD )
    #if defined( MBG_TGT_KERNEL )
      #if defined( MBG_ARCH_X86 )
+       #include <sys/time.h>
        #include <machine/clock.h>  /* for symbol 'tsc_freq' */
      #endif
    #endif

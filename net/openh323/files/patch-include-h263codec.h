*** include/h263codec.h.orig	Mon Aug  4 00:03:22 2003
--- include/h263codec.h	Mon Jun  6 14:57:16 2005
***************
*** 426,432 ****
         send. Note that for every encode thread, this 1 method is called. Consequently, 
         code is required to separate out packets from different encode threads.
      */
!     static void RtpCallback(void *data, int size, int packetNumber);
  
    protected:
      BOOL Resize(int width, int height);
--- 426,432 ----
         send. Note that for every encode thread, this 1 method is called. Consequently, 
         code is required to separate out packets from different encode threads.
      */
!     static void RtpCallback(AVCodecContext *s, void *data, int size, int packet Number);
  
    protected:
      BOOL Resize(int width, int height);

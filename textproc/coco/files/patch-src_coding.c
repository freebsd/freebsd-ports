diff -rBbc src/coding.c src/coding.c
*** src/coding.c	Sat Dec 29 03:50:32 2001
--- src/coding.c	Sat Dec 29 03:49:32 2001
***************
*** 154,160 ****
  /* 92.4.3, 92.12.18 by K.Handa */
  Lisp_Object Qcoding_system, Qcoding_system_p, Qnon_nil_coding_system_p;
  Lisp_Object Qeol_type;
! Lisp_Object Qpriority;
  /* end of patch */
  #endif /* emacs */
  
--- 154,160 ----
  /* 92.4.3, 92.12.18 by K.Handa */
  Lisp_Object Qcoding_system, Qcoding_system_p, Qnon_nil_coding_system_p;
  Lisp_Object Qeol_type;
! extern Lisp_Object Qpriority;
  /* end of patch */
  #endif /* emacs */
  
***************
*** 1044,1050 ****
  { \
    if (lc != lcg) dp = designate(dp, lcg, lc, 3, form), lcg = lc; \
    if (form & CODE_SEVEN) \
!     *dp++ = ESC, *dp++ = 'N'; \
    else \
      *dp++ = SS3; \
    cntl = (cntl & ~CC_GRAPHIC_MASK) | CC_IN_G3; \
--- 1044,1050 ----
  { \
    if (lc != lcg) dp = designate(dp, lcg, lc, 3, form), lcg = lc; \
    if (form & CODE_SEVEN) \
!     *dp++ = ESC, *dp++ = 'O'; \
    else \
      *dp++ = SS3; \
    cntl = (cntl & ~CC_GRAPHIC_MASK) | CC_IN_G3; \

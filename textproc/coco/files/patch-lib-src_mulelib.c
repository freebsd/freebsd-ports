diff -rBbc lib-src/mulelib.c lib-src/mulelib.c
*** lib-src/mulelib.c	Tue Aug 18 14:48:25 1998
--- lib-src/mulelib.c	Sat Dec 29 03:49:31 2001
***************
*** 287,299 ****
    p0 = p1 + 1;
    if (CODE_TYPE (cs) == ISO2022)  {
      long flags[12];
!     for (i = 0; i < 11; i++) {
!       if (!(flags[i] = atoi(p0))) flags[i] = Qnil;
        PROCEED_CHAR(',');
        p0 = p1 + 1;
      }
-     flags[i] = atoi(p0);
      CODE_LC_SET(cs, flags[0], flags[1], flags[2], flags[3]);
      CODE_FORM_SET(cs, (Lisp_Object)flags[4], (Lisp_Object)flags[5],
  		  (Lisp_Object)flags[6], (Lisp_Object)flags[7],
  		  (Lisp_Object)flags[8], (Lisp_Object)flags[9],
--- 287,304 ----
    p0 = p1 + 1;
    if (CODE_TYPE (cs) == ISO2022)  {
      long flags[12];
!     for (i = 0; i < 4; i++) {
!       if ((flags[i] = atoi(p0)) == -1) flags[i] = LCASCII;
        PROCEED_CHAR(',');
        p0 = p1 + 1;
      }
      CODE_LC_SET(cs, flags[0], flags[1], flags[2], flags[3]);
+     for (; i < 11; i++) {
+       if (!(flags[i] = atoi(p0))) flags[i] = Qnil;
+       PROCEED_CHAR(',');
+       p0 = p1 + 1;
+     }
+     if (!(flags[i] = atoi(p0))) flags[i] = Qnil;
      CODE_FORM_SET(cs, (Lisp_Object)flags[4], (Lisp_Object)flags[5],
  		  (Lisp_Object)flags[6], (Lisp_Object)flags[7],
  		  (Lisp_Object)flags[8], (Lisp_Object)flags[9],

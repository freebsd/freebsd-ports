*** apps/pgp/filter.c.orig      Thu Aug  9 17:39:07 2001
--- apps/pgp/filter.c   Thu Aug  9 17:39:20 2001
***************
*** 269,275 ****
      struct RingIterator *NameIter = NULL;
      union RingObject *name;
      Boolean OKToUse = FALSE, FoundName = FALSE;
!     int len = 0;
      int trust;
      char *TempNameString = NULL;

--- 269,275 ----
      struct RingIterator *NameIter = NULL;
      union RingObject *name;
      Boolean OKToUse = FALSE, FoundName = FALSE;
!     size_t len = 0;
      int trust;
      char *TempNameString = NULL;


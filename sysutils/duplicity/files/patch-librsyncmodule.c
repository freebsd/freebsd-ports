*** _librsyncmodule.c.orig	Sat Aug  9 17:26:51 2003
--- _librsyncmodule.c	Sat Aug  9 17:26:59 2003
***************
*** 13,19 ****
   * ----------------------------------------------------------------------- */
  
  #include <Python.h>
! #include <rsync.h>
  #define RS_JOB_BLOCKSIZE 65536
  
  static PyObject *librsyncError;
--- 13,19 ----
   * ----------------------------------------------------------------------- */
  
  #include <Python.h>
! #include <librsync.h>
  #define RS_JOB_BLOCKSIZE 65536
  
  static PyObject *librsyncError;

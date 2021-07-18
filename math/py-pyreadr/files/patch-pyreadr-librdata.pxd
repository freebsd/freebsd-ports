--- pyreadr/librdata.pxd.orig	2020-12-09 08:50:11 UTC
+++ pyreadr/librdata.pxd
@@ -11,7 +11,7 @@ cdef extern from '<sys/types.h>':
 cdef extern from 'Python.h':
     object PyByteArray_FromStringAndSize(const char *string, Py_ssize_t len)
 
-cdef extern from 'libs/librdata/src/rdata.h':
+cdef extern from '<rdata.h>':
 
     cdef enum rdata_type_t 'rdata_type_e':
         RDATA_TYPE_STRING
@@ -128,7 +128,7 @@ cdef extern from 'libs/librdata/src/rdata.h':
     rdata_error_t rdata_end_table(rdata_writer_t *writer, int32_t row_count, const char *datalabel);
     rdata_error_t rdata_end_file(rdata_writer_t *writer);
 
-cdef extern from 'libs/librdata/src/rdata_io_unistd.h':
+cdef extern from '<rdata_io_unistd.h>':
     cdef struct rdata_unistd_io_ctx_t 'rdata_unistd_io_ctx_s':
         int fd
 

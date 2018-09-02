<stdint.h> isn't bootlegged via gtest.h on FreeBSD 10.* leading to

In file included from test/horz_superres_test.cc:14:
In file included from av1/encoder/encoder.h:36:
av1/encoder/rd.h:304:26: error: use of undeclared identifier 'INT64_MAX'
  rd_stats->ref_rdcost = INT64_MAX;
                         ^
av1/encoder/rd.h:325:20: error: use of undeclared identifier 'INT64_MAX'
  rd_stats->dist = INT64_MAX;
                   ^
av1/encoder/rd.h:326:22: error: use of undeclared identifier 'INT64_MAX'
  rd_stats->rdcost = INT64_MAX;
                     ^
av1/encoder/rd.h:327:19: error: use of undeclared identifier 'INT64_MAX'
  rd_stats->sse = INT64_MAX;
                  ^
av1/encoder/rd.h:331:26: error: use of undeclared identifier 'INT64_MAX'
  rd_stats->ref_rdcost = INT64_MAX;
                         ^
5 errors generated.

--- av1/encoder/rd.h.orig	2018-06-25 14:54:59 UTC
+++ av1/encoder/rd.h
@@ -13,6 +13,7 @@
 #define AV1_ENCODER_RD_H_
 
 #include <limits.h>
+#include <stdint.h>
 
 #include "av1/common/blockd.h"
 

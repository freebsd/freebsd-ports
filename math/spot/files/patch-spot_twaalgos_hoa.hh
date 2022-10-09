- workaround for https://gitlab.lre.epita.fr/spot/spot/-/issues/515

--- spot/twaalgos/hoa.hh.orig	2022-10-09 17:09:51 UTC
+++ spot/twaalgos/hoa.hh
@@ -23,6 +23,7 @@
 #include <spot/misc/common.hh>
 #include <spot/twa/fwd.hh>
 #include <vector>
+#include <unordered_map>
 #include <utility>
 #include <functional>
 #include <bddx.h>

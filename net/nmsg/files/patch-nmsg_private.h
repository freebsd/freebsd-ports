--- nmsg/private.h.orig	2014-01-09 18:55:44.000000000 -0800
+++ nmsg/private.h	2014-07-26 13:45:33.000000000 -0700
@@ -1,5 +1,5 @@
 /*
- * Copyright (c) 2008-2013 by Farsight Security, Inc.
+ * Copyright (c) 2008-2014 by Farsight Security, Inc.
  *
  * Licensed under the Apache License, Version 2.0 (the "License");
  * you may not use this file except in compliance with the License.
@@ -35,6 +35,7 @@
 #include <ctype.h>
 #include <errno.h>
 #include <fcntl.h>
+#include <inttypes.h>
 #include <limits.h>
 #include <pthread.h>
 #include <poll.h>

--- src/kit/kit-lib.h.orig	2008-04-21 23:44:10.000000000 -0400
+++ src/kit/kit-lib.h	2008-04-21 23:48:03.000000000 -0400
@@ -0,0 +1,52 @@
+/* -*- Mode: C; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 8 -*- */
+/***************************************************************************
+ *
+ * kit-string.h : General utilities
+ *
+ * Copyright (C) 2007 David Zeuthen, <david@fubar.dk>
+ *
+ * Permission is hereby granted, free of charge, to any person
+ * obtaining a copy of this software and associated documentation
+ * files (the "Software"), to deal in the Software without
+ * restriction, including without limitation the rights to use, copy,
+ * modify, merge, publish, distribute, sublicense, and/or sell copies
+ * of the Software, and to permit persons to whom the Software is
+ * furnished to do so, subject to the following conditions:
+ *
+ * The above copyright notice and this permission notice shall be
+ * included in all copies or substantial portions of the Software.
+ *
+ * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
+ * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
+ * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
+ * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
+ * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
+ * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
+ * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
+ * DEALINGS IN THE SOFTWARE.
+ *
+ **************************************************************************/
+
+#if !defined (KIT_COMPILATION) && !defined(_KIT_INSIDE_KIT_H)
+#error "Only <kit/kit.h> can be included directly, this file may disappear or change contents."
+#endif
+
+#ifndef KIT_LIB_H
+#define KIT_LIB_H
+
+#include <sys/types.h>
+#include <stdio.h>
+
+#include <kit/kit.h>
+
+KIT_BEGIN_DECLS
+
+ssize_t kit_getline 	(char **lineptr, size_t *n, FILE *f);
+
+int kit_clearenv 	(void);
+
+KIT_END_DECLS
+
+#endif /* KIT_LIB_H */
+
+

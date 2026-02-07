--- sage.h.orig	2021-01-24 16:21:00 UTC
+++ sage.h
@@ -0,0 +1,23 @@
+/*
+  Coxeter version 3.0 Copyright (C) 2009 Mike Hansen
+  See file main.cpp for full copyright notice
+*/
+
+#ifndef SAGE_H /* guard against multiple inclusions */
+#define SAGE_H
+
+#include "globals.h"
+#include "coxgroup.h"
+#include "coxtypes.h"
+#include "schubert.h"
+#include "list.h"
+
+namespace sage {
+  using namespace coxeter;
+  using namespace coxtypes;
+  using namespace list;
+
+  void interval(List<CoxWord>& result, CoxGroup& W, const CoxWord& g, const CoxWord& h);
+}
+
+#endif

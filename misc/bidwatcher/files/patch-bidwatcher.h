$NetBSD: patch-aa,v 1.18 2005/02/27 10:40:04 rillig Exp $

The header file uses the FILE type without including <cstdio>.
This breaks (at least) on NetBSD-1.6.2.

--- bidwatcher.h.orig	Fri Feb 18 04:30:20 2005
+++ bidwatcher.h	Sat Feb 26 14:15:23 2005
@@ -29,6 +29,7 @@
 #include "config.h"
 #endif
 
+#include <cstdio>
 #include <string>
 
 using namespace std;

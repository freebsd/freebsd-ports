--- src/output-plugins/op_sguil.h.orig	Mon Mar 15 22:18:20 2004
+++ src/output-plugins/op_sguil.h	Sun Jan 15 22:32:07 2006
@@ -1,8 +1,9 @@
-/* $Id: op_sguil.h,v 1.2 2004/03/16 04:18:20 andrewbaker Exp $ */
+/* $Id: op_sguil.h,v 1.2 2005/03/03 21:07:44 bamm Exp $ */
+
 /*
-** Copyright (C) 2001 Andrew R. Baker <andrewb@snort.org>
+** Copyright (C) 2002-2004 Robert (Bamm) Visscher <bamm@sguil.net> 
 **
-** This program is distributed under the terms of version 1.0 of the 
+** This program is distributed under the terms of version 1.0 of the
 ** Q Public License.  See LICENSE.QPL for further details.
 **
 ** This program is distributed in the hope that it will be useful,
@@ -11,10 +12,4 @@
 **
 */
 
-#ifndef __OP_SGUIL_H__
-#define __OP_SGUIL_H__
-
 void OpSguil_Init();
-
-#endif  /* __OP_SGUIL_H__ */
-

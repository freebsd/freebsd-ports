$FreeBSD$
Add loopback support for FreeBSD.
author:  Radim Kolar

--- mtu.h.orig	Fri Oct 10 20:56:39 2003
+++ mtu.h	Tue Feb 17 21:10:49 2004
@@ -58,6 +58,7 @@
   {  4352, "FDDI" },
   {  4500, "token ring (2)" },
   {  9180, "FORE ATM" },
+  { 16384, "loopback" },
   { 16436, "sometimes loopback" },
   { 18000, "token ring x4" },
 };

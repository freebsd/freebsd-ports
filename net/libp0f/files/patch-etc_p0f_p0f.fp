--- etc/p0f/p0f.fp.orig	2009-07-28 18:31:33 UTC
+++ etc/p0f/p0f.fp
@@ -12,6 +12,10 @@
 # `-------------------------------------------------------------------------'
 #
 # (C) Copyright 2000-2006 by Michal Zalewski <lcamtuf@coredump.cx>
+# (C) Copyright 2011-2012 by Carnegie Mellon University
+#      - Roman Danyliw
+#      - version: 2012032901 (03/20/2012)
+#      - Contact <netsa-help@cert.org> for bugs and contributions
 #
 # Each line in this file specifies a single fingerprint. Please read the
 # information below carefully before attempting to append any signatures
@@ -376,19 +380,28 @@ S4:64:1:60:M1430,S,T,N,W0:.:Linux:2.4-2.
 
 S2:64:1:60:M*,S,T,N,W0:.:Linux:2.4 (large MTU?)
 S3:64:1:60:M*,S,T,N,W0:.:Linux:2.4 (newer)
-S4:64:1:60:M*,S,T,N,W0:.:Linux:2.4-2.6
+S4:64:1:60:M*,S,T,N,W0:.:Linux:2.4-2.6 (possibly CentOS 3.x)
 
 S3:64:1:60:M*,S,T,N,W1:.:Linux:2.6, seldom 2.4 (older, 1)
 S4:64:1:60:M*,S,T,N,W1:.:Linux:2.6, seldom 2.4 (older, 2)
 S3:64:1:60:M*,S,T,N,W2:.:Linux:2.6, seldom 2.4 (older, 3)
-S4:64:1:60:M*,S,T,N,W2:.:Linux:2.6, seldom 2.4 (older, 4)
+S4:64:1:60:M*,S,T,N,W2:.:Linux:2.6, seldom 2.4 (older, 4) (possibly FC 3-5, CentOS 4.x, Mandrake 10, Ubuntu 4-6)
 T4:64:1:60:M*,S,T,N,W2:.:Linux:2.6 (older, 5)
+S4:64:1:60:M*,S,T,N,W4:.:Linux:2.6 (older, 6) (possibly Mandriva 2010.x, Ubuntu 7.x)
 
-S4:64:1:60:M*,S,T,N,W5:.:Linux:2.6 (newer, 1)
-S4:64:1:60:M*,S,T,N,W6:.:Linux:2.6 (newer, 2)
-S4:64:1:60:M*,S,T,N,W7:.:Linux:2.6 (newer, 3)
+S4:64:1:60:M*,S,T,N,W5:.:Linux:2.6 (newer, 1) (possibly Mandriva 2008.x, 2009.1, Ubuntu 7-9)
+S4:64:1:60:M*,S,T,N,W6:.:Linux:2.6 (newer, 2) (possibly FC8-14, Chromium 5.x, Ubuntu 10.x, OpenSuse 11.x, CentOS 6.0, Gentoo 10.x, Slackware 12-13.1)
+S4:64:1:60:M*,S,T,N,W7:.:Linux:2.6 (newer, 3) or Mac OSX 10.3.1 (possibly FC 6, CentOS 5.x)
 T4:64:1:60:M*,S,T,N,W7:.:Linux:2.6 (newer, 4)
+S2:64:1:60:M*,S,T,N,W6:.:Linux:2.6 (newer, 5)
+S44:128:1:52:M*,N,W0,N,N,S:.:Linux:2.6 (newer, 6) (possibly Ubuntu 10.x)
+S4:64:1:52:M*,N,N,S,N,W5:.:Linux:2.6 (newer, 7) (possibly Ubuntu 8.x)
+S4:64:1:60:S,T,M*,N,W5:.:Linux:2.6 (newer, 8) (possibly Mandriva 2009.0)
+S3:64:1:60:M*,S,T,N,W6:.:Linux:2.6 (newer, 9) (possibly OpenSuse 11.4, Gentoo 11.0, Slackware 13.37)
+S10:64:1:60:M*,S,T,N,W7:.:Linux:2.6 (newer, 10) (possibly Ubuntu 11.04)
+S10:64:1:60:M*,S,T,N,W6:.:Linux:2.6 (newer, 11) (possibly FC 15, CentOS 6.2, Knoppix 6.x)
 
+S10:64:1:60:M1460,S,T,N,W4:.:Linux:3.0-1 (1) (possibly Ubuntu 11.10, FC 16, Gentoo 11.2, OpenSUSE 12.x)
 
 S20:64:1:60:M*,S,T,N,W0:.:Linux:2.2 (1)
 S22:64:1:60:M*,S,T,N,W0:.:Linux:2.2 (2)
@@ -433,8 +446,10 @@ T4:64:1:60:M1412,S,T,N,W0:.:Linux:2.4 (r
 65535:64:1:60:M*,N,W1,N,N,T:Z:FreeBSD:5.1 (2)
 65535:64:1:60:M*,N,W2,N,N,T:Z:FreeBSD:5.1 (3)
 65535:64:1:64:M*,N,N,S,N,W1,N,N,T:.:FreeBSD:5.3-5.4
-65535:64:1:64:M*,N,W1,N,N,T,S,E:P:FreeBSD:6.x (1)
+65535:64:1:64:M*,N,W1,N,N,T,S,E:P:FreeBSD:6.x (1) or MacOS X 10.6
 65535:64:1:64:M*,N,W0,N,N,T,S,E:P:FreeBSD:6.x (2)
+65535:64:1:60:M*,N,W3,S,T:.:FreeBSD:7.x, 8.x
+65535:64:1:60:M*,N,W6,S,T:.:FreeBSD:9.x
 
 65535:64:1:44:M*:Z:FreeBSD:5.2 (RFC1323-)
 
@@ -446,7 +461,7 @@ T4:64:1:60:M1412,S,T,N,W0:.:Linux:2.4 (r
 65535:64:0:60:M*,N,W0,N,N,T0:.:-NetBSD:1.6 (Opera)
 16384:64:1:60:M*,N,W0,N,N,T0:.:NetBSD:1.6
 65535:64:1:60:M*,N,W1,N,N,T0:.:NetBSD:1.6W-current (DF)
-65535:64:1:60:M*,N,W0,N,N,T0:.:NetBSD:1.6X (DF)
+65535:64:1:60:M*,N,W0,N,N,T0:.:NetBSD:1.6X (DF) or Sony PlayStation 3
 32768:64:1:60:M*,N,W0,N,N,T0:.:NetBSD:1.6Z or 2.0 (DF)
 32768:64:1:64:M1416,N,W0,S,N,N,N,N,T0:.:NetBSD:2.0G (DF)
 32768:64:1:64:M*,N,W0,S,N,N,N,N,T0:.:NetBSD:3.0 (DF)
@@ -474,9 +489,9 @@ S34:64:1:48:M*,N,N,S:.:Solaris:9
 S34:64:1:48:M*,N,N,N,N:.:Solaris:9 (no sack)
 S44:255:1:44:M*:.:Solaris:7
 
-4096:64:0:44:M1460:.:SunOS:4.1.x
+4096:64:0:44:M1460:.:SunOS:4.1.x, nmap syn scan(8)
 
-S34:64:1:52:M*,N,W0,N,N,S:.:Solaris:10 (beta)
+S34:64:1:52:M*,N,W0,N,N,S:.:Solaris:10 (beta), OpenSolaris
 32850:64:1:64:M*,N,N,T,N,W1,N,N,S:.:Solaris:10 (1203?)
 32850:64:1:64:M*,N,W1,N,N,T,N,N,S:.:Solaris:9.1
 
@@ -516,6 +531,11 @@ S2:255:1:48:M*,W0,E:.:MacOS:8.6 classic
 32768:255:1:48:M1380,N,N,N,N:.:MacOS:9.1 (OT 2.7.4) (1)
 65535:255:1:48:M*,N,N,N,N:.:MacOS:9.1 (OT 2.7.4) (2)
 
+65535:64:1:64:M*,N,W3,N,N,T,S,E:P:MacOS:X 10.x (10.3-7)
+65535:64:1:64:M*,N,W2,N,N,T,S,E:P:iOS:3.1+, 4.1-3
+65535:64:1:48:M*,S,E:P:iOS:3.x, 4.2
+65535:64:1:64:M*,N,W4,N,N,T,S,E:P:iOS:5.x
+
 # ----------------- Windows -----------------
 
 # Windows TCP/IP stack is a mess. For most recent XP, 2000 and
@@ -563,8 +583,8 @@ T31:128:1:44:M1414:.:Windows:NT 4.0 SP6a
 # either dubious or non-specific (no service pack data)
 # were deleted and replaced with generics at the end.
 
-65535:128:1:48:M*,N,N,S:.:Windows:2000 SP4, XP SP1+
-%8192:128:1:48:M*,N,N,S:.:Windows:2000 SP2+, XP SP1+ (seldom 98)
+65535:128:1:48:M*,N,N,S:.:Windows:2000 SP4, XP SP1+, 2003
+8192:128:1:48:M*,N,N,S:.:Windows:2000 SP2+, XP SP1+ (seldom 98), Vista SP1, 7 SP1, 2008 SP2
 S20:128:1:48:M*,N,N,S:.:Windows:SP3
 S45:128:1:48:M*,N,N,S:.:Windows:2000 SP4, XP SP1+ (2)
 40320:128:1:48:M*,N,N,S:.:Windows:2000 SP4
@@ -575,12 +595,16 @@ S44:128:1:48:M*,N,N,S:.:Windows:XP SP1+,
 64512:128:1:48:M*,N,N,S:.:Windows:XP SP1+, 2000 SP3 (2)
 32767:128:1:48:M*,N,N,S:.:Windows:XP SP1+, 2000 SP4 (3)
 
-# Windows 2003 & Vista
+# Windows 2003, Vista, 2008, 7, and 8
 
 8192:128:1:52:M*,W8,N,N,N,S:.:Windows:Vista (beta)
 32768:32:1:52:M1460,N,W0,N,N,S:.:Windows:2003 AS
 65535:64:1:52:M1460,N,W2,N,N,S:.:Windows:2003 (1)
 65535:64:1:48:M1460,N,N,S:.:Windows:2003 (2)
+8192:128:1:52:M*,N,W2,N,N,S:.:Windows:Vista SP1, 7 SP1
+8192:128:1:52:M*,N,W8,N,N,S:.:Windows:Vista SP0/SP2, 7 SP0+, 2008 SP0
+65535:64:0:60:M*,N,W0,S,T:.:Windows:7 SP1+
+65535:128:1:52:M*,N,W3,N,N,S:.:Windows:8 Consumer Preview
 
 # Odds, ends, mods:
 
@@ -792,6 +816,9 @@ S12:64:0:44:M1452:.:AXIS:Printer Server 
 2048:64:0:40:.:.:-*NMAP:syn scan (2)
 3072:64:0:40:.:.:-*NMAP:syn scan (3)
 4096:64:0:40:.:.:-*NMAP:syn scan (4)
+1024:64:0:44:M*:.:-*NMAP:syn scan (5)
+2048:64:0:44:M*:.:-*NMAP:syn scan (6)
+3072:64:0:44:M*:.:-*NMAP:syn scan (7)
 
 1024:64:0:40:.:A:-*NMAP:TCP sweep probe (1)
 2048:64:0:40:.:A:-*NMAP:TCP sweep probe (2)
@@ -808,10 +835,22 @@ S12:64:0:44:M1452:.:AXIS:Printer Server 
 3072:64:0:60:W10,N,M265,T,E:PF:-*NMAP:OS detection probe w/flags (3)
 4096:64:0:60:W10,N,M265,T,E:PF:-*NMAP:OS detection probe w/flags (4)
 
+1:64:0:60:W10,N,M1460,T,S:A:-*NMAP:OS detection probe (5)
+63:64:0:60:M1400,W0,S,T,E:A:-*NMAP:OS detection probe (6)
+4:64:0:60:T,N,N,W5,N,M640:A:-*NMAP:OS detection probe (7) 
+4:64:0:56:S,T,W10,E:A:-*NMAP:OS detection probe (8)
+16:64:0:60:M536,S,T,W10,E:A:-*NMAP:OS detection probe (9)
+512:64:0:56:M265,S,T:A:-*NMAP:OS detection probe (10)
+3:64:0:52:W10,N,M1460,S,N,N:UX:-*NMAP:OS detection probe (11)
+31337:64:0:60:W10,N,M265,T,S:A:-*NMAP:OS detection probe (12)
+
 32767:64:0:40:.:.:-*NAST:syn scan
 
 12345:255:0:40:.:A:-p0f:sendsyn utility
 
+S4:255:0:40:.:A:-*sinfp:active scan (1)
+S4:255:0:60:M1460,T,W1,S,E:A:-*sinfp:active scan (2) 
+
 # UFO - see tmp/*:
 56922:128:0:40:.:A:-@Mysterious:port scanner (?)
 5792:64:1:60:M1460,S,T,N,W0:T:-@Mysterious:NAT device (2nd tstamp)

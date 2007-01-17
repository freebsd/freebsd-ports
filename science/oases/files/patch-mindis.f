Using illigal chars

--- mindis/mindis.f~	Fri Feb 11 06:06:05 2000
+++ mindis/mindis.f	Wed Jan 17 13:57:49 2007
@@ -1877,7 +1877,7 @@
 
       RETURN
       END
-
+
       FUNCTION ROUND( X, IDIG )
 
 C     IDIG: ROUND X TO IDIG DIGITS
@@ -1897,7 +1897,7 @@
 
       RETURN
       END
-
+
       FUNCTION RNDDN( X, IDIG )
 
 C     IDIG: ROUND DOWN X TO IDIG DIGITS
@@ -1924,7 +1924,7 @@
 
       RETURN
       END
-
+
       FUNCTION RNDUP( X, IDIG )
 
 C     IDIG: ROUND UP X TO IDIG DIGITS
@@ -1951,7 +1951,7 @@
 
       RETURN
       END
-
+
       SUBROUTINE T4010
 
 C     PUTS A VT340 TERMINAL IN 4010 EMULATION MODE
@@ -1963,7 +1963,7 @@
 
       RETURN
       END
-
+
       SUBROUTINE VT340
 
 C     RESETS THE TERMINAL
@@ -1975,7 +1975,7 @@
 
       RETURN
       END
-
+
       SUBROUTINE REALNO( X, I, A, B)
 
 C     EMULATES DISSPLA REALNO FUNCTION
@@ -2002,7 +2002,7 @@
 
       RETURN
       END
-
+
       SUBROUTINE INTNO( INUM, A, B)
 
 C     EMULATES DISSPLA INTNO FUNCTION
@@ -2022,7 +2022,7 @@
 
       RETURN
       END
-
+
       SUBROUTINE RLREAL( X, I, A, B)
 
 C     EMULATES DISSPLA RLREAL FUNCTION
@@ -2049,7 +2049,7 @@
 
       RETURN
       END
-
+
       SUBROUTINE RLINT( INUM, A, B)
 
 C     EMULATES DISSPLA INTNO FUNCTION
@@ -2069,7 +2069,7 @@
 
       RETURN
       END
-
+
       SUBROUTINE AREA2D( XLEN, YLEN )
 
 C     Routine to define plot size
@@ -2078,7 +2078,7 @@
 
       RETURN
       END
-
+
       SUBROUTINE COMPRS
 
 C     COPPER PENNY FUSE
@@ -2091,7 +2091,7 @@
 
       RETURN
       END
-
+
       SUBROUTINE UNITS( SCALE )
 
 C     EMULATES DISPLA UNITS ROUTINE FOR SELECTING METRIC OR US
@@ -2103,7 +2103,7 @@
 
       RETURN
       END
-
+
       SUBROUTINE SETCLR( LCOLOR )
 
 C     EMULATES DISPLA SETCLR ROUTINE FOR SELECTING COLORS
@@ -2125,7 +2125,7 @@
 
       RETURN
       END
-
+
       SUBROUTINE GRACE( X )
 
 C     Set the grace value for plot clipping
@@ -2136,7 +2136,7 @@
 
       RETURN
       END
-
+
       SUBROUTINE SHDCHR( ANGRAY, NANGS, GAPRAY, NGAPS )
 
 C     COPPER PENNY FUSE
@@ -2145,7 +2145,7 @@
 
       RETURN
       END
-
+
       SUBROUTINE HWSCAL( IPSCAL )
 
 C     COPPER PENNY FUSE
@@ -2154,7 +2154,7 @@
 
       RETURN
       END
-
+
       SUBROUTINE XNONUM
 
 C     COPPER PENNY FUSE
@@ -2163,7 +2163,7 @@
 
       RETURN
       END
-
+
       SUBROUTINE YNONUM
 
 C     COPPER PENNY FUSE
@@ -2172,7 +2172,7 @@
 
       RETURN
       END
-
+
       SUBROUTINE ZNONUM
 
 C     COPPER PENNY FUSE
@@ -2181,7 +2181,7 @@
 
       RETURN
       END
-
+
       FUNCTION XINT( INUM )
 
 C     COPPER PENNY FUSE
@@ -2191,7 +2191,7 @@
 
       RETURN
       END
-
+
       FUNCTION XREAL( ANUM, IPLACE )
 
 C     COPPER PENNY FUSE
@@ -2201,7 +2201,7 @@
 
       RETURN
       END
-
+
       FUNCTION XPOSN( XVAL, YVAL )
 
 C     COPPER PENNY FUSE
@@ -2211,7 +2211,7 @@
 
       RETURN
       END
-
+
       FUNCTION YPOSN( XVAL, YVAL )
 
 C     COPPER PENNY FUSE
@@ -2221,21 +2221,21 @@
 
       RETURN
       END
-
+
       SUBROUTINE THKRND( FACTOR )
 
 C     COPPER PENNY FUSE
 
       RETURN
       END
-
+
       SUBROUTINE BSCALE( XTIMES, YTIMES )
 
 C     COPPER PENNY FUSE
 
       RETURN
       END
-
+
       SUBROUTINE BLPOLY( XARAY, YARAY, NPTS, FRM )
 
 C     COPPER PENNY FUSE
@@ -2244,7 +2244,7 @@
 
       RETURN
       END
-
+
       SUBROUTINE BLREC( XORG, YORG, WIDE, HIGH, FRM )
 
 C     ROUTINE TO BLANK OUT A RECTANGULAR AREA
@@ -2258,14 +2258,14 @@
 
       RETURN
       END
-
+
       SUBROUTINE SWISSM
 
 C     SELECTS SWISSM FONT
 
       RETURN
       END
-
+
       SUBROUTINE ZUSE( LSTRGZ, ISTRGZ )
 
 C     COPPER PENNY FUSE
@@ -2273,7 +2273,7 @@
       CHARACTER*40 LSTRGZ
       RETURN
       END
-
+
       SUBROUTINE Z1USE( LSTRGZ, ISTRGZ )
 
 C     COPPER PENNY FUSE
@@ -2281,7 +2281,7 @@
       CHARACTER*40 LSTRGZ
       RETURN
       END
-
+
       SUBROUTINE Z2USE( LSTRGZ, ISTRGZ )
 
 C     COPPER PENNY FUSE
@@ -2289,7 +2289,7 @@
       CHARACTER*40 LSTRGZ
       RETURN
       END
-
+
       SUBROUTINE Z3USE( LSTRGZ, ISTRGZ )
 
 C     COPPER PENNY FUSE
@@ -2297,7 +2297,7 @@
       CHARACTER*40 LSTRGZ
       RETURN
       END
-
+
       SUBROUTINE Z4USE( LSTRGZ, ISTRGZ )
 
 C     COPPER PENNY FUSE
@@ -2305,7 +2305,7 @@
       CHARACTER*40 LSTRGZ
       RETURN
       END
-
+
       SUBROUTINE Z5USE( LSTRGZ, ISTRGZ )
 
 C     COPPER PENNY FUSE
@@ -2313,7 +2313,7 @@
       CHARACTER*40 LSTRGZ
       RETURN
       END
-
+
       SUBROUTINE Z6USE( LSTRGZ, ISTRGZ )
 
 C     COPPER PENNY FUSE
@@ -2321,7 +2321,6 @@
       CHARACTER*40 LSTRGZ
       RETURN
       END
-
       SUBROUTINE HWROT( IPLROT )
 
 C     COPPER PENNY FUSE
@@ -2329,7 +2328,6 @@
       CHARACTER*40 IPLROT
       RETURN
       END
-
       SUBROUTINE POPNAM( LSTRING, LEN )
 
 C     COPPER PENNY FUSE

http://math-atlas.sourceforge.net/errata.html
Large blocking factors hurt LAPACK performance for small N

--- interfaces/lapack/F77/src/ilaenv.f	Mon Dec 22 09:07:51 2003
+++ interfaces/lapack/F77/src/ilaenv.f	Mon Mar  5 12:41:41 2007
@@ -7,7 +7,7 @@
 *     June 30, 1999
 *
 *  -- Modified by R. Clint Whaley for ATLAS Fortran77 LAPACK interface,
-*     1999
+*     1999, 2006
 *
 *     .. Scalar Arguments ..
       CHARACTER*( * )    NAME, OPTS
@@ -111,6 +111,7 @@
       CHARACTER*3        C3
       CHARACTER*6        SUBNAM
       INTEGER            I, IC, IZ, NB, NBMIN, NX
+      INTEGER            MN, ATLNB
 *     ..
 *     .. Intrinsic Functions ..
       INTRINSIC          CHAR, ICHAR, INT, MIN, REAL
@@ -207,13 +208,10 @@
 *     ISPEC = 1:  block size
 *
 *     ATLAS sets default blocking factor to the internal blocking factor of
-*     GEMM.  In routines such as QR where unblocked code addresses a panel
-*     (as opposed to a NBxNB block as in POTF2), this will often be too large
-*     to provide the optimal performance due to the slowness of the panel
-*     factorization.  Asymptotically, however, you will want it at least
-*     this big.  Therefore, we choose this NB as default since how much smaller
-*     an NB is required is very problem size and system architecture
-*     dependent.  Note that the recursive routines provided by ATLAS
+*     GEMM.  For particular routines, we then examine input parameters to
+*     see if we should reduce it (for instance, to ensure that we don't
+*     spend too much time in the unblocked level-2 portion of the algorithm).
+*     Note that the recursive routines provided by ATLAS
 *     (presently, LU & Cholesky) do not need this value.
 *
       NB = 60
@@ -226,6 +224,179 @@
       ELSE IF (DCPLX) THEN
          CALL ATL_F77WRAP_ZGETNB(NB)
       ENDIF
+      ATLNB = NB
+*
+*     Find minimum dimension of problem: don't want NB bigger than that
+*
+      MN = N1
+      IF (N2 .GT. 0) THEN
+         IF (MN .GT. N2) MN = N2
+         IF (N3 .GT. 0) THEN
+            IF (MN .GT. N3) MN = N3
+            IF (N4 .GT. 0) THEN
+               IF (MN .GT. N4) MN = N4
+            END IF
+         END IF
+      END IF
+*
+*     Make sure NB is not close to size of entire dimension, unless smallest
+*     dimension is so small you might as well use unblocked code the whole way
+*
+      IF (MN .LE. 3) THEN
+         NB = MN;
+      ELSE IF (NB*5 .GT. MN) THEN
+         IF (MN .LT. 16) THEN
+            IF (MN .LT. 8) THEN
+               NB = 2
+            ELSE
+               NB = 4
+            END IF
+         ELSE
+           NB = (MN / 4)
+           IF (NB .GT. 4) THEN
+              NB = (NB/4)*4
+           ENDIF
+         END IF
+      END IF
+      IF( C2.EQ.'GE' ) THEN
+         IF( C3.EQ.'TRF' ) THEN
+            NB = NB
+*
+*        QR requires extra flops for blocking, so restrain total NB
+*
+         ELSE IF( C3.EQ.'QRF' .OR. C3.EQ.'RQF' .OR. C3.EQ.'LQF' .OR.
+     $            C3.EQ.'QLF' ) THEN
+            IF (NB .GT. 80) THEN
+               IF( SNAME ) THEN
+                  NB = 60
+               ELSE
+                  NB = 40
+               END IF
+            END IF
+         ELSE IF( C3.EQ.'HRD' ) THEN
+            IF (NB .GT. 80) THEN
+               IF( SNAME ) THEN
+                  NB = 60
+               ELSE
+                  NB = 40
+               END IF
+            END IF
+         ELSE IF( C3.EQ.'BRD' ) THEN
+            IF (NB .GT. 80) THEN
+               IF( SNAME ) THEN
+                  NB = 60
+               ELSE
+                  NB = 40
+               END IF
+            END IF
+         ELSE IF( C3.EQ.'TRI' ) THEN
+               NB = NB
+         END IF
+      ELSE IF( C2.EQ.'PO' ) THEN
+         IF( C3.EQ.'TRF' ) THEN
+            NB = NB
+         END IF
+      ELSE IF( C2.EQ.'SY' ) THEN
+         IF( C3.EQ.'TRF' ) THEN
+            NB = NB
+         ELSE IF( SNAME .AND. C3.EQ.'TRD' ) THEN
+            IF (NB .GT. 80) THEN
+               IF( SNAME ) THEN
+                  NB = 60
+               ELSE
+                  NB = 40
+               END IF
+            END IF
+         ELSE IF( SNAME .AND. C3.EQ.'GST' ) THEN
+            NB = NB
+         END IF
+      ELSE IF( CNAME .AND. C2.EQ.'HE' ) THEN
+         IF( C3.EQ.'TRF' ) THEN
+            NB = NB
+         ELSE IF( C3.EQ.'TRD' ) THEN
+            IF (NB .GT. 80) THEN
+               IF( SNAME ) THEN
+                  NB = 60
+               ELSE
+                  NB = 40
+               END IF
+            END IF
+         ELSE IF( C3.EQ.'GST' ) THEN
+            NB = NB
+         END IF
+      ELSE IF( SNAME .AND. C2.EQ.'OR' ) THEN
+         IF( C3( 1:1 ).EQ.'G' ) THEN
+            IF( C4.EQ.'QR' .OR. C4.EQ.'RQ' .OR. C4.EQ.'LQ' .OR.
+     $          C4.EQ.'QL' .OR. C4.EQ.'HR' .OR. C4.EQ.'TR' .OR.
+     $          C4.EQ.'BR' ) THEN
+               IF (NB .GT. 80) NB = 60
+            END IF
+         ELSE IF( C3( 1:1 ).EQ.'M' ) THEN
+            IF( C4.EQ.'QR' .OR. C4.EQ.'RQ' .OR. C4.EQ.'LQ' .OR.
+     $          C4.EQ.'QL' .OR. C4.EQ.'HR' .OR. C4.EQ.'TR' .OR.
+     $          C4.EQ.'BR' ) THEN
+               IF (NB .GT. 80) NB = 60
+            END IF
+         END IF
+      ELSE IF( CNAME .AND. C2.EQ.'UN' ) THEN
+         IF( C3( 1:1 ).EQ.'G' ) THEN
+            IF( C4.EQ.'QR' .OR. C4.EQ.'RQ' .OR. C4.EQ.'LQ' .OR.
+     $          C4.EQ.'QL' .OR. C4.EQ.'HR' .OR. C4.EQ.'TR' .OR.
+     $          C4.EQ.'BR' ) THEN
+               IF (NB .GT. 80) NB = 40
+            END IF
+         ELSE IF( C3( 1:1 ).EQ.'M' ) THEN
+            IF( C4.EQ.'QR' .OR. C4.EQ.'RQ' .OR. C4.EQ.'LQ' .OR.
+     $          C4.EQ.'QL' .OR. C4.EQ.'HR' .OR. C4.EQ.'TR' .OR.
+     $          C4.EQ.'BR' ) THEN
+               IF (NB .GT. 80) NB = 40
+            END IF
+         END IF
+      ELSE IF( C2.EQ.'GB' ) THEN
+         IF( C3.EQ.'TRF' ) THEN
+            IF( SNAME ) THEN
+               NB = NB
+            ELSE
+               NB = NB
+            END IF
+         END IF
+      ELSE IF( C2.EQ.'PB' ) THEN
+         IF( C3.EQ.'TRF' ) THEN
+            IF( SNAME ) THEN
+               IF( N2.LE.64 ) THEN
+                  NB = NB
+               ELSE
+                  NB = NB
+               END IF
+            ELSE
+               IF( N2.LE.64 ) THEN
+                  NB = NB
+               ELSE
+                  NB = NB
+               END IF
+            END IF
+         END IF
+      ELSE IF( C2.EQ.'TR' ) THEN
+         IF( C3.EQ.'TRI' ) THEN
+            IF( SNAME ) THEN
+               NB = NB
+            ELSE
+               NB = NB
+            END IF
+         END IF
+      ELSE IF( C2.EQ.'LA' ) THEN
+         IF( C3.EQ.'UUM' ) THEN
+            IF( SNAME ) THEN
+               NB = NB
+            ELSE
+               NB = NB
+            END IF
+         END IF
+      ELSE IF( SNAME .AND. C2.EQ.'ST' ) THEN
+         IF( C3.EQ.'EBZ' ) THEN
+            NB = 1
+         END IF
+      END IF
 *
       ILAENV = NB
       RETURN

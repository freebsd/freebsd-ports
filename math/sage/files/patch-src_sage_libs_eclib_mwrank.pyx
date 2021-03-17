--- src/sage/libs/eclib/mwrank.pyx.orig	2021-03-16 21:40:43 UTC
+++ src/sage/libs/eclib/mwrank.pyx
@@ -28,6 +28,7 @@ from cysignals.signals cimport sig_on, sig_off
 from sage.cpython.string cimport char_to_str, str_to_bytes
 from sage.cpython.string import FS_ENCODING
 from sage.libs.eclib cimport bigint, Curvedata, mw, two_descent
+from sage.rings.all import Integer
 
 cdef extern from "wrap.cpp":
     ### misc functions ###
@@ -55,8 +56,8 @@ cdef extern from "wrap.cpp":
     char* mw_getbasis(mw* m)
     double mw_regulator(mw* m)
     int mw_rank(mw* m)
-    int mw_saturate(mw* m, bigint* index, char** unsat,
-                    long sat_bd, int odd_primes_only)
+    int mw_saturate(mw* m, long* index, char** unsat,
+                    long sat_bd, long sat_low_bd)
     void mw_search(mw* m, char* h_lim, int moduli_option, int verb)
 
     ### two_descent ###
@@ -67,9 +68,8 @@ cdef extern from "wrap.cpp":
     long two_descent_get_rank(two_descent* t)
     long two_descent_get_rank_bound(two_descent* t)
     long two_descent_get_selmer_rank(two_descent* t)
-    void two_descent_saturate(two_descent* t, long sat_bd)
+    void two_descent_saturate(two_descent* t, long sat_bd, long sat_low_bd)
 
-
 cdef object string_sigoff(char* s):
     sig_off()
     # Makes a python string and deletes what is pointed to by s.
@@ -445,7 +445,6 @@ cdef class _Curvedata:   # cython class wrapping eclib
             -1269581104000000
         """
         sig_on()
-        from sage.rings.all import Integer
         return Integer(string_sigoff(Curvedata_getdiscr(self.x)))
 
     def conductor(self):
@@ -467,7 +466,6 @@ cdef class _Curvedata:   # cython class wrapping eclib
             126958110400
         """
         sig_on()
-        from sage.rings.all import Integer
         return Integer(string_sigoff(Curvedata_conductor(self.x)))
 
     def isogeny_class(self, verbose=False):
@@ -503,6 +501,36 @@ cdef class _Curvedata:   # cython class wrapping eclib
 
 ############# _mw #################
 
+def parse_point_list(s):
+    r"""
+    Parse a string representing a list of points.
+
+    INPUT:
+
+    - ``s`` (string) -- string representation of a list of points, for
+      example '[]', '[[1:2:3]]', or '[[1:2:3],[4:5:6]]'.
+
+    OUTPUT:
+
+    (list)  a list of triples of integers, for example [], [[1,2,3]], [[1,2,3],[4,5,6]].
+
+    EXAMPLES::
+
+        sage: from sage.libs.eclib.mwrank import parse_point_list
+        sage: parse_point_list('[]')
+        []
+        sage: parse_point_list('[[1:2:3]]')
+        [[1, 2, 3]]
+        sage: parse_point_list('[[1:2:3],[4:5:6]]')
+        [[1, 2, 3], [4, 5, 6]]
+
+    """
+    s = s.replace(":", ",").replace(" ", "")
+    if s == '[]':
+        return []
+    pts = s[2:-2].split('],[')
+    return [[Integer(x) for x in pt.split(",")] for pt in pts]
+
 cdef class _mw:
     """
     Cython class wrapping eclib's mw class.
@@ -561,72 +589,37 @@ cdef class _mw:
             sage: EQ.search(1)
             P1 = [0:1:0]         is torsion point, order 1
             P1 = [-3:0:1]         is generator number 1
-            ...
-            P4 = [12:35:27]      = 1*P1 + -1*P2 + -1*P3 (mod torsion)
-
-        The previous command produces the following output::
-
-            P1 = [0:1:0]         is torsion point, order 1
-            P1 = [-3:0:1]         is generator number 1
-            saturating up to 20...Checking 2-saturation
-            Points have successfully been 2-saturated (max q used = 7)
-            Checking 3-saturation
-            Points have successfully been 3-saturated (max q used = 7)
-            Checking 5-saturation
-            Points have successfully been 5-saturated (max q used = 23)
-            Checking 7-saturation
-            Points have successfully been 7-saturated (max q used = 41)
-            Checking 11-saturation
-            Points have successfully been 11-saturated (max q used = 17)
-            Checking 13-saturation
-            Points have successfully been 13-saturated (max q used = 43)
-            Checking 17-saturation
-            Points have successfully been 17-saturated (max q used = 31)
-            Checking 19-saturation
-            Points have successfully been 19-saturated (max q used = 37)
+            saturating up to 20...Saturation index bound (for points of good reduction)  = 3
+            Reducing saturation bound from given value 20 to computed index bound 3
+            Checking saturation at [ 2 3 ]
+            Checking 2-saturation 
+            Points were proved 2-saturated (max q used = 7)
+            Checking 3-saturation 
+            Points were proved 3-saturated (max q used = 7)
             done
             P2 = [-2:3:1]         is generator number 2
-            saturating up to 20...Checking 2-saturation
+            saturating up to 20...Saturation index bound (for points of good reduction)  = 4
+            Reducing saturation bound from given value 20 to computed index bound 4
+            Checking saturation at [ 2 3 ]
+            Checking 2-saturation 
             possible kernel vector = [1,1]
             This point may be in 2E(Q): [14:-52:1]
-            ...and it is!
+            ...and it is! 
             Replacing old generator #1 with new generator [1:-1:1]
+            Reducing index bound from 4 to 2
             Points have successfully been 2-saturated (max q used = 7)
             Index gain = 2^1
-            Checking 3-saturation
-            Points have successfully been 3-saturated (max q used = 13)
-            Checking 5-saturation
-            Points have successfully been 5-saturated (max q used = 67)
-            Checking 7-saturation
-            Points have successfully been 7-saturated (max q used = 53)
-            Checking 11-saturation
-            Points have successfully been 11-saturated (max q used = 73)
-            Checking 13-saturation
-            Points have successfully been 13-saturated (max q used = 103)
-            Checking 17-saturation
-            Points have successfully been 17-saturated (max q used = 113)
-            Checking 19-saturation
-            Points have successfully been 19-saturated (max q used = 47)
-            done (index = 2).
+            done, index = 2.
             Gained index 2, new generators = [ [1:-1:1] [-2:3:1] ]
             P3 = [-14:25:8]       is generator number 3
-            saturating up to 20...Checking 2-saturation
-            Points have successfully been 2-saturated (max q used = 11)
-            Checking 3-saturation
-            Points have successfully been 3-saturated (max q used = 13)
-            Checking 5-saturation
-            Points have successfully been 5-saturated (max q used = 71)
-            Checking 7-saturation
-            Points have successfully been 7-saturated (max q used = 101)
-            Checking 11-saturation
-            Points have successfully been 11-saturated (max q used = 127)
-            Checking 13-saturation
-            Points have successfully been 13-saturated (max q used = 151)
-            Checking 17-saturation
-            Points have successfully been 17-saturated (max q used = 139)
-            Checking 19-saturation
-            Points have successfully been 19-saturated (max q used = 179)
-            done (index = 1).
+            saturating up to 20...Saturation index bound (for points of good reduction)  = 3
+            Reducing saturation bound from given value 20 to computed index bound 3
+            Checking saturation at [ 2 3 ]
+            Checking 2-saturation 
+            Points were proved 2-saturated (max q used = 11)
+            Checking 3-saturation 
+            Points were proved 3-saturated (max q used = 13)
+            done, index = 1.
             P4 = [-1:3:1]        = -1*P1 + -1*P2 + -1*P3 (mod torsion)
             P4 = [0:2:1]         = 2*P1 + 0*P2 + 1*P3 (mod torsion)
             P4 = [2:13:8]        = -3*P1 + 1*P2 + -1*P3 (mod torsion)
@@ -687,7 +680,7 @@ cdef class _mw:
         sig_on()
         return string_sigoff(mw_getbasis(self.x))
 
-    def process(self, point, sat=0):
+    def process(self, point, saturation_bound=0):
         """
         Processes the given point, adding it to the mw group.
 
@@ -697,10 +690,12 @@ cdef class _mw:
           An ``ArithmeticError`` is raised if the point is not on the
           curve.
 
-        - ``sat`` (int, default 0) --saturate at primes up to ``sat``.
-          No saturation is done if ``sat=0``.  (Note that it is more
-          efficient to add several points at once and then saturate
-          just once at the end).
+        - ``saturation_bound`` (int, default 0) --saturate at primes up to ``saturation_bound``.
+          No saturation is done if ``saturation_bound=0``.  If ``saturation_bound=-1`` then
+          saturation is done at all primes, by computing a bound on
+          the saturation index.  Note that it is more efficient to add
+          several points at once and then saturate just once at the
+          end.
 
         .. NOTE::
 
@@ -746,7 +741,7 @@ cdef class _mw:
         cdef _bigint x,y,z
         sig_on()
         x,y,z = _bigint(point[0]), _bigint(point[1]), _bigint(point[2])
-        r = mw_process(self.curve, self.x, x.x, y.x, z.x, sat)
+        r = mw_process(self.curve, self.x, x.x, y.x, z.x, saturation_bound)
         sig_off()
         if r != 0:
             raise ArithmeticError("point (=%s) not on curve." % point)
@@ -757,8 +752,8 @@ cdef class _mw:
 
         OUTPUT:
 
-        (string) String representation of the points in the basis of
-        the mw group.
+        (list) list of integer triples giving the projective
+        coordinates of the points in the basis.
 
         EXAMPLES::
 
@@ -768,13 +763,13 @@ cdef class _mw:
             sage: EQ = _mw(E)
             sage: EQ.search(3)
             sage: EQ.getbasis()
-            '[[0:-1:1], [-1:1:1]]'
+            [[0, -1, 1], [-1, 1, 1]]
             sage: EQ.rank()
             2
         """
         sig_on()
         s = string_sigoff(mw_getbasis(self.x))
-        return s
+        return parse_point_list(s)
 
     def regulator(self):
         """
@@ -797,7 +792,7 @@ cdef class _mw:
             sage: EQ = _mw(E)
             sage: EQ.search(3)
             sage: EQ.getbasis()
-            '[[0:-1:1], [-1:1:1]]'
+            [[0, -1, 1], [-1, 1, 1]]
             sage: EQ.rank()
             2
             sage: EQ.regulator()
@@ -824,40 +819,55 @@ cdef class _mw:
             sage: EQ = _mw(E)
             sage: EQ.search(3)
             sage: EQ.getbasis()
-            '[[0:-1:1], [-1:1:1]]'
+            [[0, -1, 1], [-1, 1, 1]]
             sage: EQ.rank()
             2
         """
         sig_on()
         r = mw_rank(self.x)
         sig_off()
-        from sage.rings.all import Integer
         return Integer(r)
 
-    def saturate(self, int sat_bd=-1, int odd_primes_only=0):
+    def saturate(self, int sat_bd=-1, int sat_low_bd=2):
         """
         Saturates the current subgroup of the mw group.
 
         INPUT:
 
-        - ``sat_bnd`` (int, default -1) -- bound on primes at which to
-          saturate.  If -1 (default), compute a bound for the primes
-          which may not be saturated, and use that.
+        - ``sat_bnd`` (int, default -1) -- upper bound on primes at
+          which to saturate.  If -1 (default), compute a bound for the
+          primes which may not be saturated, and use that.  Otherwise,
+          the bound used is the minumum of the value of ``sat_bnd``
+          and the computed bound.
 
-        - ``odd_primes_only`` (bool, default ``False``) -- only do
-          saturation at odd primes.  (If the points have been found
-          via 2-descent they should already be 2-saturated.)
+        - ``sat_low_bd`` (int, default 2) -- only do saturation at
+          prime not less than this.  For exampe, if the points have
+          been found via 2-descent they should already be 2-saturated,
+          and ``sat_low_bd=3`` is appropriate.
 
         OUTPUT:
 
         (tuple) (success flag, index, list) The success flag will be 1
         unless something failed (usually an indication that the points
-        were not saturated but the precision is not high enough to
-        divide out successfully).  The index is the index of the mw
-        group before saturation in the mw group after.  The list is a
-        string representation of the primes at which saturation was
-        not proved or achieved.
+        were not saturated but eclib was not able to divide out
+        successfully).  The index is the index of the mw group before
+        saturation in the mw group after.  The list is a string
+        representation of the primes at which saturation was not
+        proved or achieved.
 
+        .. NOTE::
+
+        ``eclib`` will compute a bound on the saturation index.  If
+        the computed saturation bound is very large and ``sat_bnd`` is
+        -1, ``eclib`` may output a warning, but will still attempt to
+        saturate up to the computed bound.  If a positive value of
+        ``sat_bnd`` is given which is greater than the computed bound,
+        `p`-saturation will only be carried out for primes up to the
+        compated bound.  Setting ``sat_low_bnd`` to a value greater
+        than 2 allows for saturation to be done incrementally, or for
+        exactly one prime `p` by setting both ``sat_bd`` and
+        ``sat_low_bd`` to `p`.
+
         EXAMPLES::
 
             sage: from sage.libs.eclib.mwrank import _Curvedata
@@ -872,34 +882,23 @@ cdef class _mw:
             sage: EQ
             [[-1:1:1]]
 
-        If we set the saturation bound at 2, then saturation will fail::
+        If we set the saturation bound at 2, then saturation will not
+        enlarge the basis, but the success flag is still 1 (True)
+        since we did not ask to check 3-saturation::
 
             sage: EQ = _mw(E)
             sage: EQ.process([494, -5720, 6859]) # 3 times another point
             sage: EQ.saturate(sat_bd=2)
-            Saturation index bound = 10
-            WARNING: saturation at primes p > 2 will not be done;
-            points may be unsaturated at primes between 2 and index bound
-            Failed to saturate MW basis at primes [ ]
-            (0, 1, '[ ]')
+            (1, 1, '[ ]')
             sage: EQ
             [[494:-5720:6859]]
 
-        The following output is also seen in the preceding example::
-
-            Saturation index bound = 10
-            WARNING: saturation at primes p > 2 will not be done;
-            points may be unsaturated at primes between 2 and index bound
-            Failed to saturate MW basis at primes [ ]
-
-
         """
-        cdef _bigint index
+        cdef long index
         cdef char* s
         cdef int ok
         sig_on()
-        index = _bigint()
-        ok = mw_saturate(self.x, index.x, &s, sat_bd, odd_primes_only)
+        ok = mw_saturate(self.x, &index, &s, sat_bd, sat_low_bd)
         unsat = string_sigoff(s)
         return ok, index, unsat
 
@@ -1094,7 +1093,6 @@ cdef class _two_descent:
         sig_on()
         r = two_descent_get_rank(self.x)
         sig_off()
-        from sage.rings.all import Integer
         return Integer(r)
 
     def getrankbound(self):
@@ -1128,7 +1126,6 @@ cdef class _two_descent:
         sig_on()
         r = two_descent_get_rank_bound(self.x)
         sig_off()
-        from sage.rings.all import Integer
         return Integer(r)
 
     def getselmer(self):
@@ -1161,7 +1158,6 @@ cdef class _two_descent:
         sig_on()
         r = two_descent_get_selmer_rank(self.x)
         sig_off()
-        from sage.rings.all import Integer
         return Integer(r)
 
     def ok(self):
@@ -1222,10 +1218,21 @@ cdef class _two_descent:
         """
         return two_descent_get_certain(self.x)
 
-    def saturate(self, saturation_bound=0):
+    def saturate(self, saturation_bound=0, lower=3):
         """
         Carries out saturation of the points found by a 2-descent.
 
+        INPUT:
+
+        - ``saturation_bound`` (int) -- an upper bound on the primes
+          `p` at which `p`-saturation will be carried out, or -1, in
+          which case ``eclib`` will compute an upper bound on the
+          saturation index.
+
+        - ``lower`` (int, default 3) -- do no `p`-saturation for `p`
+          less than this.  The default is 3 since the points found
+          during 2-descent will be 2-saturated.
+
         OUTPUT:
 
         None.
@@ -1257,7 +1264,7 @@ cdef class _two_descent:
             '[[1:-1:1], [-2:3:1], [-14:25:8]]'
         """
         sig_on()
-        two_descent_saturate(self.x, saturation_bound)
+        two_descent_saturate(self.x, saturation_bound, 3)
         sig_off()
 
     def getbasis(self):

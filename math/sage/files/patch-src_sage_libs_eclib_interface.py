--- src/sage/libs/eclib/interface.py.orig	2021-03-16 21:40:43 UTC
+++ src/sage/libs/eclib/interface.py
@@ -21,18 +21,17 @@ Check that ``eclib`` is imported as needed::
     sage: [k for k in sys.modules if k.startswith("sage.libs.eclib")]
     []
     sage: EllipticCurve('11a1').mwrank_curve()
-    y^2+ y = x^3 - x^2 - 10*x - 20
+    y^2 + y = x^3 - x^2 - 10 x - 20
     sage: [k for k in sys.modules if k.startswith("sage.libs.eclib")]
     ['...']
 """
-
+import sys
 from sage.structure.sage_object import SageObject
 from sage.rings.all import Integer
 from sage.rings.integer_ring import IntegerRing
 
-from .mwrank import _Curvedata, _two_descent, _mw
+from .mwrank import _Curvedata, _two_descent, _mw, parse_point_list
 
-
 class mwrank_EllipticCurve(SageObject):
     r"""
     The :class:`mwrank_EllipticCurve` class represents an elliptic
@@ -67,7 +66,7 @@ class mwrank_EllipticCurve(SageObject):
 
         sage: e = mwrank_EllipticCurve([3, -4])
         sage: e
-        y^2 = x^3 + 3*x - 4
+        y^2 = x^3 + 3 x - 4
         sage: e.ainvs()
         [0, 0, 0, 3, -4]
 
@@ -127,6 +126,7 @@ class mwrank_EllipticCurve(SageObject):
 
         # place holders
         self.__saturate = -2  # not yet saturated
+        self.__descent = None
 
     def __reduce__(self):
         r"""
@@ -137,12 +137,9 @@ class mwrank_EllipticCurve(SageObject):
             sage: E = mwrank_EllipticCurve([0,0,1,-7,6])
             sage: E.__reduce__()
             (<class 'sage.libs.eclib.interface.mwrank_EllipticCurve'>, ([0, 0, 1, -7, 6], False))
-
-
         """
         return mwrank_EllipticCurve, (self.__ainvs, self.__verbose)
 
-
     def set_verbose(self, verbose):
         """
         Set the verbosity of printing of output by the :meth:`two_descent()` and
@@ -247,53 +244,27 @@ class mwrank_EllipticCurve(SageObject):
 
             sage: E = mwrank_EllipticCurve([0,-1,1,0,0])
             sage: E.__repr__()
-            'y^2+ y = x^3 - x^2 '
+            'y^2 + y = x^3 - x^2'
         """
-        # TODO: Is the use (or omission) of spaces here intentional?
-        a = self.ainvs()
-        s = "y^2"
-        if a[0] == -1:
-            s += "- x*y "
-        elif a[0] == 1:
-            s += "+ x*y "
-        elif a[0] != 0:
-            s += "+ %s*x*y "%a[0]
-        if a[2] == -1:
-            s += " - y"
-        elif a[2] == 1:
-            s += "+ y"
-        elif a[2] != 0:
-            s += "+ %s*y"%a[2]
-        s += " = x^3 "
-        if a[1] == -1:
-            s += "- x^2 "
-        elif a[1] == 1:
-            s += "+ x^2 "
-        elif a[1] != 0:
-            s += "+ %s*x^2 "%a[1]
-        if a[3] == -1:
-            s += "- x "
-        elif a[3] == 1:
-            s += "+ x "
-        elif a[3] != 0:
-            s += "+ %s*x "%a[3]
-        if a[4] == -1:
-            s += "-1"
-        elif a[4] == 1:
-            s += "+1"
-        elif a[4] != 0:
-            s += "+ %s"%a[4]
-        s = s.replace("+ -","- ")
-        return s
+        a1, a2, a3, a4, a6 = self.__ainvs
+        # we do not assume a1, a2, a3 are reduced to {0,1}, {-1,0,1}, {0,1}
+        coeff = lambda a: ''.join([" +" if a > 0 else " -",
+                                   " " + str(abs(a)) if abs(a) > 1 else ""])
+        return ''.join(['y^2',
+                        ' '.join([coeff(a1), 'xy']) if a1 else '',
+                        ' '.join([coeff(a3), 'y']) if a3 else '',
+                        ' = x^3',
+                        ' '.join([coeff(a2), 'x^2']) if a2 else '',
+                        ' '.join([coeff(a4), 'x']) if a4 else '',
+                        ' '.join([" +" if a6 > 0 else " -", str(abs(a6))]) if a6 else ''])
 
-
     def two_descent(self,
-                    verbose = True,
-                    selmer_only = False,
-                    first_limit = 20,
-                    second_limit = 8,
-                    n_aux = -1,
-                    second_descent = True):
+                    verbose=True,
+                    selmer_only=False,
+                    first_limit=20,
+                    second_limit=8,
+                    n_aux=-1,
+                    second_descent=True):
         r"""
         Compute 2-descent data for this curve.
 
@@ -374,16 +345,14 @@ class mwrank_EllipticCurve(SageObject):
         second_limit = int(second_limit)
         n_aux = int(n_aux)
         second_descent = int(second_descent)    # convert from bool to (int) 0 or 1
-        # TODO:  Don't allow limits above some value...???
-        #   (since otherwise mwrank just sets limit tiny)
         self.__descent = _two_descent()
         self.__descent.do_descent(self.__curve,
-                                      verbose,
-                                      selmer_only,
-                                      first_limit,
-                                      second_limit,
-                                      n_aux,
-                                      second_descent)
+                                  verbose,
+                                  selmer_only,
+                                  first_limit,
+                                  second_limit,
+                                  n_aux,
+                                  second_descent)
         if not self.__descent.ok():
             raise RuntimeError("A 2-descent did not complete successfully.")
         self.__saturate = -2  # not yet saturated
@@ -398,11 +367,9 @@ class mwrank_EllipticCurve(SageObject):
             sage: E._mwrank_EllipticCurve__two_descent_data()
             <sage.libs.eclib.mwrank._two_descent object at ...>
         """
-        try:
-            return self.__descent
-        except AttributeError:
+        if self.__descent is None:
             self.two_descent(self.__verbose)
-            return self.__descent
+        return self.__descent
 
     def conductor(self):
         """
@@ -565,22 +532,24 @@ class mwrank_EllipticCurve(SageObject):
         R = self.__two_descent_data().regulator()
         return float(R)
 
-    def saturate(self, bound=-1):
+    def saturate(self, bound=-1, lower=2):
         """
-        Compute the saturation of the Mordell-Weil group at all
-        primes up to ``bound``.
+        Compute the saturation of the Mordell-Weil group.
 
         INPUT:
 
-        - ``bound`` (int, default -1) -- Use `-1` (the default) to
-          saturate at *all* primes, `0` for no saturation, or `n` (a
-          positive integer) to saturate at all primes up to `n`.
+        - ``bound`` (int, default -1) -- If `-1`, saturate at *all*
+          primes by computing a bound on the saturation index,
+          otherwise saturate at all primes up to the minimum of
+          ``bound`` and the saturation index bound.
 
+        - ``lower`` (int, default 2) -- Only saturate at primes not
+          less than this.
+
         EXAMPLES:
 
         Since the 2-descent automatically saturates at primes up to
-        20, it is not easy to come up with an example where saturation
-        has any effect::
+        20, further saturation often has no effect::
 
             sage: E = mwrank_EllipticCurve([0, 0, 0, -1002231243161, 0])
             sage: E.gens()
@@ -599,7 +568,7 @@ class mwrank_EllipticCurve(SageObject):
         """
         bound = int(bound)
         if self.__saturate < bound:
-            self.__two_descent_data().saturate(bound)
+            self.__two_descent_data().saturate(bound, lower)
             self.__saturate = bound
 
     def gens(self):
@@ -613,8 +582,7 @@ class mwrank_EllipticCurve(SageObject):
             [[0, -1, 1]]
         """
         self.saturate()
-        L = eval(self.__two_descent_data().getbasis().replace(":",","))
-        return [[Integer(x), Integer(y), Integer(z)] for (x,y,z) in L]
+        return parse_point_list(self.__two_descent_data().getbasis())
 
     def certain(self):
         r"""
@@ -760,65 +728,37 @@ class mwrank_MordellWeil(SageObject):
         sage: EQ.search(1)
         P1 = [0:1:0]     is torsion point, order 1
         P1 = [-3:0:1]     is generator number 1
-        saturating up to 20...Checking 2-saturation
-        Points have successfully been 2-saturated (max q used = 7)
-        Checking 3-saturation
-        Points have successfully been 3-saturated (max q used = 7)
-        Checking 5-saturation
-        Points have successfully been 5-saturated (max q used = 23)
-        Checking 7-saturation
-        Points have successfully been 7-saturated (max q used = 41)
-        Checking 11-saturation
-        Points have successfully been 11-saturated (max q used = 17)
-        Checking 13-saturation
-        Points have successfully been 13-saturated (max q used = 43)
-        Checking 17-saturation
-        Points have successfully been 17-saturated (max q used = 31)
-        Checking 19-saturation
-        Points have successfully been 19-saturated (max q used = 37)
+        saturating up to 20...Saturation index bound (for points of good reduction)  = 3
+        Reducing saturation bound from given value 20 to computed index bound 3
+        Checking saturation at [ 2 3 ]
+        Checking 2-saturation 
+        Points were proved 2-saturated (max q used = 7)
+        Checking 3-saturation 
+        Points were proved 3-saturated (max q used = 7)
         done
         P2 = [-2:3:1]     is generator number 2
-        saturating up to 20...Checking 2-saturation
+        saturating up to 20...Saturation index bound (for points of good reduction)  = 4
+        Reducing saturation bound from given value 20 to computed index bound 4
+        Checking saturation at [ 2 3 ]
+        Checking 2-saturation 
         possible kernel vector = [1,1]
         This point may be in 2E(Q): [14:-52:1]
-        ...and it is!
+        ...and it is! 
         Replacing old generator #1 with new generator [1:-1:1]
+        Reducing index bound from 4 to 2
         Points have successfully been 2-saturated (max q used = 7)
         Index gain = 2^1
-        Checking 3-saturation
-        Points have successfully been 3-saturated (max q used = 13)
-        Checking 5-saturation
-        Points have successfully been 5-saturated (max q used = 67)
-        Checking 7-saturation
-        Points have successfully been 7-saturated (max q used = 53)
-        Checking 11-saturation
-        Points have successfully been 11-saturated (max q used = 73)
-        Checking 13-saturation
-        Points have successfully been 13-saturated (max q used = 103)
-        Checking 17-saturation
-        Points have successfully been 17-saturated (max q used = 113)
-        Checking 19-saturation
-        Points have successfully been 19-saturated (max q used = 47)
-        done (index = 2).
+        done, index = 2.
         Gained index 2, new generators = [ [1:-1:1] [-2:3:1] ]
         P3 = [-14:25:8]   is generator number 3
-        saturating up to 20...Checking 2-saturation
-        Points have successfully been 2-saturated (max q used = 11)
-        Checking 3-saturation
-        Points have successfully been 3-saturated (max q used = 13)
-        Checking 5-saturation
-        Points have successfully been 5-saturated (max q used = 71)
-        Checking 7-saturation
-        Points have successfully been 7-saturated (max q used = 101)
-        Checking 11-saturation
-        Points have successfully been 11-saturated (max q used = 127)
-        Checking 13-saturation
-        Points have successfully been 13-saturated (max q used = 151)
-        Checking 17-saturation
-        Points have successfully been 17-saturated (max q used = 139)
-        Checking 19-saturation
-        Points have successfully been 19-saturated (max q used = 179)
-        done (index = 1).
+        saturating up to 20...Saturation index bound (for points of good reduction)  = 3
+        Reducing saturation bound from given value 20 to computed index bound 3
+        Checking saturation at [ 2 3 ]
+        Checking 2-saturation 
+        Points were proved 2-saturated (max q used = 11)
+        Checking 3-saturation 
+        Points were proved 3-saturated (max q used = 13)
+        done, index = 1.
         P4 = [-1:3:1]    = -1*P1 + -1*P2 + -1*P3 (mod torsion)
         P4 = [0:2:1]     = 2*P1 + 0*P2 + 1*P3 (mod torsion)
         P4 = [2:13:8]    = -3*P1 + 1*P2 + -1*P3 (mod torsion)
@@ -878,7 +818,7 @@ class mwrank_MordellWeil(SageObject):
             sage: E = mwrank_EllipticCurve([0,0,1,-7,6])
             sage: EQ = mwrank_MordellWeil(E)
             sage: EQ.__reduce__()
-            (<class 'sage.libs.eclib.interface.mwrank_MordellWeil'>, (y^2+ y = x^3 - 7*x + 6, True, 1, 999))
+            (<class 'sage.libs.eclib.interface.mwrank_MordellWeil'>, (y^2 + y = x^3 - 7 x + 6, True, 1, 999))
         """
         return mwrank_MordellWeil, (self.__curve, self.__verbose, self.__pp, self.__maxr)
 
@@ -902,21 +842,20 @@ class mwrank_MordellWeil(SageObject):
         """
         return "Subgroup of Mordell-Weil group: %s"%self.__mw
 
-    def process(self, v, sat=0):
-        """
+    def process(self, v, saturation_bound=0):
+        """Process points in the list ``v``.
+
         This function allows one to add points to a :class:`mwrank_MordellWeil` object.
 
-        Process points in the list ``v``, with saturation at primes up to
-        ``sat``.  If ``sat`` is zero (the default), do no saturation.
-
         INPUT:
 
         - ``v`` (list of 3-tuples or lists of ints or Integers) -- a
           list of triples of integers, which define points on the
           curve.
 
-        - ``sat`` (int, default 0) -- saturate at primes up to ``sat``, or at
-          *all* primes if ``sat`` is zero.
+        - ``saturation_bound`` (int, default 0) -- saturate at primes up to
+          ``saturation_bound``, or at *all* primes if ``saturation_bound`` is -1; when ``saturation_bound``
+          is 0 (the default), do no saturation..
 
         OUTPUT:
 
@@ -939,11 +878,11 @@ class mwrank_MordellWeil(SageObject):
             sage: EQ.points()
             [[1, -1, 1], [-2, 3, 1], [-14, 25, 8]]
 
-        Example to illustrate the saturation parameter ``sat``::
+        Example to illustrate the saturation parameter ``saturation_bound``::
 
             sage: E = mwrank_EllipticCurve([0,0,1,-7,6])
             sage: EQ = mwrank_MordellWeil(E)
-            sage: EQ.process([[1547, -2967, 343], [2707496766203306, 864581029138191, 2969715140223272], [-13422227300, -49322830557, 12167000000]], sat=20)
+            sage: EQ.process([[1547, -2967, 343], [2707496766203306, 864581029138191, 2969715140223272], [-13422227300, -49322830557, 12167000000]], saturation_bound=20)
             P1 = [1547:-2967:343]         is generator number 1
             ...
             Gained index 5, new generators = [ [-2:3:1] [-14:25:8] [1:-1:1] ]
@@ -956,7 +895,7 @@ class mwrank_MordellWeil(SageObject):
 
             sage: E = mwrank_EllipticCurve([0,0,1,-7,6])
             sage: EQ = mwrank_MordellWeil(E)
-            sage: EQ.process([[1547, -2967, 343], [2707496766203306, 864581029138191, 2969715140223272], [-13422227300, -49322830557, 12167000000]], sat=0)
+            sage: EQ.process([[1547, -2967, 343], [2707496766203306, 864581029138191, 2969715140223272], [-13422227300, -49322830557, 12167000000]], saturation_bound=0)
             P1 = [1547:-2967:343]         is generator number 1
             P2 = [2707496766203306:864581029138191:2969715140223272]      is generator number 2
             P3 = [-13422227300:-49322830557:12167000000]          is generator number 3
@@ -965,55 +904,92 @@ class mwrank_MordellWeil(SageObject):
             sage: EQ.regulator()
             375.42920288254555
             sage: EQ.saturate(2)  # points were not 2-saturated
-            saturating basis...Saturation index bound = 93
-            WARNING: saturation at primes p > 2 will not be done;
-            ...
+            saturating basis...Saturation index bound (for points of good reduction)  = 93
+            Only p-saturating for p up to given value 2.
+            The resulting points may not be p-saturated for p between this and the computed index bound 93
+            Checking saturation at [ 2 ]
+            Checking 2-saturation 
+            possible kernel vector = [1,0,0]
+            This point may be in 2E(Q): [1547:-2967:343]
+            ...and it is! 
+            Replacing old generator #1 with new generator [-2:3:1]
+            Reducing index bound from 93 to 46
+            Points have successfully been 2-saturated (max q used = 11)
+            Index gain = 2^1
+            done
             Gained index 2
-            New regulator =  93.857...
-            (False, 2, '[ ]')
+            New regulator =  93.85730072
+            (True, 2, '[ ]')
             sage: EQ.points()
             [[-2, 3, 1], [2707496766203306, 864581029138191, 2969715140223272], [-13422227300, -49322830557, 12167000000]]
             sage: EQ.regulator()
             93.85730072063639
             sage: EQ.saturate(3)  # points were not 3-saturated
-            saturating basis...Saturation index bound = 46
-            WARNING: saturation at primes p > 3 will not be done;
-            ...
+            saturating basis...Saturation index bound (for points of good reduction)  = 46
+            Only p-saturating for p up to given value 3.
+            The resulting points may not be p-saturated for p between this and the computed index bound 46
+            Checking saturation at [ 2 3 ]
+            Checking 2-saturation 
+            Points were proved 2-saturated (max q used = 11)
+            Checking 3-saturation 
+            possible kernel vector = [0,1,0]
+            This point may be in 3E(Q): [2707496766203306:864581029138191:2969715140223272]
+            ...and it is! 
+            Replacing old generator #2 with new generator [-14:25:8]
+            Reducing index bound from 46 to 15
+            Points have successfully been 3-saturated (max q used = 13)
+            Index gain = 3^1
+            done
             Gained index 3
-            New regulator =  10.428...
-            (False, 3, '[ ]')
+            New regulator =  10.42858897
+            (True, 3, '[ ]')
             sage: EQ.points()
             [[-2, 3, 1], [-14, 25, 8], [-13422227300, -49322830557, 12167000000]]
             sage: EQ.regulator()
             10.4285889689596
             sage: EQ.saturate(5)  # points were not 5-saturated
-            saturating basis...Saturation index bound = 15
-            WARNING: saturation at primes p > 5 will not be done;
-            ...
+            saturating basis...Saturation index bound (for points of good reduction)  = 15
+            Only p-saturating for p up to given value 5.
+            The resulting points may not be p-saturated for p between this and the computed index bound 15
+            Checking saturation at [ 2 3 5 ]
+            Checking 2-saturation 
+            Points were proved 2-saturated (max q used = 11)
+            Checking 3-saturation 
+            Points were proved 3-saturated (max q used = 13)
+            Checking 5-saturation 
+            possible kernel vector = [0,0,1]
+            This point may be in 5E(Q): [-13422227300:-49322830557:12167000000]
+            ...and it is! 
+            Replacing old generator #3 with new generator [1:-1:1]
+            Reducing index bound from 15 to 3
+            Points have successfully been 5-saturated (max q used = 71)
+            Index gain = 5^1
+            done
             Gained index 5
-            New regulator =  0.417...
-            (False, 5, '[ ]')
+            New regulator =  0.4171435588
+            (True, 5, '[ ]')
             sage: EQ.points()
             [[-2, 3, 1], [-14, 25, 8], [1, -1, 1]]
             sage: EQ.regulator()
             0.417143558758384
             sage: EQ.saturate()   # points are now saturated
-            saturating basis...Saturation index bound = 3
+            saturating basis...Saturation index bound (for points of good reduction)  = 3
+            Tamagawa index primes are [ ]
             Checking saturation at [ 2 3 ]
-            Checking 2-saturation
+            Checking 2-saturation 
             Points were proved 2-saturated (max q used = 11)
-            Checking 3-saturation
+            Checking 3-saturation 
             Points were proved 3-saturated (max q used = 13)
             done
             (True, 1, '[ ]')
         """
         if not isinstance(v, list):
             raise TypeError("v (=%s) must be a list"%v)
-        sat = int(sat)
+        saturation_bound = int(saturation_bound)
         for P in v:
-            if not isinstance(P, (list,tuple)) or len(P) != 3:
+            if not isinstance(P, (list, tuple)) or len(P) != 3:
                 raise TypeError("v (=%s) must be a list of 3-tuples (or 3-element lists) of ints"%v)
-            self.__mw.process(P, sat)
+            self.__mw.process(P, saturation_bound)
 
     def regulator(self):
         """
@@ -1091,23 +1067,21 @@ class mwrank_MordellWeil(SageObject):
         """
         return self.__mw.rank()
 
-    def saturate(self, max_prime=-1, odd_primes_only=False):
-        r"""
-        Saturate this subgroup of the Mordell-Weil group.
+    def saturate(self, max_prime=-1, min_prime=2):
+        r"""Saturate this subgroup of the Mordell-Weil group.
 
         INPUT:
 
-        - ``max_prime`` (int, default -1) -- saturation is performed for
-          all primes up to ``max_prime``. If `-1` (the default), an
+        - ``max_prime`` (int, default -1) -- If `-1` (the default), an
           upper bound is computed for the primes at which the subgroup
-          may not be saturated, and this is used; however, if the
-          computed bound is greater than a value set by the ``eclib``
-          library (currently 97) then no saturation will be attempted
-          at primes above this.
+          may not be saturated, and saturation is performed for all
+          primes up to this bound.  Otherwise, the bound used is the
+          minimum of ``max_prime`` and the computed bound.
 
-        - ``odd_primes_only`` (bool, default ``False``) -- only do
-          saturation at odd primes.  (If the points have been found
-          via :meth:`two_descent` they should already be 2-saturated.)
+        - ``min_prime`` (int, default 2) -- only do saturation at
+          primes no less than this.  (For example, if the points have
+          been found via :meth:`two_descent` they should already be
+          2-saturated so a value of 3 is appropriate.)
 
         OUTPUT:
 
@@ -1115,40 +1089,35 @@ class mwrank_MordellWeil(SageObject):
 
         - ``ok`` (bool) -- ``True`` if and only if the saturation was
           provably successful at all primes attempted.  If the default
-          was used for ``max_prime`` and no warning was output about
-          the computed saturation bound being too high, then ``True``
-          indicates that the subgroup is saturated at *all*
-          primes.
+          was used for ``max_prime``, then ``True`` indicates that the
+          subgroup is saturated at *all* primes.
 
         - ``index`` (int) -- the index of the group generated by the
           original points in their saturation.
 
         - ``unsatlist`` (list of ints) -- list of primes at which
-          saturation could not be proved or achieved.  Increasing the
-          precision should correct this, since it happens when
-          a linear combination of the points appears to be a multiple
-          of `p` but cannot be divided by `p`.  (Note that ``eclib``
-          uses floating point methods based on elliptic logarithms to
-          divide points.)
+          saturation could not be proved or achieved.
 
         .. note::
 
-           We emphasize that if this function returns ``True`` as the
-           first return argument (``ok``), and if the default was used for the
-           parameter ``max_prime``, then the points in the basis after
-           calling this function are saturated at *all* primes,
-           i.e., saturating at the primes up to ``max_prime`` are
-           sufficient to saturate at all primes.  Note that the
-           function might not have needed to saturate at all primes up
-           to ``max_prime``.  It has worked out what prime you need to
-           saturate up to, and that prime might be smaller than ``max_prime``.
+          In versions up to v20190909, ``eclib`` used floating point
+          methods based on elliptic logarithms to divide points, and
+          did not compute the precision necessary, which could casue
+          failures. Since v20210310, ``eclib`` uses exact method based
+          on division polynomials, which should mean that such
+          failures does not happen.
 
         .. note::
 
-           Currently (May 2010), this does not remember the result of
-           calling :meth:`search()`.  So calling :meth:`search()` up
-           to height 20 then calling :meth:`saturate()` results in
-           another search up to height 18.
+           We emphasize that if this function returns ``True`` as the
+           first return argument (``ok``), and if the default was used
+           for the parameter ``max_prime``, then the points in the
+           basis after calling this function are saturated at *all*
+           primes, i.e., saturating at the primes up to ``max_prime``
+           are sufficient to saturate at all primes.  Note that the
+           function computes an upper bound for the index of
+           saturation, and does no work for primes greater than this
+           even if ``max_prime`` is larger.
 
         EXAMPLES::
 
@@ -1160,7 +1129,7 @@ class mwrank_MordellWeil(SageObject):
         automatic saturation at this stage we set the parameter
         ``sat`` to 0 (which is in fact the default)::
 
-            sage: EQ.process([[1547, -2967, 343], [2707496766203306, 864581029138191, 2969715140223272], [-13422227300, -49322830557, 12167000000]], sat=0)
+            sage: EQ.process([[1547, -2967, 343], [2707496766203306, 864581029138191, 2969715140223272], [-13422227300, -49322830557, 12167000000]], saturation_bound=0)
             P1 = [1547:-2967:343]         is generator number 1
             P2 = [2707496766203306:864581029138191:2969715140223272]      is generator number 2
             P3 = [-13422227300:-49322830557:12167000000]          is generator number 3
@@ -1172,12 +1141,12 @@ class mwrank_MordellWeil(SageObject):
         Now we saturate at `p=2`, and gain index 2::
 
             sage: EQ.saturate(2)  # points were not 2-saturated
-            saturating basis...Saturation index bound = 93
-            WARNING: saturation at primes p > 2 will not be done;
+            saturating basis...Saturation index bound (for points of good reduction) = 93
+            Only p-saturating for p up to given value 2.
             ...
             Gained index 2
             New regulator =  93.857...
-            (False, 2, '[ ]')
+            (True, 2, '[ ]')
             sage: EQ
             Subgroup of Mordell-Weil group: [[-2:3:1], [2707496766203306:864581029138191:2969715140223272], [-13422227300:-49322830557:12167000000]]
             sage: EQ.regulator()
@@ -1186,12 +1155,12 @@ class mwrank_MordellWeil(SageObject):
         Now we saturate at `p=3`, and gain index 3::
 
             sage: EQ.saturate(3)  # points were not 3-saturated
-            saturating basis...Saturation index bound = 46
-            WARNING: saturation at primes p > 3 will not be done;
+            saturating basis...Saturation index bound (for points of good reduction) = 46
+            Only p-saturating for p up to given value 3.
             ...
             Gained index 3
             New regulator =  10.428...
-            (False, 3, '[ ]')
+            (True, 3, '[ ]')
             sage: EQ
             Subgroup of Mordell-Weil group: [[-2:3:1], [-14:25:8], [-13422227300:-49322830557:12167000000]]
             sage: EQ.regulator()
@@ -1200,12 +1169,12 @@ class mwrank_MordellWeil(SageObject):
         Now we saturate at `p=5`, and gain index 5::
 
             sage: EQ.saturate(5)  # points were not 5-saturated
-            saturating basis...Saturation index bound = 15
-            WARNING: saturation at primes p > 5 will not be done;
+            saturating basis...Saturation index bound (for points of good reduction) = 15
+            Only p-saturating for p up to given value 5.
             ...
             Gained index 5
             New regulator =  0.417...
-            (False, 5, '[ ]')
+            (True, 5, '[ ]')
             sage: EQ
             Subgroup of Mordell-Weil group: [[-2:3:1], [-14:25:8], [1:-1:1]]
             sage: EQ.regulator()
@@ -1215,7 +1184,8 @@ class mwrank_MordellWeil(SageObject):
         the points are now provably saturated at all primes::
 
             sage: EQ.saturate()   # points are now saturated
-            saturating basis...Saturation index bound = 3
+            saturating basis...Saturation index bound (for points of good reduction) = 3
+            Tamagawa index primes are [ ]
             Checking saturation at [ 2 3 ]
             Checking 2-saturation
             Points were proved 2-saturated (max q used = 11)
@@ -1229,7 +1199,7 @@ class mwrank_MordellWeil(SageObject):
 
             sage: E = mwrank_EllipticCurve([0,0,1,-7,6])
             sage: EQ = mwrank_MordellWeil(E)
-            sage: EQ.process([[1547, -2967, 343], [2707496766203306, 864581029138191, 2969715140223272], [-13422227300, -49322830557, 12167000000]], sat=5)
+            sage: EQ.process([[1547, -2967, 343], [2707496766203306, 864581029138191, 2969715140223272], [-13422227300, -49322830557, 12167000000]], saturation_bound=5)
             P1 = [1547:-2967:343]         is generator number 1
             ...
             Gained index 5, new generators = [ [-2:3:1] [-14:25:8] [1:-1:1] ]
@@ -1242,7 +1212,8 @@ class mwrank_MordellWeil(SageObject):
         verify that full saturation has been done::
 
             sage: EQ.saturate()
-            saturating basis...Saturation index bound = 3
+            saturating basis...Saturation index bound (for points of good reduction) = 3
+            Tamagawa index primes are [ ]
             Checking saturation at [ 2 3 ]
             Checking 2-saturation
             Points were proved 2-saturated (max q used = 11)
@@ -1255,8 +1226,9 @@ class mwrank_MordellWeil(SageObject):
         index of the points in their saturation is at most 3, then
         proves saturation at 2 and at 3, by reducing the points modulo
         all primes of good reduction up to 11, respectively 13.
+
         """
-        ok, index, unsat = self.__mw.saturate(int(max_prime), odd_primes_only)
+        ok, index, unsat = self.__mw.saturate(int(max_prime), int(min_prime))
         return bool(ok), int(str(index)), unsat
 
     def search(self, height_limit=18, verbose=False):
@@ -1271,9 +1243,9 @@ class mwrank_MordellWeil(SageObject):
 
         .. note::
 
-          On 32-bit machines, this *must* be < 21.48 else
+          On 32-bit machines, this *must* be < 21.48 (`31\log(2)`) else
           `\exp(h_{\text{lim}}) > 2^{31}` and overflows.  On 64-bit machines, it
-          must be *at most* 43.668.  However, this bound is a logarithmic
+          must be *at most* 43.668  (`63\log(2)`) .  However, this bound is a logarithmic
           bound and increasing it by just 1 increases the running time
           by (roughly) `\exp(1.5)=4.5`, so searching up to even 20
           takes a very long time.
@@ -1320,8 +1292,10 @@ class mwrank_MordellWeil(SageObject):
             Subgroup of Mordell-Weil group: [[4413270:10381877:27000]]
         """
         height_limit = float(height_limit)
-        if height_limit >= 21.4:        # TODO: docstring says 21.48 (for 32-bit machines; what about 64-bit...?)
-            raise ValueError("The height limit must be < 21.4.")
+        int_bits = sys.maxsize.bit_length()
+        max_height_limit = int_bits * 0.693147 # log(2.0) = 0.693147 approx
+        if height_limit >= max_height_limit:
+            raise ValueError("The height limit must be < {} = {}log(2) on a {}-bit machine.".format(max_height_limit, int_bits, int_bits+1))
 
         moduli_option = 0  # Use Stoll's sieving program... see strategies in ratpoints-1.4.c
 
@@ -1352,5 +1326,4 @@ class mwrank_MordellWeil(SageObject):
             [[1, -1, 1], [-2, 3, 1], [-14, 25, 8]]
 
         """
-        L = eval(self.__mw.getbasis().replace(":",","))
-        return [[Integer(x), Integer(y), Integer(z)] for (x,y,z) in L]
+        return self.__mw.getbasis()

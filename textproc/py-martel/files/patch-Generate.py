From: "Andrew Dalke" <dalke@acm.org>
To: <biopython-dev@biopython.org>
Date: Wed, 6 Dec 2000 01:12:29 -0700

There's a bug in Martel-0.4 and earlier versions.

Suppose you have  ([<>][ABC])+[<>]?
and want to match it against

   <A<B<

The "<A" matches the first [<>][ABC].  The "<B" matches
the second [<>][ABC].  The parser tries to match the final
"<" against [<>][ABC] and should fail then try to match
the "<" against [<>]? .

The bug was that it would match the "<" against the [<>] in
[<>][ABC] and fail at that point.  It gives an assertion error
about "l" being greater than "r".

Here's the patch.  The only consequence should be a small hit
in performance.

                    Andrew

[ Note from port maintainer:
  This patch was somehow not incorporated into Martel 0.5 ]


--- Generate.py.orig	Wed Nov 22 09:26:48 2000
+++ Generate.py	Thu Dec  7 12:27:09 2000
@@ -268,11 +268,11 @@
 
     # Must repeat at least "i" times.
     for i in range(min_count):
-        result.append( (None, TT.SubTable, tuple(tagtable)) )
+        result.append( (">ignore", TT.Table, tuple(tagtable)) )
 
     # Special case for when the max count means "unbounded"
     if max_count == sre_parse.MAXREPEAT:
-        result.append( (None, TT.SubTable, tuple(tagtable),
+        result.append( (">ignore", TT.Table, tuple(tagtable),
                                   +1, 0))
     elif min_count == max_count:
         # Special case when i == j

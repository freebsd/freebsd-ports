--- radicale/item/filter.py.orig	2022-07-14 20:36:41 UTC
+++ radicale/item/filter.py
@@ -225,6 +225,7 @@ def visit_time_ranges(vobject_item: vobject.base.Compo
     def get_children(components: Iterable[vobject.base.Component]) -> Iterator[
                          Tuple[vobject.base.Component, bool, List[date]]]:
         main = None
+        rec_main = None
         recurrences = []
         for comp in components:
             if hasattr(comp, "recurrence_id") and comp.recurrence_id.value:
@@ -232,11 +233,14 @@ def visit_time_ranges(vobject_item: vobject.base.Compo
                 if comp.rruleset:
                     # Prevent possible infinite loop
                     raise ValueError("Overwritten recurrence with RRULESET")
+                rec_main = comp
                 yield comp, True, []
             else:
                 if main is not None:
                     raise ValueError("Multiple main components")
                 main = comp
+        if main is None and len(recurrences) == 1:
+            main = rec_main
         if main is None:
             raise ValueError("Main component missing")
         yield main, False, recurrences

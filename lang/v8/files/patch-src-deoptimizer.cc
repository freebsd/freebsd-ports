--- src/deoptimizer.cc.orig	2013-05-01 12:56:29 UTC
+++ src/deoptimizer.cc
@@ -1392,7 +1392,7 @@ void Deoptimizer::MaterializeHeapObjects
       PrintF("Materializing a new heap number %p [%e] in slot %p\n",
              reinterpret_cast<void*>(*num),
              d.value(),
-             d.slot_address());
+             reinterpret_cast<void*>(d.slot_address()));
     }
     Memory::Object_at(d.slot_address()) = *num;
   }
@@ -1474,7 +1474,7 @@ void Deoptimizer::MaterializeHeapNumbers
                "for parameter slot #%d\n",
                reinterpret_cast<void*>(*num),
                d.value(),
-               d.slot_address(),
+               reinterpret_cast<void*>(d.slot_address()),
                index);
       }
 
@@ -1490,7 +1490,7 @@ void Deoptimizer::MaterializeHeapNumbers
                "for expression slot #%d\n",
                reinterpret_cast<void*>(*num),
                d.value(),
-               d.slot_address(),
+               reinterpret_cast<void*>(d.slot_address()),
                index);
       }
 

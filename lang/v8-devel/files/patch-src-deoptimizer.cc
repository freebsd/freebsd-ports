--- src/deoptimizer.cc.orig	2014-06-03 08:52:11 UTC
+++ src/deoptimizer.cc
@@ -1920,7 +1920,7 @@ void Deoptimizer::MaterializeHeapObjects
              "Materialized a new heap number %p [%e] in slot %p\n",
              reinterpret_cast<void*>(*num),
              d.value(),
-             d.destination());
+             reinterpret_cast<void*>(d.destination()));
     }
     Memory::Object_at(d.destination()) = *num;
   }
@@ -2017,7 +2017,7 @@ void Deoptimizer::MaterializeHeapNumbers
                "for parameter slot #%d\n",
                reinterpret_cast<void*>(*num),
                d.value(),
-               d.destination(),
+               reinterpret_cast<void*>(d.destination()),
                index);
       }
 
@@ -2034,7 +2034,7 @@ void Deoptimizer::MaterializeHeapNumbers
                "for expression slot #%d\n",
                reinterpret_cast<void*>(*num),
                d.value(),
-               d.destination(),
+               reinterpret_cast<void*>(d.destination()),
                index);
       }
 

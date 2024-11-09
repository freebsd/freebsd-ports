Fix build with LLVM 19

/wrkdirs/usr/ports/science/py-hoomd-blue/work/hoomd-blue-4.9.0/hoomd/extern/nano-signal-slot/nano_signal_slot.hpp:46:45:
error: a template argument list is expected after a name prefixed by the template keyword [-Wmissing-template-arg-list-after-template-kw]
   46 |         Observer::insert(Delegate::template bind (instance), this);
      |                                             ^
/wrkdirs/usr/ports/science/py-hoomd-blue/work/hoomd-blue-4.9.0/hoomd/extern/nano-signal-slot/nano_signal_slot.hpp:87:45:
error: a template argument list is expected after a name prefixed by the template keyword [-Wmissing-template-arg-list-after-template-kw]
   87 |         Observer::remove(Delegate::template bind (instance), this);

--- hoomd/extern/nano-signal-slot/nano_signal_slot.hpp.orig	2016-07-13 20:06:52 UTC
+++ hoomd/extern/nano-signal-slot/nano_signal_slot.hpp
@@ -43,7 +43,7 @@ class Signal<RT(Args...)> : private Observer
     template <typename L>
     void connect(L* instance)
     {
-        Observer::insert(Delegate::template bind (instance), this);
+        Observer::insert(Delegate::bind (instance), this);
     }
     template <typename L>
     void connect(L& instance)
@@ -84,7 +84,7 @@ class Signal<RT(Args...)> : private Observer
     template <typename L>
     void disconnect(L* instance)
     {
-        Observer::remove(Delegate::template bind (instance), this);
+        Observer::remove(Delegate::bind (instance), this);
     }
     template <typename L>
     void disconnect(L& instance)

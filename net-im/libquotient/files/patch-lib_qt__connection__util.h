The call std::bind_front() below only works from LLVM 14 on because libc++
needs https://reviews.llvm.org/D107199 to work correctly, otherwise uses of
connectSingleShot() fail. See net-im/neochat for example [1]:

In file included from /wrkdirs/usr/ports/net-im/neochat/work/neochat-23.04.2/src/controller.cpp:5:
In file included from /wrkdirs/usr/ports/net-im/neochat/work/neochat-23.04.2/src/controller.h:6:
In file included from /usr/local/include/qt5/QtCore/QObject:1:
In file included from /usr/local/include/qt5/QtCore/qobject.h:46:
In file included from /usr/local/include/qt5/QtCore/qobjectdefs.h:48:
In file included from /usr/local/include/qt5/QtCore/qnamespace.h:43:
In file included from /usr/local/include/qt5/QtCore/qglobal.h:142:
In file included from /usr/include/c++/v1/algorithm:653:
In file included from /usr/include/c++/v1/functional:495:
In file included from /usr/include/c++/v1/__functional/bind_front.h:14:
/usr/include/c++/v1/__functional/perfect_forward.h:77:9: error: no matching constructor for initialization of 'tuple<void (Controller::*)(), Controller *>'
        __bound_(_VSTD::forward<_BoundArgs>(__bound)...) { }
        ^        ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
/usr/local/include/Quotient/qt_connection_util.h:22:14: note: in instantiation of function template specialization 'std::__perfect_forward_impl<std::__bind_front_op, std::__tuple_types<void (Controller::*)(), Controller *>, std::__tuple_indices<0, 1>>::__perfect_forward_impl<std::__perfect_forward_impl<std::__bind_front_op, std::__tuple_types<void (Controller::*)(), Controller *>, std::__tuple_indices<0, 1>> &>' requested here
            [slotLike, pConn = std::move(pConn)](const auto&... args)
             ^
/usr/local/include/Quotient/qt_connection_util.h:93:23: note: in instantiation of function template specialization 'Quotient::_impl::connect<Quotient::_impl::SingleShot, Quotient::Connection, void (Quotient::Connection::*)(), Controller, std::__perfect_forward_impl<std::__bind_front_op, std::__tuple_types<void (Controller::*)(), Controller *>, std::__tuple_indices<0, 1>>>' requested here
        return _impl::connect<_impl::SingleShot>(
                      ^
/wrkdirs/usr/ports/net-im/neochat/work/neochat-23.04.2/src/controller.cpp:372:25: note: in instantiation of function template specialization 'Quotient::connectSingleShot<Controller, void (Controller::*)(), Quotient::Connection, void (Quotient::Connection::*)()>' requested here
                        connectSingleShot(connection, &Connection::syncDone, this, &Controller::initiated);
                        ^

[1] https://pkg-status.freebsd.org/beefy2/data/124amd64-quarterly/8898bf465b47/logs/neochat-23.04.2.log

--- lib/qt_connection_util.h
+++ lib/qt_connection_util.h
@@ -3,6 +3,8 @@
 
 #pragma once
 
+#include <sys/param.h>  // For __FreeBSD_version
+
 #include "function_traits.h"
 
 #include <QtCore/QPointer>
@@ -81,7 +83,10 @@ inline auto connectSingleShot(auto* sender, auto signal, ContextT* context,
     // object has to be pre-bound to the slot to make it self-contained
     if constexpr (_impl::PmfSlot<SlotT, ContextT>) {
         auto&& boundSlot =
-#    if __cpp_lib_bind_front // Needs Apple Clang 13 (other platforms are fine)
+#    if __cpp_lib_bind_front && \
+	  (!defined(__FreeBSD_version) || __FreeBSD_version >= 1301504)
+            // This requires LLVM >= 14, this only works with libc++ commit
+            // https://reviews.llvm.org/D107199.
             std::bind_front(slot, context);
 #    else
             [context, slot](const auto&... args)

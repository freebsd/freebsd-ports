In file included from ../lib/engine/videoinput/videoinput-core.cpp:44:
In file included from ../lib/engine/videoinput/videoinput-core.h:40:
In file included from ../lib/engine/framework/services.h:48:
In file included from /usr/local/include/boost/signals.hpp:9:
In file included from /usr/local/include/boost/signal.hpp:27:
In file included from /usr/local/include/boost/signals/signal0.hpp:24:
In file included from /usr/local/include/boost/signals/signal_template.hpp:37:
In file included from /usr/local/include/boost/function/function0.hpp:11:
In file included from /usr/local/include/boost/function/detail/maybe_include.hpp:13:
/usr/local/include/boost/function/function_template.hpp:159:33: error: called object type 'nullptr_t' is not a function or function pointer
          BOOST_FUNCTION_RETURN((*f)(BOOST_FUNCTION_ARGS));
                                ^~~~
/usr/local/include/boost/function/function_template.hpp:81:36: note: expanded from macro 'BOOST_FUNCTION_RETURN'
#  define BOOST_FUNCTION_RETURN(X) X
                                   ^
/usr/local/include/boost/function/function_template.hpp:925:53: note: in instantiation of member function 'boost::detail::function::void_function_obj_invoker0<nullptr_t, void>::invoke' requested here
        { { &manager_type::manage }, &invoker_type::invoke };
                                                    ^
/usr/local/include/boost/function/function_template.hpp:716:13: note: in instantiation of function template specialization 'boost::function0<void>::assign_to<nullptr_t>' requested here
      this->assign_to(f);
            ^
../lib/engine/notification/notification-core.h:59:61: note: in instantiation of function template specialization 'boost::function0<void>::function0<nullptr_t>' requested here
                  boost::function0<void> action_callback_ = NULL)
                                                            ^
/usr/include/sys/_null.h:37:14: note: expanded from macro 'NULL'
#define NULL    nullptr
                ^

--- lib/engine/notification/notification-core.h.orig	2012-11-07 20:43:51 UTC
+++ lib/engine/notification/notification-core.h
@@ -56,7 +56,7 @@ namespace Ekiga
 		  const std::string title_,
 		  const std::string body_,
                   const std::string action_name_ = "",
-                  boost::function0<void> action_callback_ = NULL)
+                  boost::function0<void> action_callback_ = 0)
       : level(level_), title(title_), body(body_), action_name(action_name_), action_callback(action_callback_)
     {}
 

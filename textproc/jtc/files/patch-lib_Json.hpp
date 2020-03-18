--- lib/Json.hpp.orig	2020-03-13 20:36:36 UTC
+++ lib/Json.hpp
@@ -1189,8 +1189,6 @@ class Jnode::Iterator: public std::iterator<std::bidir
 
         SuperJnode &        operator()(const std::string &s, Jnode &jn)
                              { lbp_ = &s; jnp_ = &jn; return *this; }
-        const SuperJnode &  operator()(const std::string &s, const Jnode &jn) const
-                             { lbp_ = &s; jnp_ = &jn; return *this; }
 
         const std::string * lbp_{nullptr};                      // pointer to a label string
         Jnode *             jnp_{nullptr};                      // resolved Jnode pointer

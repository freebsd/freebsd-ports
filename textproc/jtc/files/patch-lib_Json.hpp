--- lib/Json.hpp.orig	2020-05-07 19:34:09 UTC
+++ lib/Json.hpp
@@ -688,11 +688,11 @@ class Jnode {
                         Jnode(const Jnode &jn): Jnode() {       // CC
 
                          #ifdef BG_CC                           // -DBG_CC to compile this debug
-                          if(DBG()(__Dbg_flow__::ind)) {        // dodge DBG's mutex dead-lock
+                          if(DBG()(__Dbg_flow__::ind())) {        // dodge DBG's mutex dead-lock
                            GUARD(DBG().alt_prefix, DBG().alt_prefix)
                            DBG().alt_prefix(">");
                            DOUT() << DBG().prompt(__func__,
-                                                  __Dbg_flow__::ind + 1, DBG().stamped(),
+                                                  __Dbg_flow__::ind() + 1, DBG().stamped(),
                                                   Debug::Indention::Alternative)
                                   << "CC copying: "
                                   << jn.to_string(Jnode::PrettyType::Raw, 0) << std::endl;
@@ -1221,8 +1221,6 @@ class Jnode::Iterator: public std::iterator<std::bidir
                             SuperJnode(Jtype t): Jnode{t} {}    // Init Construct
 
         SuperJnode &        operator()(const std::string &s, Jnode &jn)
-                             { lbp_ = &s; jnp_ = &jn; return *this; }
-        const SuperJnode &  operator()(const std::string &s, const Jnode &jn) const
                              { lbp_ = &s; jnp_ = &jn; return *this; }
 
         const std::string * lbp_{nullptr};                      // pointer to a label string

--- lib/core/include/ContainerChain.h.orig	2024-09-24 09:32:47 UTC
+++ lib/core/include/ContainerChain.h
@@ -1128,15 +1128,15 @@ class modified_container_tuple_impl (public)
 
    Int size() const
    {
-      return this->manip_top().template get_container(size_constant<base_t::normal_it_pos>()).size();
+      return this->manip_top().get_container(size_constant<base_t::normal_it_pos>()).size();
    }
    Int dim() const
    {
-      return get_dim(this->manip_top().template get_container(size_constant<base_t::normal_it_pos>()));
+      return get_dim(this->manip_top().get_container(size_constant<base_t::normal_it_pos>()));
    }
    bool empty() const
    {
-      return this->manip_top().template get_container(size_constant<base_t::normal_it_pos>()).empty();
+      return this->manip_top().get_container(size_constant<base_t::normal_it_pos>()).empty();
    }
 
    decltype(auto) front()
@@ -1153,40 +1153,40 @@ class modified_container_tuple_impl (public)
    iterator make_begin(std::index_sequence<Index...>, mlist<Features...>)
    {
       return iterator(this->manip_top().get_operation(),
-                      ensure(this->manip_top().template get_container(size_constant<Index>()), muntag_t<Features>()).begin()...);
+                      ensure(this->manip_top().get_container(size_constant<Index>()), muntag_t<Features>()).begin()...);
    }
 
    template <size_t... Index, typename... Features>
    iterator make_end(std::index_sequence<Index...>, mlist<Features...>)
    {
       return iterator(this->manip_top().get_operation(),
-                      ensure(this->manip_top().template get_container(size_constant<Index>()), muntag_t<Features>()).end()...);
+                      ensure(this->manip_top().get_container(size_constant<Index>()), muntag_t<Features>()).end()...);
    }
 
    template <size_t... Index, typename... Features>
    const_iterator make_begin(std::index_sequence<Index...>, mlist<Features...>) const
    {
       return const_iterator(this->manip_top().get_operation(),
-                            ensure(this->manip_top().template get_container(size_constant<Index>()), muntag_t<Features>()).begin()...);
+                            ensure(this->manip_top().get_container(size_constant<Index>()), muntag_t<Features>()).begin()...);
    }
 
    template <size_t... Index, typename... Features>
    const_iterator make_end(std::index_sequence<Index...>, mlist<Features...>) const
    {
       return const_iterator(this->manip_top().get_operation(),
-                            ensure(this->manip_top().template get_container(size_constant<Index>()), muntag_t<Features>()).end()...);
+                            ensure(this->manip_top().get_container(size_constant<Index>()), muntag_t<Features>()).end()...);
    }
 
    template <size_t... Index>
    decltype(auto) make_front(std::index_sequence<Index...>)
    {
-      return this->manip_top().get_operation()( this->manip_top().template get_container(size_constant<Index>()).front()... );
+      return this->manip_top().get_operation()( this->manip_top().get_container(size_constant<Index>()).front()... );
    }
 
    template <size_t... Index>
    decltype(auto) make_front(std::index_sequence<Index...>) const
    {
-      return this->manip_top().get_operation()( this->manip_top().template get_container(size_constant<Index>()).front()... );
+      return this->manip_top().get_operation()( this->manip_top().get_container(size_constant<Index>()).front()... );
    }
 };
 
@@ -1230,40 +1230,40 @@ class modified_container_tuple_impl<Top, Params, std::
    reverse_iterator make_rbegin(std::index_sequence<Index...>, mlist<Features...>)
    {
       return reverse_iterator(this->manip_top().get_operation(),
-                              ensure(this->manip_top().template get_container(size_constant<Index>()), muntag_t<Features>()).rbegin()...);
+                              ensure(this->manip_top().get_container(size_constant<Index>()), muntag_t<Features>()).rbegin()...);
    }
 
    template <size_t... Index, typename... Features>
    reverse_iterator make_rend(std::index_sequence<Index...>, mlist<Features...>)
    {
       return reverse_iterator(this->manip_top().get_operation(),
-                              ensure(this->manip_top().template get_container(size_constant<Index>()), muntag_t<Features>()).rend()...);
+                              ensure(this->manip_top().get_container(size_constant<Index>()), muntag_t<Features>()).rend()...);
    }
 
    template <size_t... Index, typename... Features>
    const_reverse_iterator make_rbegin(std::index_sequence<Index...>, mlist<Features...>) const
    {
       return const_reverse_iterator(this->manip_top().get_operation(),
-                                    ensure(this->manip_top().template get_container(size_constant<Index>()), muntag_t<Features>()).rbegin()...);
+                                    ensure(this->manip_top().get_container(size_constant<Index>()), muntag_t<Features>()).rbegin()...);
    }
 
    template <size_t... Index, typename... Features>
    const_reverse_iterator make_rend(std::index_sequence<Index...>, mlist<Features...>) const
    {
       return const_reverse_iterator(this->manip_top().get_operation(),
-                                    ensure(this->manip_top().template get_container(size_constant<Index>()), muntag_t<Features>()).rend()...);
+                                    ensure(this->manip_top().get_container(size_constant<Index>()), muntag_t<Features>()).rend()...);
    }
 
    template <size_t... Index>
    decltype(auto) make_back(std::index_sequence<Index...>)
    {
-      return this->manip_top().get_operation()( this->manip_top().template get_container(size_constant<Index>()).back()... );
+      return this->manip_top().get_operation()( this->manip_top().get_container(size_constant<Index>()).back()... );
    }
 
    template <size_t... Index>
    decltype(auto) make_back(std::index_sequence<Index...>) const
    {
-      return this->manip_top().get_operation()( this->manip_top().template get_container(size_constant<Index>()).back()... );
+      return this->manip_top().get_operation()( this->manip_top().get_container(size_constant<Index>()).back()... );
    }
 };
 
@@ -1285,13 +1285,13 @@ class modified_container_tuple_impl<Top, Params, std::
    template <size_t... Index>
    decltype(auto) make_random(Int i, std::index_sequence<Index...>)
    {
-      return this->manip_top().get_operation()( this->manip_top().template get_container(size_constant<Index>())[i]... );
+      return this->manip_top().get_operation()( this->manip_top().get_container(size_constant<Index>())[i]... );
    }
 
    template <size_t... Index>
    decltype(auto) make_random(Int i, std::index_sequence<Index...>) const
    {
-      return this->manip_top().get_operation()( this->manip_top().template get_container(size_constant<Index>())[i]... );
+      return this->manip_top().get_operation()( this->manip_top().get_container(size_constant<Index>())[i]... );
    }
 };
 

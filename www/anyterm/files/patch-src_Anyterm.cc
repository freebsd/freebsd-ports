After http://github.com/boostorg/range/commit/69409ed63a9e1 build fails:

../src/Anyterm.cc: In member function 'Anyterm::response_t Anyterm::process_request(const pbe::HttpRequest&)':
../src/Anyterm.cc:174:74: error: call of overloaded 'distance(std::map<SessionId, boost::shared_ptr<Session> >::const_iterator, std::map<SessionId, boost::shared_ptr<Session> >::const_iterator)' is ambiguous
         int n_sessions = distance(sessions_rd->begin(),sessions_rd->end());
                                                                          ^
In file included from /usr/local/lib/gcc6/include/c++/bits/stl_algobase.h:66:0,
                 from /usr/local/lib/gcc6/include/c++/bits/stl_tree.h:63,
                 from /usr/local/lib/gcc6/include/c++/map:60,
                 from ../src/Anyterm.hh:25,
                 from ../src/Anyterm.cc:20:
/usr/local/lib/gcc6/include/c++/bits/stl_iterator_base_funcs.h:135:5: note: candidate: typename std::iterator_traits<_Iterator>::difference_type std::distance(_InputIterator, _InputIterator) [with _InputIterator = std::_Rb_tree_const_iterator<std::pair<const SessionId, boost::shared_ptr<Session> > >; typename std::iterator_traits<_Iterator>::difference_type = int]
     distance(_InputIterator __first, _InputIterator __last)
     ^~~~~~~~
In file included from /usr/local/include/boost/range/distance.hpp:18:0,
                 from /usr/local/include/boost/range/functions.hpp:21,
                 from /usr/local/include/boost/range/iterator_range_core.hpp:38,
                 from /usr/local/include/boost/lexical_cast.hpp:30,
                 from ../libpbe/include/FileDescriptor.hh:26,
                 from ../src/Activity.hh:27,
                 from ../src/Session.hh:39,
                 from ../src/Anyterm.hh:32,
                 from ../src/Anyterm.cc:20:
/usr/local/include/boost/iterator/distance.hpp:49:9: note: candidate: typename boost::iterators::iterator_difference<Iterator>::type boost::iterators::distance_adl_barrier::distance(SinglePassIterator, SinglePassIterator) [with SinglePassIterator = std::_Rb_tree_const_iterator<std::pair<const SessionId, boost::shared_ptr<Session> > >; typename boost::iterators::iterator_difference<Iterator>::type = int]
         distance(SinglePassIterator first, SinglePassIterator last)
         ^~~~~~~~

--- src/Anyterm.cc.orig	2008-11-24 12:45:25 UTC
+++ src/Anyterm.cc
@@ -171,7 +171,7 @@ Anyterm::response_t Anyterm::process_request(const Htt
 
       {
         locked_sessions_t::reader sessions_rd(sessions);
-        int n_sessions = distance(sessions_rd->begin(),sessions_rd->end());
+        int n_sessions = std::distance(sessions_rd->begin(),sessions_rd->end());
         if (n_sessions>=max_sessions) {
           throw Error("The maximum number of concurrent sessions has been reached");
         }

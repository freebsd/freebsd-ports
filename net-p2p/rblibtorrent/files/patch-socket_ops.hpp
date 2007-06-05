--- include/libtorrent/asio/detail/socket_ops.hpp      Wed May 16 00:35:55 2007
+++ include/libtorrent/asio/detail/socket_ops.hpp.orig Wed May 16 00:35:45 2007
66c66
< #if defined(__MACH__) && defined(__APPLE__)
---
> #if defined(__MACH__) && defined(__APPLE__) || defined(__FreeBSD__)
298c298
< #elif defined(__MACH__) && defined(__APPLE__)
---
> #elif defined(__MACH__) && defined(__APPLE__) || defined(__FreeBSD__) 

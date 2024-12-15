--- external_codes/mpi_wrapper/mpi3/include/mpi3/detail/package.hpp.orig	2024-12-15 00:09:27 UTC
+++ external_codes/mpi_wrapper/mpi3/include/mpi3/detail/package.hpp
@@ -24,7 +24,7 @@ struct package : buffer {
 
  public:
 	explicit package(communicator& comm, buffer::size_type n = 0)
-	: buffer{n}, bcomm_{reinterpret_cast<basic_communicator&>(comm)} {  // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast) TODO(correaa) break cyclic dependency of classes
+	: buffer(static_cast<size_t>(n)), bcomm_{reinterpret_cast<basic_communicator&>(comm)} {  // NOLINT(cppcoreguidelines-pro-type-reinterpret-cast) TODO(correaa) break cyclic dependency of classes
 		reserve(n);
 	}
 	package(package const&) = delete;

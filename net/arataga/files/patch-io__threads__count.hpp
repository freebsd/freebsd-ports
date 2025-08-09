--- io_threads_count.hpp.orig	2022-07-13 05:09:45 UTC
+++ io_threads_count.hpp
@@ -134,7 +134,7 @@ struct fmt::formatter< arataga::io_threads_count_t > 
 	template< typename FormatContext >
 	auto format(
 		const arataga::io_threads_count_t & tc,
-		FormatContext & ctx )
+		FormatContext & ctx ) const
 	{
 		const auto str = arataga::to_string(tc);
 		return fmt::formatter< std::string >::format( str, ctx );

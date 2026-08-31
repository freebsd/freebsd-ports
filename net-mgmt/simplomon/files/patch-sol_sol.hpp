--- sol/sol.hpp.orig	2025-02-19 22:01:58 UTC
+++ sol/sol.hpp
@@ -6747,12 +6747,10 @@ namespace sol {
 		/// one.
 		///
 		/// \group emplace
-		template <class... Args>
-		T& emplace(Args&&... args) noexcept {
-			static_assert(std::is_constructible<T, Args&&...>::value, "T must be constructible with Args");
-
+		T& emplace(T& arg) noexcept {
 			*this = nullopt;
-			this->construct(std::forward<Args>(args)...);
+			m_value = &arg;
+			return **this;
 		}
 
 		/// Swaps this optional with the other.

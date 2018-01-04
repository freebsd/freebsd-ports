--- Telegram/SourceFiles/base/lambda.h.orig	2017-09-05 17:38:38 UTC
+++ Telegram/SourceFiles/base/lambda.h
@@ -212,11 +212,14 @@ protected:
 
 template <typename Lambda, typename Return, typename ...Args>
 struct vtable_once : public vtable_once_impl<Lambda, is_large<Lambda>, Return, Args...> {
-	static const vtable_once instance;
+	static const vtable_once* get_instance();
 };
 
 template <typename Lambda, typename Return, typename ...Args>
-const vtable_once<Lambda, Return, Args...> vtable_once<Lambda, Return, Args...>::instance = {};
+const vtable_once<Lambda, Return, Args...>* vtable_once<Lambda, Return, Args...>::get_instance() {
+	static vtable_once<Lambda, Return, Args...> instance;
+	return &instance;
+}
 
 template <typename Lambda, bool IsLarge, typename Return, typename ...Args> struct vtable_impl;
 
@@ -262,12 +265,14 @@ struct vtable_impl<Lambda, false, Return
 
 template <typename Lambda, typename Return, typename ...Args>
 struct vtable : public vtable_impl<Lambda, is_large<Lambda>, Return, Args...> {
-	static const vtable instance;
+	static const vtable* get_instance();
 };
 
 template <typename Lambda, typename Return, typename ...Args>
-const vtable<Lambda, Return, Args...> vtable<Lambda, Return, Args...>::instance = {};
-
+const vtable<Lambda, Return, Args...>* vtable<Lambda, Return, Args...>::get_instance() {
+	static vtable<Lambda, Return, Args...> instance;
+	return &instance;
+}
 } // namespace lambda_internal
 
 template <typename Return, typename ...Args>
@@ -346,7 +351,7 @@ public:
 	// Copy / move construct / assign from an arbitrary type.
 	template <typename Lambda, typename = std::enable_if_t<std::is_convertible<decltype(std::declval<Lambda>()(std::declval<Args>()...)),Return>::value>>
 	lambda_once(Lambda other) {
-		data_.vtable = &lambda_internal::vtable_once<Lambda, Return, Args...>::instance;
+		data_.vtable = lambda_internal::vtable_once<Lambda, Return, Args...>::get_instance();
 		lambda_internal::vtable_once<Lambda, Return, Args...>::construct_move_lambda_method(data_.storage, &other);
 	}
 	template <typename Lambda, typename = std::enable_if_t<std::is_convertible<decltype(std::declval<Lambda>()(std::declval<Args>()...)),Return>::value>>
@@ -354,7 +359,7 @@ public:
 		if (data_.vtable) {
 			data_.vtable->destruct(data_.storage);
 		}
-		data_.vtable = &lambda_internal::vtable_once<Lambda, Return, Args...>::instance;
+		data_.vtable = lambda_internal::vtable_once<Lambda, Return, Args...>::get_instance();
 		lambda_internal::vtable_once<Lambda, Return, Args...>::construct_move_lambda_method(data_.storage, &other);
 		return *this;
 	}
@@ -424,7 +429,7 @@ public:
 
 	// Copy / move construct / assign from an arbitrary type.
 	template <typename Lambda, typename = std::enable_if_t<std::is_convertible<decltype(std::declval<Lambda>()(std::declval<Args>()...)),Return>::value>>
-	lambda(Lambda other) : Parent(&lambda_internal::vtable<Lambda, Return, Args...>::instance, typename Parent::Private()) {
+	lambda(Lambda other) : Parent(lambda_internal::vtable<Lambda, Return, Args...>::get_instance(), typename Parent::Private()) {
 		lambda_internal::vtable<Lambda, Return, Args...>::construct_move_lambda_method(this->data_.storage, &other);
 	}
 	template <typename Lambda, typename = std::enable_if_t<std::is_convertible<decltype(std::declval<Lambda>()(std::declval<Args>()...)),Return>::value>>
@@ -432,7 +437,7 @@ public:
 		if (this->data_.vtable) {
 			this->data_.vtable->destruct(this->data_.storage);
 		}
-		this->data_.vtable = &lambda_internal::vtable<Lambda, Return, Args...>::instance;
+		this->data_.vtable = lambda_internal::vtable<Lambda, Return, Args...>::get_instance();
 		lambda_internal::vtable<Lambda, Return, Args...>::construct_move_lambda_method(this->data_.storage, &other);
 		return *this;
 	}
